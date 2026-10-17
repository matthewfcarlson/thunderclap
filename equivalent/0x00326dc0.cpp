// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// FUN_00326dc0 @ 0x00326dc0
// equiv-conv: FUN_00326dc0 eax ecx
int FUN_00326dc0(unsigned int mode, int value)
{
    switch (mode) {
    case 0: return value / 3;
    case 1: return value - 2;
    case 2: return value / 2;
    case 3: return value - 1;
    case 4: return value;
    default: return 0;
    }
}