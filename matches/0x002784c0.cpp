unsigned char __stdcall compare(const unsigned short* a, const unsigned short* b) {
    unsigned short x = *b;
    while (x != 0) {
        if (*a == 0 || *a != x)
            return 0;
        x = *(++b);
        ++a;
    }
    return 1;
}