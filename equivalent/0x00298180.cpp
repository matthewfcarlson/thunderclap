// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// FUN_00298180 @ 0x00298180
int __cdecl FUN_00298180(int value) {
    switch (value) {
    case 2: return 1;
    case 4: return 2;
    case 8: return 3;
    case 16: return 6;
    case 32: return 4;
    case 64: return 5;
    default: return 0;
    }
}
