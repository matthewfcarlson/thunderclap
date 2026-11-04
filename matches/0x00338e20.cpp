#include "compat/ptr.h"
typedef unsigned int U_338e20;
extern void __cdecl F1(hulk_uintptr, int);
extern void __cdecl F2(hulk_uintptr, hulk_uintptr, U_338e20*);
extern void __cdecl F3(hulk_uintptr, int);
extern int __cdecl F4(hulk_uintptr);
int __cdecl target(hulk_uintptr a, hulk_uintptr b, ...) {
    F1(a, 1);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, b);
    F2(a, b, (U_338e20*)args);
#else
    F2(a, b, (U_338e20*)&b + 1);
#endif
    F3(a, 2);
    return F4(a);
}
