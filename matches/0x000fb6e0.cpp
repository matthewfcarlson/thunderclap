typedef unsigned int uint_fb6e0;
extern "C" bool FUN_000fb6e0(const short* a, const short* b, uint_fb6e0 count) {
    uint_fb6e0 i = 0;
    while (i < count) {
        if (*a != *b)
            return false;
        ++a;
        ++b;
        ++i;
    }
    return true;
}