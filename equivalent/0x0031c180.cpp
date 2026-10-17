// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 6/6)
// FUN_0031c180 @ 0x0031c180
// equiv-conv: FUN_0031c180 eax
unsigned int FUN_0031c180(unsigned int value) {
    switch (value) {
    case 2: case 3: case 4: case 5:
    case 0x10: case 0x11: case 0x1d: case 0x28:
        return 0x10;
    case 6: case 7: case 0x12: case 0x1e:
        return 0x20;
    case 0xb:
        return 8;
    default:
        return 0;
    }
}