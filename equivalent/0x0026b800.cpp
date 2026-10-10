// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/18)
// FUN_0026b800 @ 0x0026b800
// equiv-conv: FUN_0026b380 stack stack stack ebx edx esi edi
extern int FUN_0026b380(void* a, int mode, void* c, int toMode, int g, int f, int e);
// equiv-conv: FUN_0026b440 stack stack stack ebx edx esi edi
extern int FUN_0026b440(void* a, int mode, void* c, int toMode, int g, int f, int e);
// equiv-conv: FUN_0026b500 stack stack stack ebx edx esi edi
extern int FUN_0026b500(void* a, int mode, void* c, int toMode, int g, int f, int e);
// equiv-conv: FUN_0026b5c0 stack stack stack ebx edx esi edi
extern int FUN_0026b5c0(void* a, int mode, void* c, int toMode, int g, int f, int e);
// equiv-conv: FUN_0026b680 stack stack stack ebx edx esi edi
extern int FUN_0026b680(void* a, int mode, void* c, int toMode, int g, int f, int e);
// equiv-conv: FUN_0026b740 stack stack stack ebx edx esi edi
extern int FUN_0026b740(void* a, int mode, void* c, int toMode, int g, int f, int e);

int FUN_0026b800(void* a, int fromMode, void* c, int toMode, int e, int f, int g) {
    if (a == 0)
        return -3;
    if (c == 0)
        return -2;
    if (fromMode == toMode && a == c && g == 0)
        return 0;
    switch (fromMode) {
    case 0:
        return FUN_0026b380(a, 0, c, toMode, g, f, e);
    case 1:
        return FUN_0026b440(a, 1, c, toMode, g, f, e);
    case 2:
        return FUN_0026b500(a, 2, c, toMode, g, f, e);
    case 3:
        return FUN_0026b5c0(a, 3, c, toMode, g, f, e);
    case 4:
        return FUN_0026b680(a, 4, c, toMode, g, f, e);
    case 5:
        return FUN_0026b740(a, 5, c, toMode, g, f, e);
    }
    return -3;
}
