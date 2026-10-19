// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 15/16, incomplete)
// FUN_0026b5c0 @ 0x0026b5c0
// equiv-conv: FUN_0026a6b0 eax stack stack
extern "C" int __cdecl FUN_0026a6b0(int c, int a, int limit);
// equiv-conv: FUN_0026a750 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a750(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a800 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a800(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a8b0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a8b0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a960 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a960(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026aa00 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aa00(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026aab0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aab0(int c, int a, int p2, int p3, int p4);

// equiv-conv: FUN_0026b5c0 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b5c0(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a6b0(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a750(c, a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a800(c, a, ediArg, esiArg, edxArg);
    case 2: return FUN_0026a8b0(c, a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026a960(c, a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026aa00(c, a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026aab0(c, a, ediArg, esiArg, edxArg);
    }
    return -2;
}
