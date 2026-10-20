// Pointer-sized integer types for sources that hold a pointer in an integer (docs/native-build.md "64-bit").
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

#endif
