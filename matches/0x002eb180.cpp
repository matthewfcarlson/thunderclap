struct Obj_2eb180 {
    char pad0[8];
    unsigned int flags;
    char pad1[0x74];
    float a[8];
};
void target(int p1, Obj_2eb180* p2, double a, double b, double c, double d, double e, double f, double g, double h) {
    if (!p1)
        return;
    if (!p2)
        return;
    p2->flags |= 4;
    p2->a[0] = (float)a;
    p2->a[1] = (float)b;
    p2->a[2] = (float)c;
    p2->a[3] = (float)d;
    p2->a[4] = (float)e;
    p2->a[5] = (float)f;
    p2->a[6] = (float)g;
    p2->a[7] = (float)h;
}