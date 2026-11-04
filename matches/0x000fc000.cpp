#include "compat/ptr.h"
typedef unsigned int U_fc000;
extern void FUN_000fbc00(hulk_uintptr, U_fc000, hulk_uintptr, U_fc000*);
extern "C" void FUN_000fc000(hulk_uintptr a, U_fc000 b, hulk_uintptr c, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, c);
    FUN_000fbc00(a, b, c, (U_fc000*)args);
#else
    FUN_000fbc00(a, b, c, (&c) + 1);
#endif
}