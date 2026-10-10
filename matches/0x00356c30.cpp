unsigned int __cdecl FUN_00356c30(unsigned int value) {
    unsigned int result;
    unsigned char table[16];
    unsigned int index = value;
    unsigned int zero = 0;

    if (index & 0xFFFF0000) {
        index >>= 16;
        result = 0x10;
    } else {
        result = 0;
    }

    if (index & 0xFF00) {
        index >>= 8;
        result |= 8;
    }

    if (index & 0xF0) {
        index >>= 4;
        result |= 4;
    }

    table[0] = zero;
    table[1] = zero;
    table[2] = 1;
    table[3] = 1;
    table[4] = 2;
    table[5] = 2;
    table[6] = 2;
    table[7] = 2;
    table[8] = 3;
    table[9] = 3;
    table[10] = 3;
    table[11] = 3;
    table[12] = 3;
    table[13] = 3;
    table[14] = 3;
    table[15] = 3;

    return (int)(signed char)table[index] | result;
}