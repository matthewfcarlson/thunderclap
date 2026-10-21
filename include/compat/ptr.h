// Pointer-sized integer types for sources that hold a pointer in an integer (docs/native-build.md "64-bit"),
// and the x87 register float type hulk_freg (end of file).
//
// On the 32-bit build (MSVC 7.1 and clang i686) each one is exactly the type the source spelled before
// (`int`, `unsigned int`, `long`, `unsigned long`), so object code, mangled names and overloads are unchanged;
// on a 64-bit target it is the pointer-sized integer of the same signedness. MSVC 7.1 has no <stdint.h>, hence
// the names. Signedness is part of the contract: a signed `int` that held a pointer is hulk_intptr, an
// `unsigned int` hulk_uintptr; `long` keeps its own pair because the two differ in mangled names on 32-bit.
//
//   hulk_intptr / hulk_uintptr      were `int` / `unsigned int`
//   hulk_longptr / hulk_ulongptr    were `long` / `unsigned long`
//
// Not for on-disk or wire fields (those stay 32-bit) and not for the XBE-address constants (hulk_at_ / DAT_).
#ifndef HULK_COMPAT_PTR_H
#define HULK_COMPAT_PTR_H

#if defined(_WIN64) || defined(_M_X64) || defined(_M_ARM64) || defined(__LP64__) || defined(__x86_64__) || \
    defined(__aarch64__)
#if defined(__INTPTR_TYPE__)
typedef __INTPTR_TYPE__ hulk_intptr;
typedef __UINTPTR_TYPE__ hulk_uintptr;
#else
typedef __int64 hulk_intptr;
typedef unsigned __int64 hulk_uintptr;
#endif
typedef hulk_intptr hulk_longptr;
typedef hulk_uintptr hulk_ulongptr;
#else
typedef int hulk_intptr;
typedef unsigned int hulk_uintptr;
typedef long hulk_longptr;
typedef unsigned long hulk_ulongptr;
#endif

// x87 register temporaries (docs/native-float.md, native15). MSVC 7.1 keeps `float` locals and temporaries in x87
// registers, which the game runs at 53-bit precision, and rounds them to 24 bits only when it stores them to float
// memory; clang rounds every `float` local it stores (always at -O0). `hulk_freg` is the type of a local the
// original kept in a register: `float` for MSVC 7.1 (the verification build: the same object code, so byte-matched
// sources keep matching) and `double` everywhere else, which is the x87 register's value at precision control 53
// (on i686 x87 and on SSE2/NEON alike). Only where the original's listing keeps the value in a register (a value
// it spills to a float slot stays `float`), and never as a return or parameter type (those are part of the symbol
// names callers bind to). It lives here because tools/gen_tree.py includes this header once per tree TU.
#if defined(_MSC_VER) && !defined(__clang__)
typedef float hulk_freg;
#else
typedef double hulk_freg;
#endif

#endif
