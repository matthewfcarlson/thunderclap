struct V3_90490 {
    int x, y, z;
};
struct Sub_90490 {
    void Get(V3_90490* out);
};
struct D {
    char p[0x10];
    Sub_90490* sub;
    char q[0x1b0c - 0x14];
    float f;
};
struct C_90490 {
    char p[0x124];
    D* d;
};
struct G_90490 {
    char p[0x20];
    C_90490* c;
};
extern G_90490* g_g_90490;
struct T_90490 {
    char pad[0x14];
    int mode;
    char flag;
    char pad2[3];
    V3_90490 a;
    V3_90490 b;
    int i34;
    int i38;
    void F();
};
void T_90490::F() {
    if (flag)
        return;
    int m = mode;
    flag = 1;
    i34 = 0;
    i38 = 0;
    if (m > 0) {
        if (m > 2) {
            if (m == 3)
                i34 = (int)g_g_90490->c->d->f;
        } else {
            V3_90490* p = &a;
            g_g_90490->c->d->sub->Get(p);
            b.x = p->x;
            b.y = p->y;
            b.z = p->z;
        }
    }
}
