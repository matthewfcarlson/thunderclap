extern signed char gTable[256];
int __cdecl CountChars(const char* str, unsigned int* end) {
    int count = 0;
    unsigned int pos = 0;
    unsigned char c = str[pos];
    while (c) {
        const char* p = str + pos;
        unsigned int n = (int)gTable[c] + 1;
        unsigned int i = 0;
        while (i < n) {
            if (!p)
                return -1;
            ++i;
            ++p;
        }
        pos += n;
        c = str[pos];
        ++count;
    }
    if (end)
        *end = pos;
    return count;
}
