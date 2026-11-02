// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b5c0 @ 0x0026b5c0
// FUN_0026b5c0 @ 0x0026b5c0
// equiv-conv: FUN_0026a6b0 eax stack stack
#include "compat/ptr.h"
extern "C" int __cdecl FUN_0026a6b0(const char *, char *, unsigned int);
// equiv-conv: FUN_0026a750 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a750(const char *, char *, int, int, int);
// equiv-conv: FUN_0026a800 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a800(const char *, unsigned *, int, int, void *);
// equiv-conv: FUN_0026a8b0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a8b0(const unsigned short *, char *, int, int, int);
// equiv-conv: FUN_0026a960 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a960(const int *, char *, int, int, int);
// equiv-conv: FUN_0026aa00 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aa00(const char *, unsigned *, int, int, void *);
// equiv-conv: FUN_0026aab0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aab0(const char *, char *, int, int, int);

// equiv-conv: FUN_0026b5c0 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b5c0(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a6b0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (int)esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a750((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a800((const char *)(hulk_uintptr)(int)c, (unsigned *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_0026a8b0((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026a960((const int *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026aa00((const char *)(hulk_uintptr)(int)c, (unsigned *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026aab0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    }
    return -2;
}
