// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b740 @ 0x0026b740
// FUN_0026b740 @ 0x0026b740
// equiv-conv: FUN_0026af70 eax stack stack
extern "C" int __cdecl FUN_0026af70(int c, int a, int limit);
// equiv-conv: FUN_0026b000 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b000(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026b090 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b090(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026b120 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b120(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026b1c0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b1c0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026b260 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b260(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026b2f0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b2f0(int c, int a, int p2, int p3, int p4);

// equiv-conv: FUN_0026b740 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b740(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026af70(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026b000(c, a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026b090(c, a, ediArg, esiArg, edxArg);
    case 2: return FUN_0026b120(c, a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026b1c0(c, a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026b260(c, a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026b2f0(c, a, ediArg, esiArg, edxArg);
    }
    return -2;
}
