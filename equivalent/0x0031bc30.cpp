// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 7/7)
// FUN_0031bc30 @ 0x0031bc30
// FUN_0031bc30 @ 0x0031bc30
// equiv-conv: FUN_0031bc30 eax ecx
int FUN_0031bc30(int mode, int value) {
    switch (mode) {
    case 0: return value / 3;
    case 1: return value - 2;
    case 2: return value / 2;
    case 3: return value - 1;
    case 4: return value;
    default: return 0;
    }
}
