// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 15/16, incomplete)
// FUN_0026b380 @ 0x0026b380
// equiv-conv: FUN_002699f0 eax stack stack
extern "C" int __cdecl FUN_002699f0(int c, int a, int limit);
// equiv-conv: FUN_00269a80 eax ecx stack
extern "C" int __cdecl FUN_00269a80(int c, int a, int p2);
// equiv-conv: FUN_00269b10 eax ecx stack
extern "C" int __cdecl FUN_00269b10(int c, int a, int p2);
// equiv-conv: FUN_00269ba0 eax ecx stack
extern "C" int __cdecl FUN_00269ba0(int c, int a, int p2);
// equiv-conv: FUN_00269c40 eax ecx stack
extern "C" int __cdecl FUN_00269c40(int c, int a, int p2);
// equiv-conv: FUN_00269ce0 eax ecx stack
extern "C" int __cdecl FUN_00269ce0(int c, int a, int p2);
// equiv-conv: FUN_00269d70 eax ecx stack
extern "C" int __cdecl FUN_00269d70(int c, int a, int p2);

// equiv-conv: FUN_0026b380 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b380(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_002699f0(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_00269a80(c, a, ediArg);
    case 1: return FUN_00269b10(c, a, ediArg);
    case 2: return FUN_00269ba0(c, a, ediArg);
    case 3: return FUN_00269c40(c, a, ediArg);
    case 4: return FUN_00269ce0(c, a, ediArg);
    case 5: return FUN_00269d70(c, a, ediArg);
    }
    return -2;
}
