struct S {
    char pad[0x10];
    unsigned char b[0x20];
};
void f(S* a, unsigned short* d) {
    if (d) {
        unsigned char* p = a->b;
        int i = 0;
        do {
            if (p[0] == 0)
                break;
            d[i] = p[i];
            i++;
        } while (i < 0x1f);
        d[i] = 0;
    }
}
