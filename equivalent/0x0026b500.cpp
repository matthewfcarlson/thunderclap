// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b500 @ 0x0026b500
// FUN_0026b500 @ 0x0026b500
// equiv-conv: FUN_0026a210 eax stack stack
#include "compat/ptr.h"
extern "C" int __cdecl FUN_0026a210(const unsigned short *, char *, unsigned int);
// equiv-conv: FUN_0026a2a0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a2a0(const char *, char *, int, int, int);
// equiv-conv: FUN_0026a350 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a350(const char *, char *, int, int, int);
// equiv-conv: FUN_0026a400 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a400(const unsigned short *, unsigned short *, int, int, void *);
// equiv-conv: FUN_0026a4a0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a4a0(const unsigned *, char *, int, int, int);
// equiv-conv: FUN_0026a550 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a550(const char *, char *, int, int, int);
// equiv-conv: FUN_0026a600 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a600(const char *, unsigned short *, int, int, void *);

// equiv-conv: FUN_0026b500 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b500(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a210((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (int)esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a2a0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a350((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 2: return FUN_0026a400((const unsigned short *)(hulk_uintptr)(int)c, (unsigned short *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026a4a0((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026a550((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026a600((const char *)(hulk_uintptr)(int)c, (unsigned short *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}
