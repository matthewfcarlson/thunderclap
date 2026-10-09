struct Obj {
    char pad0[8];
    unsigned int flags;
    char pad1[0x64 - 12];
    int a;
    int b;
    unsigned char c;
};
void target(int p1, Obj* p2, int p3, int p4, unsigned char p5) {
    if (p1 != 0 && p2 != 0) {
        p2->a = p3;
        p2->b = p4;
        p2->c = p5;
        p2->flags |= 0x100;
    }
}