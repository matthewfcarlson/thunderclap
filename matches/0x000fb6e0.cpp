typedef unsigned int uint_fb6e0;
bool compare(const short* a, const short* b, uint_fb6e0 count) {
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