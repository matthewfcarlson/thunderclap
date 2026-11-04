#include "compat/ptr.h"
extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
const char* __cdecl FUN_00216320(hulk_uintptr a, hulk_uintptr b, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, b);
    return FUN_002160c0((void *)a, (const char *)b, args);
#else
    return FUN_002160c0((void *)(hulk_uintptr)(unsigned int)a, (const char *)(hulk_uintptr)(unsigned int)b, (char *)((unsigned int *)(&b) + 1));
#endif
}
