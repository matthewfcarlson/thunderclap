int FUN_001c62c0(char* a, char* b) {
    int r = 0;
    for (; a < b; ++a)
        r = *a - 0x30 + r * 10;
    return r;
}