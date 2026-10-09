int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}