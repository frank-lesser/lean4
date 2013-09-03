/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "type_checker.h"
#include "environment.h"
#include "kernel_exception.h"
#include "normalizer.h"
#include "instantiate.h"
#include "scoped_map.h"
#include "builtin.h"
#include "free_vars.h"

namespace lean {
/** \brief Auxiliary functional object used to implement infer_type. */
class type_checker::imp {
    typedef scoped_map<expr, expr, expr_hash, expr_eqp> cache;

    environment const & m_env;
    cache               m_cache;
    normalizer          m_normalizer;
    volatile bool       m_interrupted;

    expr lookup(context const & c, unsigned i) {
        auto p = lookup_ext(c, i);
        context_entry const & def = p.first;
        context const & def_c     = p.second;
        lean_assert(length(c) > length(def_c));
        return lift_free_vars(def.get_domain(), length(c) - length(def_c));
    }

    expr check_pi(expr const & e, expr const & s, context const & ctx) {
        if (is_pi(e))
            return e;
        expr r = m_normalizer(e, ctx);
        if (is_pi(r))
            return r;
        throw function_expected_exception(m_env, ctx, s);
    }

public:
    imp(environment const & env):
        m_env(env),
        m_normalizer(env) {
        m_interrupted = false;
    }

    level infer_universe(expr const & t, context const & ctx) {
        expr u = m_normalizer(infer_type(t, ctx), ctx);
        if (is_type(u))
            return ty_level(u);
        if (u == Bool)
            return level();
        throw type_expected_exception(m_env, ctx, t);
    }

    expr infer_type(expr const & e, context const & ctx) {
        check_interrupted(m_interrupted);
        bool shared = false;
        if (is_shared(e)) {
            shared = true;
            auto it = m_cache.find(e);
            if (it != m_cache.end())
                return it->second;
        }

        expr r;
        switch (e.kind()) {
        case expr_kind::Constant:
            r = m_env.get_object(const_name(e)).get_type();
            break;
        case expr_kind::Var:
            r = lookup(ctx, var_idx(e));
            break;
        case expr_kind::Type:
            r = mk_type(ty_level(e) + 1);
            break;
        case expr_kind::App: {
            unsigned num = num_args(e);
            lean_assert(num >= 2);
            buffer<expr> arg_types;
            for (unsigned i = 0; i < num; i++) {
                arg_types.push_back(infer_type(arg(e, i), ctx));
            }
            expr f_t     = check_pi(arg_types[0], e, ctx);
            unsigned i   = 1;
            while (true) {
                expr const & c   = arg(e, i);
                expr const & c_t = arg_types[i];
                if (!m_normalizer.is_convertible(abst_domain(f_t), c_t, ctx))
                    throw app_type_mismatch_exception(m_env, ctx, e, arg_types.size(), arg_types.data());
                if (closed(abst_body(f_t)))
                    f_t = abst_body(f_t);
                else if (closed(c))
                    f_t = instantiate_with_closed(abst_body(f_t), c);
                else
                    f_t = instantiate(abst_body(f_t), c);
                i++;
                if (i == num) {
                    r = f_t;
                    break;
                }
                check_pi(f_t, e, ctx);
            }
            break;
        }
        case expr_kind::Eq:
            infer_type(eq_lhs(e), ctx);
            infer_type(eq_rhs(e), ctx);
            r = mk_bool_type();
            break;
        case expr_kind::Lambda: {
            infer_universe(abst_domain(e), ctx);
            expr t;
            {
                cache::mk_scope sc(m_cache);
                t = infer_type(abst_body(e), extend(ctx, abst_name(e), abst_domain(e)));
            }
            r = mk_pi(abst_name(e), abst_domain(e), t);
            break;
        }
        case expr_kind::Pi: {
            level l1 = infer_universe(abst_domain(e), ctx);
            level l2;
            {
                cache::mk_scope sc(m_cache);
                l2 = infer_universe(abst_body(e), extend(ctx, abst_name(e), abst_domain(e)));
            }
            r = mk_type(max(l1, l2));
            break;
        }
        case expr_kind::Let: {
            expr lt = infer_type(let_value(e), ctx);
            {
                cache::mk_scope sc(m_cache);
                r = lower_free_vars(infer_type(let_body(e), extend(ctx, let_name(e), lt, let_value(e))), 1);
            }
            break;
        }
        case expr_kind::Value:
            r = to_value(e).get_type();
            break;
        }

        if (shared) {
            m_cache.insert(e, r);
        }
        return r;
    }

    bool is_convertible(expr const & t1, expr const & t2, context const & ctx) {
        return m_normalizer.is_convertible(t1, t2, ctx);
    }

    void set_interrupt(bool flag) {
        m_interrupted = flag;
        m_normalizer.set_interrupt(flag);
    }

    void clear() {
        m_cache.clear();
        m_normalizer.clear();
    }

    normalizer & get_normalizer() {
        return m_normalizer;
    }
};

type_checker::type_checker(environment const & env):m_ptr(new imp(env)) {}
type_checker::~type_checker() {}
expr type_checker::infer_type(expr const & e, context const & ctx) { return m_ptr->infer_type(e, ctx); }
level type_checker::infer_universe(expr const & e, context const & ctx) { return m_ptr->infer_universe(e, ctx); }
void type_checker::clear() { m_ptr->clear(); }
void type_checker::set_interrupt(bool flag) { m_ptr->set_interrupt(flag); }
bool type_checker::is_convertible(expr const & t1, expr const & t2, context const & ctx) { return m_ptr->is_convertible(t1, t2, ctx); }
normalizer & type_checker::get_normalizer() { return m_ptr->get_normalizer(); }

expr  infer_type(expr const & e, environment const & env, context const & ctx) {
    return type_checker(env).infer_type(e, ctx);
}

level infer_universe(expr const & t, environment const & env, context const & ctx) {
    return type_checker(env).infer_universe(t, ctx);
}
}
