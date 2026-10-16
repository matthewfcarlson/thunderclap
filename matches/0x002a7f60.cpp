char* f(char* dest, int count, const char* src) {
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