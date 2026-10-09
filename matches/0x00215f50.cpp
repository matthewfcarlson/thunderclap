unsigned int FUN_00215f50(unsigned int param_1) {
    unsigned int iVar1 = 0;
    if (param_1 >= 8) {
        do {
            param_1 = (param_1 + 1) >> 1;
            ++iVar1;
        } while (param_1 >= 8);
    }
    return (iVar1 << 3) | param_1;
}