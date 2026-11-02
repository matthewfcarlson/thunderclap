extern "C" int FUN_00294b80(const unsigned short* p) {
    int n = 0;
    if (p)
        while (p[n] != 0)
            ++n;
    return n;
}