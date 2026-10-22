class CSPManager_1dbe60 {
  public:
    char pad0[0x61e];
    short entries[0x800][20];
    char pad1[0x1e608 - 0x61e - 0x800 * 40];
    int index;
    void run();
};
void CSPManager_1dbe60::run() {
    int i = index + 1;
    if (i < 0x800) {
        short* p = &entries[i][0];
        do {
            if (*p == 0)
                goto found;
            ++i;
            p += 20;
        } while (i < 0x800);
    }
    i = 0;
    if (index < 0)
        return;
    short* p = &entries[0][0];
    do {
        if (*p == 0)
            goto found;
        ++i;
        p += 20;
    } while (i <= *(volatile int*)&index);
    return;
found:
    index = i;
}
