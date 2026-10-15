unsigned int f(float scale, unsigned int n) {
    unsigned int v = (unsigned int)((float)n * scale);
    if (v < 0xbc)
        return 0xbc;
    if (v > 0x2edef)
        return 0x2edef;
    return v;
}