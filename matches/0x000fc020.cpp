// Same code shape as 0x000fc000 (propagated; names are from that function)
#include "compat/ptr.h"
typedef unsigned int U_fc020;
extern void FUN_000fbc00(hulk_uintptr, U_fc020, hulk_uintptr, U_fc020*);
extern "C" void FUN_000fc020(hulk_uintptr a, U_fc020 b, hulk_uintptr c, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, c);
    FUN_000fbc00(a, b, c, (U_fc020*)args);
#else
    FUN_000fbc00(a, b, c, (&c) + 1);
#endif
}