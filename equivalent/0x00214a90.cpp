// STATUS: equivalent (tools/equiv.py level 3: 18536 inputs, branch coverage 0/0)
// FUN_00214a90 @ 0x00214a90
// FUN_00214a90 @ 0x00214a90
#include "compat/ptr.h"
extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
// equiv-conv: FUN_00214900 ebx stack
extern "C" void __cdecl FUN_00214900(int, int);
extern "C" void __cdecl FUN_002149b0(void *);
void __cdecl FUN_00214a90(hulk_intptr first, hulk_intptr second, ...)
{
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, second);
    int result = ((int)(hulk_uintptr)FUN_002160c0((void *)first, (const char *)second, args));
    FUN_00214900((int)first, result);
    FUN_002149b0((void *)first);
#else
    int result = ((int)(hulk_uintptr)FUN_002160c0((void *)(hulk_uintptr)(int)first, (const char *)(hulk_uintptr)(int)second, (char *)(void *)((int *)(&second) + 1)));
    FUN_00214900(first, result);
    FUN_002149b0((void *)(hulk_uintptr)(int)first);
#endif
}
