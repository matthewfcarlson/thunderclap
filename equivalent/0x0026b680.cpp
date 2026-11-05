// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b680 @ 0x0026b680
// FUN_0026b680 @ 0x0026b680
// equiv-conv: FUN_0026ab60 eax stack stack
#include "compat/ptr.h"
extern "C" int __cdecl FUN_0026ab60(int c, int a, int limit);
// equiv-conv: FUN_0026abf0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026abf0(const char *, char *, int, int, void *);
// equiv-conv: FUN_0026ac80 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ac80(const char *, char *, void *, int, void *);
// equiv-conv: FUN_0026ad10 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ad10(const unsigned short *, char *, int, int, void *);
// equiv-conv: FUN_0026adb0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026adb0(const unsigned *, char *, int, int, void *);
// equiv-conv: FUN_0026ae50 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ae50(const char *, char *, void *, int, void *);
// equiv-conv: FUN_0026aee0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aee0(const char *, char *, void *, int, void *);

// equiv-conv: FUN_0026b680 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b680(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026ab60(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026abf0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 1: return FUN_0026ac80((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_0026ad10((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026adb0((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 4: return FUN_0026ae50((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026aee0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}
