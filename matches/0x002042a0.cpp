struct Obj {
    char pad[0x58c];
    short* entries;
    int pad2;
    int count;
    int FUN_002042a0(int, int);
};
int Obj::FUN_002042a0(int param_2, int param_3) {
    int n = count;
    int found = 0;
    int i = 0;
    if (n > 0) {
        short* base = entries;
        short* p = base;
        do {
            if (*p == param_3) {
                if (found == param_2)
                    return base[i * 0x2b + 1];
                ++found;
            }
            ++i;
            p += 0x2b;
        } while (i < n);
    }
    return -1;
}