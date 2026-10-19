// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b440 @ 0x0026b440
// FUN_0026b440 @ 0x0026b440
// equiv-conv: FUN_00269e00 eax stack stack
extern "C" int __cdecl FUN_00269e00(int c, int a, int limit);
// equiv-conv: FUN_00269e90 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269e90(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_00269f20 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269f20(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_00269fb0 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269fb0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a050 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a050(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a0f0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a0f0(int c, int a, int p2, int p3, int p4);
// equiv-conv: FUN_0026a180 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a180(int c, int a, int p2, int p3, int p4);

// equiv-conv: FUN_0026b440 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b440(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_00269e00(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_00269e90(c, a, ediArg, esiArg, edxArg);
    case 1: return FUN_00269f20(c, a, ediArg, esiArg, edxArg);
    case 2: return FUN_00269fb0(c, a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026a050(c, a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026a0f0(c, a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026a180(c, a, ediArg, esiArg, edxArg);
    }
    return -2;
}
