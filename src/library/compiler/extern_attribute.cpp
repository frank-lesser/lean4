/*
Copyright (c) 2019 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Leonardo de Moura
*/
#include "runtime/sstream.h"
#include "util/object_ref.h"
#include "kernel/instantiate.h"
#include "kernel/type_checker.h"
#include "library/util.h"
#include "library/attribute_manager.h"
#include "library/compiler/borrowed_annotation.h"
#include "library/compiler/util.h"
#include "library/compiler/builtin.h" // TODO(Leo): delete

void initialize_init_lean_extern();

namespace lean {
object* mk_adhoc_ext_entry_core(object*);
object* mk_inline_ext_entry_core(object*, object*);
object* mk_std_ext_entry_core(object*, object*);
object* mk_foreign_ext_entry_core(object*, object*);
object* mk_extern_call_core(object*, object*, object*);
object* mk_extern_attr_data_core(object*, object*);
object* mk_extern_call_core(object*, object*, object*);

typedef object_ref extern_entry;
typedef list_ref<extern_entry> extern_entries;
typedef object_ref extern_attr_data_value;

extern_entry mk_adhoc_ext_entry(name const & backend) {
    inc(backend.raw());
    return extern_entry(mk_adhoc_ext_entry_core(backend.raw()));
}
extern_entry mk_inline_ext_entry(name const & backend, char const * pattern) {
    inc(backend.raw());
    return extern_entry(mk_inline_ext_entry_core(backend.raw(), mk_string(pattern)));
}
extern_entry mk_std_ext_entry(name const & backend, char const * fn) {
    inc(backend.raw());
    return extern_entry(mk_std_ext_entry_core(backend.raw(), mk_string(fn)));
}
extern_entry mk_foreign_ext_entry(name const & backend, char const * fn) {
    inc(backend.raw());
    return extern_entry(mk_foreign_ext_entry_core(backend.raw(), mk_string(fn)));
}
extern_attr_data_value mk_extern_attr_data_value(optional<unsigned> const & arity, buffer<extern_entry> const & es) {
    object * _arity;
    if (arity) {
        _arity = alloc_cnstr(1, 1, 0); cnstr_set(_arity, 0, mk_nat_obj(*arity));
    } else {
        _arity = box(0);
    }
    return extern_attr_data_value(mk_extern_attr_data_core(_arity, extern_entries(es).steal()));
}

struct extern_attr_data : public attr_data {
    extern_attr_data_value m_value;
    extern_attr_data(extern_attr_data_value const & ref): m_value(ref) {}
    extern_attr_data() {}

    virtual unsigned hash() const override { return 0; }
    void write(serializer & s) const { s.write_object(m_value.raw()); }
    void read(deserializer & d) { m_value = extern_attr_data_value(d.read_object(), true); }

