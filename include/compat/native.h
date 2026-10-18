// Native (clang) build compatibility header. Force-included by the native build only
// (clang: -include compat/native.h, clang-cl: /FIcompat/native.h); the MSVC 7.1 verification build never sees it.
// What MSVC 7.1 predeclares or what <new> / <typeinfo> would bring, for a tree that includes no system headers.
// See docs/native-build.md (fix 1). compat/crt.h: the one declaration of each C runtime function (fix 4).
#ifndef HULK_COMPAT_NATIVE_H
#define HULK_COMPAT_NATIVE_H

// size_t: build/tree/include/tree_prelude.h (tools/gen_tree.py) declares it for every tree TU; this one covers
// anything compiled outside the tree (data TUs, shims). Redeclaring a typedef as the same type is fine.
typedef __SIZE_TYPE__ size_t;

// type_info: the MS ABI's is a global class (sources declare their own `class type_info`); Itanium's is
// std::type_info, which `typeid` needs declared.
#if defined(_MSC_VER)
class type_info;
namespace std { using ::type_info; }
#else
namespace std { class type_info; }
#endif

#include "compat/crt.h"

#endif
