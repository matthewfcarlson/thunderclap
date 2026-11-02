extern "C" char* FUN_002a7f60(char* dest, int count, const char* src) {
    if (count) {
        int n = count;
        char* p = dest;
        do {
            if (p)
                *p = *src;
            ++p;
            --n;
        } while (n);
        return p;
    }
    return dest;
}