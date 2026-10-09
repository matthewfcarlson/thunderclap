int __fastcall count(unsigned int ignored, unsigned int value) {
    int n = 0;
    for (int i = 0; i < 32; ++i) {
        if (value & (1 << i)) ++n;
    }
    return n;
}