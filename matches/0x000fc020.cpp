// Same code shape as 0x000fc000 (propagated); the wide variant: it calls the wide formatter 0x000fbe00
#include "compat/ptr.h"
typedef unsigned int U_fc020;
hulk_intptr FUN_000fbe00(unsigned short* buf, unsigned int count, const unsigned short* fmt, char* ap);
extern "C" void FUN_000fc020(hulk_uintptr a, U_fc020 b, hulk_uintptr c, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, c);
    FUN_000fbe00((unsigned short*)a, b, (const unsigned short*)c, (char*)args);
#else
    FUN_000fbe00((unsigned short*)a, b, (const unsigned short*)c, (char*)((&c) + 1));
#endif
}
