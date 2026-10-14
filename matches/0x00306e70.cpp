struct S_306e70 {
    unsigned int a[8];
    unsigned char b;
    unsigned char pad[3];
    unsigned int c;
};
S_306e70* __fastcall target(S_306e70* p) {
    p->a[0] = 0;
    p->a[1] = 0;
    p->a[2] = 0;
    p->a[3] = 0;
    p->a[4] = 0x3f800000;
    p->a[5] = 0;
    p->a[6] = 0x3f800000;
    p->a[7] = 0x3f800000;
    p->b = 0;
    p->c = 0;
    return p;
}
