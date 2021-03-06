/*
Copyright (c) 2018 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
// DO NOT EDIT, this is an automatically generated file
// Generated using script: ../../gen/apply.lean
#include "runtime/apply.h"
namespace lean {
#define obj object
#define fx(i) closure_arg_cptr(f)[i]

static obj* fix_args(obj* f, unsigned n, obj*const* as) {
    unsigned arity = closure_arity(f);
    unsigned fixed = closure_num_fixed(f);
    unsigned new_fixed = fixed + n;
    lean_assert(new_fixed < arity);
    obj * r = alloc_closure(closure_fun(f), arity, new_fixed);
    obj ** source = closure_arg_cptr(f);
    obj ** target = closure_arg_cptr(r);
    if (!is_exclusive(f)) {
      for (unsigned i = 0; i < fixed; i++, source++, target++) {
          *target = *source;
          inc(*target);
      }
      dec_ref(f);
    } else {
      for (unsigned i = 0; i < fixed; i++, source++, target++) {
          *target = *source;
      }
      free_closure_obj(f);
    }
    for (unsigned i = 0; i < n; i++, as++, target++) {
        *target = *as;
    }
    return r;
}

static inline obj* fix_args(obj* f, std::initializer_list<obj*> const & l) {
    return fix_args(f, l.size(), l.begin());
}
typedef obj* (*fn1)(obj*); // NOLINT
#define FN1(f) reinterpret_cast<fn1>(closure_fun(f))
typedef obj* (*fn2)(obj*, obj*); // NOLINT
#define FN2(f) reinterpret_cast<fn2>(closure_fun(f))
typedef obj* (*fn3)(obj*, obj*, obj*); // NOLINT
#define FN3(f) reinterpret_cast<fn3>(closure_fun(f))
typedef obj* (*fn4)(obj*, obj*, obj*, obj*); // NOLINT
#define FN4(f) reinterpret_cast<fn4>(closure_fun(f))
typedef obj* (*fn5)(obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN5(f) reinterpret_cast<fn5>(closure_fun(f))
typedef obj* (*fn6)(obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN6(f) reinterpret_cast<fn6>(closure_fun(f))
typedef obj* (*fn7)(obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN7(f) reinterpret_cast<fn7>(closure_fun(f))
typedef obj* (*fn8)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN8(f) reinterpret_cast<fn8>(closure_fun(f))
typedef obj* (*fn9)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN9(f) reinterpret_cast<fn9>(closure_fun(f))
typedef obj* (*fn10)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN10(f) reinterpret_cast<fn10>(closure_fun(f))
typedef obj* (*fn11)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN11(f) reinterpret_cast<fn11>(closure_fun(f))
typedef obj* (*fn12)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN12(f) reinterpret_cast<fn12>(closure_fun(f))
typedef obj* (*fn13)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN13(f) reinterpret_cast<fn13>(closure_fun(f))
typedef obj* (*fn14)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN14(f) reinterpret_cast<fn14>(closure_fun(f))
typedef obj* (*fn15)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN15(f) reinterpret_cast<fn15>(closure_fun(f))
typedef obj* (*fn16)(obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*); // NOLINT
#define FN16(f) reinterpret_cast<fn16>(closure_fun(f))
typedef obj* (*fnn)(obj**); // NOLINT
#define FNN(f) reinterpret_cast<fnn>(closure_fun(f))
static obj* curry(obj* f, unsigned n, obj** as) {
switch (n) {
case 0: lean_unreachable();
case 1: return FN1(f)(as[0]);
case 2: return FN2(f)(as[0], as[1]);
case 3: return FN3(f)(as[0], as[1], as[2]);
case 4: return FN4(f)(as[0], as[1], as[2], as[3]);
case 5: return FN5(f)(as[0], as[1], as[2], as[3], as[4]);
case 6: return FN6(f)(as[0], as[1], as[2], as[3], as[4], as[5]);
case 7: return FN7(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6]);
case 8: return FN8(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7]);
case 9: return FN9(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8]);
case 10: return FN10(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9]);
case 11: return FN11(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10]);
case 12: return FN12(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11]);
case 13: return FN13(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12]);
case 14: return FN14(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13]);
case 15: return FN15(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13], as[14]);
case 16: return FN16(f)(as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13], as[14], as[15]);
default: return FNN(f)(as);
}
}
obj* apply_n(obj*, unsigned, obj**);
obj* apply_1(obj* f, obj* a1) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 1) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 1: { obj* r = FN1(f)(a1); free_closure_obj(f); return r; }
    case 2: { obj* r = FN2(f)(fx(0), a1); free_closure_obj(f); return r; }
    case 3: { obj* r = FN3(f)(fx(0), fx(1), a1); free_closure_obj(f); return r; }
    case 4: { obj* r = FN4(f)(fx(0), fx(1), fx(2), a1); free_closure_obj(f); return r; }
    case 5: { obj* r = FN5(f)(fx(0), fx(1), fx(2), fx(3), a1); free_closure_obj(f); return r; }
    case 6: { obj* r = FN6(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), a1); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), fx(14), a1); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 1: { obj* r = FN1(f)(a1); dec_ref(f); return r; }
  case 2: { inc(fx(0)); obj* r = FN2(f)(fx(0), a1); dec_ref(f); return r; }
  case 3: { inc(fx(0)); inc(fx(1)); obj* r = FN3(f)(fx(0), fx(1), a1); dec_ref(f); return r; }
  case 4: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN4(f)(fx(0), fx(1), fx(2), a1); dec_ref(f); return r; }
  case 5: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN5(f)(fx(0), fx(1), fx(2), fx(3), a1); dec_ref(f); return r; }
  case 6: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN6(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1); dec_ref(f); return r; }
  case 7: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); inc(fx(13)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), a1); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); inc(fx(13)); inc(fx(14)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), fx(14), a1); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[1] = { a1 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 1; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 1) {
  lean_assert(fixed < arity);
  lean_unreachable();
} else {
  return fix_args(f, {a1});
}
}
obj* apply_2(obj* f, obj* a1, obj* a2) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 2) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 2: { obj* r = FN2(f)(a1, a2); free_closure_obj(f); return r; }
    case 3: { obj* r = FN3(f)(fx(0), a1, a2); free_closure_obj(f); return r; }
    case 4: { obj* r = FN4(f)(fx(0), fx(1), a1, a2); free_closure_obj(f); return r; }
    case 5: { obj* r = FN5(f)(fx(0), fx(1), fx(2), a1, a2); free_closure_obj(f); return r; }
    case 6: { obj* r = FN6(f)(fx(0), fx(1), fx(2), fx(3), a1, a2); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1, a2); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), a1, a2); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 2: { obj* r = FN2(f)(a1, a2); dec_ref(f); return r; }
  case 3: { inc(fx(0)); obj* r = FN3(f)(fx(0), a1, a2); dec_ref(f); return r; }
  case 4: { inc(fx(0)); inc(fx(1)); obj* r = FN4(f)(fx(0), fx(1), a1, a2); dec_ref(f); return r; }
  case 5: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN5(f)(fx(0), fx(1), fx(2), a1, a2); dec_ref(f); return r; }
  case 6: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN6(f)(fx(0), fx(1), fx(2), fx(3), a1, a2); dec_ref(f); return r; }
  case 7: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1, a2); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); inc(fx(13)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), fx(13), a1, a2); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[2] = { a1, a2 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 2; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 2) {
  obj * as[2] = { a1, a2 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 2+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2});
}
}
obj* apply_3(obj* f, obj* a1, obj* a2, obj* a3) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 3) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 3: { obj* r = FN3(f)(a1, a2, a3); free_closure_obj(f); return r; }
    case 4: { obj* r = FN4(f)(fx(0), a1, a2, a3); free_closure_obj(f); return r; }
    case 5: { obj* r = FN5(f)(fx(0), fx(1), a1, a2, a3); free_closure_obj(f); return r; }
    case 6: { obj* r = FN6(f)(fx(0), fx(1), fx(2), a1, a2, a3); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2, a3); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1, a2, a3); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 3: { obj* r = FN3(f)(a1, a2, a3); dec_ref(f); return r; }
  case 4: { inc(fx(0)); obj* r = FN4(f)(fx(0), a1, a2, a3); dec_ref(f); return r; }
  case 5: { inc(fx(0)); inc(fx(1)); obj* r = FN5(f)(fx(0), fx(1), a1, a2, a3); dec_ref(f); return r; }
  case 6: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN6(f)(fx(0), fx(1), fx(2), a1, a2, a3); dec_ref(f); return r; }
  case 7: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN7(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2, a3); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); inc(fx(12)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), fx(12), a1, a2, a3); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[3] = { a1, a2, a3 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 3; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 3) {
  obj * as[3] = { a1, a2, a3 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 3+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3});
}
}
obj* apply_4(obj* f, obj* a1, obj* a2, obj* a3, obj* a4) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 4) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 4: { obj* r = FN4(f)(a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 5: { obj* r = FN5(f)(fx(0), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 6: { obj* r = FN6(f)(fx(0), fx(1), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3, a4); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2, a3, a4); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 4: { obj* r = FN4(f)(a1, a2, a3, a4); dec_ref(f); return r; }
  case 5: { inc(fx(0)); obj* r = FN5(f)(fx(0), a1, a2, a3, a4); dec_ref(f); return r; }
  case 6: { inc(fx(0)); inc(fx(1)); obj* r = FN6(f)(fx(0), fx(1), a1, a2, a3, a4); dec_ref(f); return r; }
  case 7: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN7(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN8(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3, a4); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); inc(fx(11)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), fx(11), a1, a2, a3, a4); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[4] = { a1, a2, a3, a4 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 4; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 4) {
  obj * as[4] = { a1, a2, a3, a4 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 4+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4});
}
}
obj* apply_5(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 5) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 5: { obj* r = FN5(f)(a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 6: { obj* r = FN6(f)(fx(0), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), fx(1), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3, a4, a5); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 5: { obj* r = FN5(f)(a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 6: { inc(fx(0)); obj* r = FN6(f)(fx(0), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 7: { inc(fx(0)); inc(fx(1)); obj* r = FN7(f)(fx(0), fx(1), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN8(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN9(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); inc(fx(10)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), fx(10), a1, a2, a3, a4, a5); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[5] = { a1, a2, a3, a4, a5 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 5; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 5) {
  obj * as[5] = { a1, a2, a3, a4, a5 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 5+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5});
}
}
obj* apply_6(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 6) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 6: { obj* r = FN6(f)(a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 7: { obj* r = FN7(f)(fx(0), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4, a5, a6); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 6: { obj* r = FN6(f)(a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 7: { inc(fx(0)); obj* r = FN7(f)(fx(0), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 8: { inc(fx(0)); inc(fx(1)); obj* r = FN8(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN9(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN10(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); inc(fx(9)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), fx(9), a1, a2, a3, a4, a5, a6); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[6] = { a1, a2, a3, a4, a5, a6 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 6; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 6) {
  obj * as[6] = { a1, a2, a3, a4, a5, a6 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 6+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6});
}
}
obj* apply_7(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 7) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 7: { obj* r = FN7(f)(a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 8: { obj* r = FN8(f)(fx(0), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5, a6, a7); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 7: { obj* r = FN7(f)(a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 8: { inc(fx(0)); obj* r = FN8(f)(fx(0), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 9: { inc(fx(0)); inc(fx(1)); obj* r = FN9(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN10(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN11(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); inc(fx(8)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), fx(8), a1, a2, a3, a4, a5, a6, a7); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[7] = { a1, a2, a3, a4, a5, a6, a7 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 7; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 7) {
  obj * as[7] = { a1, a2, a3, a4, a5, a6, a7 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 7+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7});
}
}
obj* apply_8(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 8) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 8: { obj* r = FN8(f)(a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 9: { obj* r = FN9(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6, a7, a8); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 8: { obj* r = FN8(f)(a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 9: { inc(fx(0)); obj* r = FN9(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 10: { inc(fx(0)); inc(fx(1)); obj* r = FN10(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN11(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN12(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); inc(fx(7)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), fx(7), a1, a2, a3, a4, a5, a6, a7, a8); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[8] = { a1, a2, a3, a4, a5, a6, a7, a8 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 8; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 8) {
  obj * as[8] = { a1, a2, a3, a4, a5, a6, a7, a8 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 8+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8});
}
}
obj* apply_9(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 9) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 9: { obj* r = FN9(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 10: { obj* r = FN10(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7, a8, a9); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 9: { obj* r = FN9(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 10: { inc(fx(0)); obj* r = FN10(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 11: { inc(fx(0)); inc(fx(1)); obj* r = FN11(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN12(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN13(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); inc(fx(6)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), fx(6), a1, a2, a3, a4, a5, a6, a7, a8, a9); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[9] = { a1, a2, a3, a4, a5, a6, a7, a8, a9 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 9; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 9) {
  obj * as[9] = { a1, a2, a3, a4, a5, a6, a7, a8, a9 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 9+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9});
}
}
obj* apply_10(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 10) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 10: { obj* r = FN10(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 11: { obj* r = FN11(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 10: { obj* r = FN10(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 11: { inc(fx(0)); obj* r = FN11(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 12: { inc(fx(0)); inc(fx(1)); obj* r = FN12(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN13(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN14(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); inc(fx(5)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), fx(5), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[10] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 10; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 10) {
  obj * as[10] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 10+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
}
}
obj* apply_11(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 11) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 11: { obj* r = FN11(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    case 12: { obj* r = FN12(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 11: { obj* r = FN11(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  case 12: { inc(fx(0)); obj* r = FN12(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  case 13: { inc(fx(0)); inc(fx(1)); obj* r = FN13(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN14(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN15(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); inc(fx(4)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), fx(4), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[11] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 11; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 11) {
  obj * as[11] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 11+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11});
}
}
obj* apply_12(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11, obj* a12) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 12) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 12: { obj* r = FN12(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); free_closure_obj(f); return r; }
    case 13: { obj* r = FN13(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 12: { obj* r = FN12(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); dec_ref(f); return r; }
  case 13: { inc(fx(0)); obj* r = FN13(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); dec_ref(f); return r; }
  case 14: { inc(fx(0)); inc(fx(1)); obj* r = FN14(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN15(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); inc(fx(3)); obj* r = FN16(f)(fx(0), fx(1), fx(2), fx(3), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[12] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 12; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 12) {
  obj * as[12] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 12+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12});
}
}
obj* apply_13(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11, obj* a12, obj* a13) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 13) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 13: { obj* r = FN13(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); free_closure_obj(f); return r; }
    case 14: { obj* r = FN14(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 13: { obj* r = FN13(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); dec_ref(f); return r; }
  case 14: { inc(fx(0)); obj* r = FN14(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); dec_ref(f); return r; }
  case 15: { inc(fx(0)); inc(fx(1)); obj* r = FN15(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); inc(fx(2)); obj* r = FN16(f)(fx(0), fx(1), fx(2), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[13] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 13; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 13) {
  obj * as[13] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 13+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13});
}
}
obj* apply_14(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11, obj* a12, obj* a13, obj* a14) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 14) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 14: { obj* r = FN14(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); free_closure_obj(f); return r; }
    case 15: { obj* r = FN15(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 14: { obj* r = FN14(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); dec_ref(f); return r; }
  case 15: { inc(fx(0)); obj* r = FN15(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); dec_ref(f); return r; }
  case 16: { inc(fx(0)); inc(fx(1)); obj* r = FN16(f)(fx(0), fx(1), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[14] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 14; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 14) {
  obj * as[14] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 14+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14});
}
}
obj* apply_15(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11, obj* a12, obj* a13, obj* a14, obj* a15) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 15) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 15: { obj* r = FN15(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); free_closure_obj(f); return r; }
    case 16: { obj* r = FN16(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 15: { obj* r = FN15(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); dec_ref(f); return r; }
  case 16: { inc(fx(0)); obj* r = FN16(f)(fx(0), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[15] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 15; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 15) {
  obj * as[15] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 15+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15});
}
}
obj* apply_16(obj* f, obj* a1, obj* a2, obj* a3, obj* a4, obj* a5, obj* a6, obj* a7, obj* a8, obj* a9, obj* a10, obj* a11, obj* a12, obj* a13, obj* a14, obj* a15, obj* a16) {
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + 16) {
  if (is_exclusive(f)) {
    switch (arity) {
    case 16: { obj* r = FN16(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); free_closure_obj(f); return r; }
    }
  }
  switch (arity) {
  case 16: { obj* r = FN16(f)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); dec_ref(f); return r; }
  default:
    lean_assert(arity > 16);
    obj * as[16] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 };
    obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
    for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
    for (unsigned i = 0; i < 16; i++) args[fixed+i] = as[i];
    obj * r = FNN(f)(args);
    dec_ref(f);
    return r;
  }
} else if (arity < fixed + 16) {
  obj * as[16] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 };
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = curry(f, arity, args);
  dec_ref(f);
  return apply_n(new_f, 16+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16});
}
}
obj* apply_m(obj* f, unsigned n, obj** as) {
lean_assert(n > 16);
unsigned arity = closure_arity(f);
unsigned fixed = closure_num_fixed(f);
if (arity == fixed + n) {
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < n; i++) args[fixed+i] = as[i];
  obj * r = FNN(f)(args);
  dec_ref(f);
  return r;
} else if (arity < fixed + n) {
  obj ** args = static_cast<obj**>(LEAN_ALLOCA(arity*sizeof(obj*))); // NOLINT
  for (unsigned i = 0; i < fixed; i++) { inc(fx(i)); args[i] = fx(i); }
  for (unsigned i = 0; i < arity-fixed; i++) args[fixed+i] = as[i];
  obj * new_f = FNN(f)(args);
  dec_ref(f);
  return apply_n(new_f, n+fixed-arity, as+arity-fixed);
} else {
  return fix_args(f, n, as);
}
}
obj* apply_n(obj* f, unsigned n, obj** as) {
switch (n) {
case 0: lean_unreachable();
case 1: return apply_1(f, as[0]);
case 2: return apply_2(f, as[0], as[1]);
case 3: return apply_3(f, as[0], as[1], as[2]);
case 4: return apply_4(f, as[0], as[1], as[2], as[3]);
case 5: return apply_5(f, as[0], as[1], as[2], as[3], as[4]);
case 6: return apply_6(f, as[0], as[1], as[2], as[3], as[4], as[5]);
case 7: return apply_7(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6]);
case 8: return apply_8(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7]);
case 9: return apply_9(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8]);
case 10: return apply_10(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9]);
case 11: return apply_11(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10]);
case 12: return apply_12(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11]);
case 13: return apply_13(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12]);
case 14: return apply_14(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13]);
case 15: return apply_15(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13], as[14]);
case 16: return apply_16(f, as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], as[8], as[9], as[10], as[11], as[12], as[13], as[14], as[15]);
default: return apply_m(f, n, as);
}
}
}
