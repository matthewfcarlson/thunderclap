// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 15/16, incomplete)
// FUN_0026b500 @ 0x0026b500
// equiv-conv: FUN_0026a210 eax stack stack
extern "C" int __cdecl FUN_0026a210(int c, int a, int limit);
// equiv-conv: FUN_0026a2a0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a2a0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a350 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a350(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a400 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a400(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a4a0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a4a0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a550 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a550(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a600 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a600(int c, int a, int p2, int p3, int p4);

// equiv-conv: FUN_0026b500 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b500(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a210(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a2a0(c, a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a350(c, a, ediArg, esiArg, edxArg);
    case 2: return FUN_0026a400(c, a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026a4a0(c, a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026a550(c, a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026a600(c, a, ediArg, esiArg, edxArg);
    }
    return -2;
}
