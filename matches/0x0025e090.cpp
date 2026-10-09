struct X {
    char pad0[4];
    unsigned int a;
    char pad8[8];
    unsigned char flag;
    char pad11[3];
    unsigned int c;
    unsigned int d;
};
int __cdecl target(X* p) {
    if (p->flag)
        return 0;
    unsigned int v = p->d;
    unsigned int c = p->c;
    if (v > c)
        return v - c;
    return p->a - c;
}