    /*
      Examples:

      - `@[extern]`
      - `@[extern "level_hash"]`
      - `@[extern cpp "lean::string_size" llvm "lean_str_size"]`
      - `@[extern cpp inline "#1 + #2"]`
      - `@[extern cpp "foo" llvm adhoc]`
      - `@[extern 2 cpp "io_prim_println"]
    */
    virtual void parse(abstract_parser & p) override {
        buffer<extern_entry> entries;
        optional<unsigned> arity;
        if (p.curr_is_token("]") || p.curr_is_token(",")) {
            // - `@[extern]`
            entries.push_back(mk_adhoc_ext_entry("all"));
            m_value = mk_extern_attr_data_value(arity, entries);
            return;
        }
        if (p.curr_is_numeral()) {
            arity = p.parse_small_nat();
        }
        if (p.curr_is_string()) {
            // - `@[extern "level_hash"]`
            // - `@[extern 2 "level_hash"]`
            std::string lit = p.parse_string_lit();
            entries.push_back(mk_std_ext_entry("all", lit.c_str()));
            m_value = mk_extern_attr_data_value(arity, entries);
            return;
        }
        while (p.curr_is_name()) {
            name backend = p.parse_name();
            if (p.curr_is_token_or_id("inline")) {
                p.next();
                std::string fn = p.parse_string_lit();
                entries.push_back(mk_inline_ext_entry(backend, fn.c_str()));
            } else if (p.curr_is_token("adhoc")) {
                p.next();
                entries.push_back(mk_adhoc_ext_entry(backend));
            } else {
                std::string fn = p.parse_string_lit();
                entries.push_back(mk_std_ext_entry(backend, fn.c_str()));
            }
        }
        m_value = mk_extern_attr_data_value(arity, entries);
    }
    virtual void print(std::ostream & out) override {
        out << "<>";
    }
};

typedef typed_attribute<extern_attr_data> extern_attr;

extern_attr const & get_extern_attr() {
    return static_cast<extern_attr const &>(get_system_attribute("extern"));
}

bool emit_extern_call_core(std::ostream & out, environment const & env, name const & backend, name const & fn, string_refs const & attrs) {
    if (std::shared_ptr<extern_attr_data> const & data = get_extern_attr().get(env, fn)) {
        extern_attr_data_value const & v = data->m_value;
        inc(v.raw()); inc(backend.raw()); inc(attrs.raw());
        object * r = mk_extern_call_core(v.raw(), backend.raw(), attrs.raw());
        if (is_scalar(r)) return false;
        object * s = cnstr_get(r, 0);
        out << string_cstr(s);
        dec(r);
        return true;
    } else {
        return false;
    }
}

void emit_extern_call(std::ostream & out, environment const & env, name const & backend, name const & fn, string_refs const & attrs) {
    if (emit_extern_call_core(out, env, backend, fn, attrs))
        return;
    { // TODO(Leo): delete this blcok
        name _fn = *get_native_constant_cname(env, fn);
        out << _fn << "(";
        bool first = true;
        string_refs it = attrs;
        while (!empty(it)) {
            if (first) first = false; else out << ", ";
            out << string_cstr(head(it).raw());
            it = tail(it);
        }
        out << ")";
    }
}

static inline bool is_extern_constant_core(environment const & env, name const & c) {
    return static_cast<bool>(get_extern_attr().get(env, c));
}

bool is_extern_constant(environment const & env, name const & c) {
    if (is_extern_constant_core(env, c))
        return true;
    { // TODO(Leo): delete this block
        return is_native_constant(env, c);
    }
    return false;
}

static optional<unsigned> get_given_arity(environment const & env, name const & c) {
    lean_assert(is_extern_constant_core(env, c));
    extern_attr_data_value v = get_extern_attr().get(env, c)->m_value;
    object * arity = cnstr_get(v.raw(), 0);
    if (is_scalar(arity)) return optional<unsigned>();
    else if (is_mpz(arity)) return optional<unsigned>(); // ignore big nums
    else return optional<unsigned>(unbox(arity));
}

optional<unsigned> get_extern_constant_arity(environment const & env, name const & c) {
    if (is_extern_constant_core(env, c)) {
        if (optional<unsigned> given_arity = get_given_arity(env, c))
            return given_arity;
        /* Infer arity from type */
        return optional<unsigned>(get_arity(env.get(c).get_type()));
    }
    // TODO(Leo): replace with return optional<unsigned>
    return get_native_constant_arity(env, c);
}

bool get_extern_borrowed_info(environment const & env, name const & c, buffer<bool> & borrowed_args, bool & borrowed_res) {
    if (is_extern_constant_core(env, c)) {
        /* Extract borrowed info from type */
        expr type = env.get(c).get_type();
        unsigned arity = 0;
        while (is_pi(type)) {
            arity++;
            expr d = binding_domain(type);
            borrowed_args.push_back(is_borrowed(d));
            type = binding_body(type);
        }
        borrowed_res = false;
        if (optional<unsigned> given_arity = get_given_arity(env, c)) {
            if (*given_arity < arity) {
                borrowed_args.shrink(*given_arity);
                return true;
            } else if (*given_arity > arity) {
                borrowed_args.resize(*given_arity, false);
                return true;
            }
        }
        borrowed_res = is_borrowed(type);
        return true;
    }
    // TODO(Leo): replace with return false
    return get_native_borrowed_info(env, c, borrowed_args, borrowed_res);
}

optional<expr> get_extern_constant_ll_type(environment const & env, name const & c) {
    if (is_extern_constant_core(env, c)) {
        unsigned arity = 0;
        expr type = env.get(c).get_type();
        type_checker::state st(env);
        local_ctx lctx;
        name_generator ngen;
        buffer<expr> arg_ll_types;
        buffer<expr> locals;
        while (is_pi(type)) {
            arity++;
            expr arg_type = instantiate_rev(binding_domain(type), locals.size(), locals.data());
            expr arg_ll_type = mk_runtime_type(st, lctx, arg_type);
            arg_ll_types.push_back(arg_ll_type);
            expr local = lctx.mk_local_decl(ngen, binding_name(type), arg_type);
            locals.push_back(local);
            type = binding_body(type);
        }
        type = instantiate_rev(type, locals.size(), locals.data());
        expr ll_type;
        if (optional<unsigned> given_arity = get_given_arity(env, c)) {
            if (arity < *given_arity) {
                /* Fill with `_obj` */
                arg_ll_types.resize(*given_arity, mk_enf_object_type());
                ll_type = mk_enf_object_type();
            } else if (arity > *given_arity) {
                arg_ll_types.shrink(*given_arity);
                ll_type = mk_enf_object_type(); /* Result is a closure */
            } else {
                ll_type = mk_runtime_type(st, lctx, type);
            }
        } else {
            ll_type = mk_runtime_type(st, lctx, type);
        }
        unsigned i = arg_ll_types.size();
        while (i > 0) {
            --i;
            ll_type = mk_arrow(arg_ll_types[i], ll_type);
        }
        return some_expr(ll_type);
    }
    // TODO(Leo): replace with return none_expr()
    return get_native_constant_ll_type(env, c);
}

void initialize_extern_attribute() {
    initialize_init_lean_extern(); // Lean module initialization
    register_system_attribute(extern_attr("extern", "builtin and foreign functions",
                                          [](environment const & env, io_state const &, name const &, unsigned, bool persistent) {
                                              if (!persistent) throw exception("invalid [extern] attribute, it must be persistent");
                                              return env;
                                          }));
}

void finalize_extern_attribute() {
}
}
