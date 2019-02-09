/*
Copyright (c) 2019 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "runtime/object.h"
using namespace lean; // NOLINT

lean::object* lean_expr_local(lean::object*, lean::object*, lean::object*, lean::object*) {
    lean_unreachable();
    return nullptr;
}

lean::object* lean_environment_empty = nullptr;

lean::object* lean_environment_contains(lean::object*, lean::object*) {
    lean_unreachable();
    return nullptr;
}

lean::object* lean_elaborator_elaborate_command(lean::object*, lean::object*, lean::object*) {
    lean_unreachable();
    return nullptr;
}