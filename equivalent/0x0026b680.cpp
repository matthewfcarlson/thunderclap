// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 15/16, incomplete)
// FUN_0026b680 @ 0x0026b680
// equiv-conv: FUN_0026ab60 eax stack stack
extern "C" int __cdecl FUN_0026ab60(int c, int a, int limit);
// equiv-conv: FUN_0026abf0 eax ecx stack
extern "C" int __cdecl FUN_0026abf0(int c, int a, int p2);
// equiv-conv: FUN_0026ac80 eax ecx stack
extern "C" int __cdecl FUN_0026ac80(int c, int a, int p2);
// equiv-conv: FUN_0026ad10 eax ecx stack
extern "C" int __cdecl FUN_0026ad10(int c, int a, int p2);
// equiv-conv: FUN_0026adb0 eax ecx stack
extern "C" int __cdecl FUN_0026adb0(int c, int a, int p2);
// equiv-conv: FUN_0026ae50 eax ecx stack
extern "C" int __cdecl FUN_0026ae50(int c, int a, int p2);
// equiv-conv: FUN_0026aee0 eax ecx stack
extern "C" int __cdecl FUN_0026aee0(int c, int a, int p2);

// equiv-conv: FUN_0026b680 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b680(int a, int fromMode, int c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026ab60(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026abf0(c, a, ediArg);
    case 1: return FUN_0026ac80(c, a, ediArg);
    case 2: return FUN_0026ad10(c, a, ediArg);
    case 3: return FUN_0026adb0(c, a, ediArg);
    case 4: return FUN_0026ae50(c, a, ediArg);
    case 5: return FUN_0026aee0(c, a, ediArg);
    }
    return -2;
}
