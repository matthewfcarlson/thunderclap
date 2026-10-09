void FUN_002eb520(int a, void* b, unsigned char c) {
    if (a && b) {
        ((unsigned char*)b)[0x2c] = c;
        *(unsigned*)((char*)b + 8) |= 0x800;
    }
}