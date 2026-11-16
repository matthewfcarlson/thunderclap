// Fixed-width integer types (x64t16, D70) for a value whose width the game fixes where a source spells it out: the
// heap id 0x00266da0 sets and returns (a 4-byte item, DAT_00527f60), never a pointer. MSVC 7.1 has no <stdint.h>:
// its build takes them from `__int32`, which is `int` there (the same object code and mangled names as `int` /
// `unsigned int`); clang (the Wine build and the 64-bit builds) from its predefined __INT32_TYPE__ / __UINT32_TYPE__
// (`int` / `unsigned int`, the types <stdint.h> gives them, so a later <stdint.h> repeats the same typedefs).
#ifndef HULK_COMPAT_FIXEDINT_H
#define HULK_COMPAT_FIXEDINT_H

#if defined(_MSC_VER) && !defined(__clang__)
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
#else
typedef __INT32_TYPE__ int32_t;
typedef __UINT32_TYPE__ uint32_t;
#endif

#endif
