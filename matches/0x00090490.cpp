struct V3 {
    int x, y, z;
};
struct Sub {
    void Get(V3* out);
};
struct D {
    char p[0x10];
    Sub* sub;
    char q[0x1b0c - 0x14];
    float f;
};
struct C {
    char p[0x124];
    D* d;
};
struct G {
    char p[0x20];
    C* c;
};
extern G* g_g;
struct T {
    char pad[0x14];
    int mode;
    char flag;
    char pad2[3];
    V3 a;
    V3 b;
    int i34;
    int i38;
    void F();
};
void T::F() {
    if (flag)
        return;
    int m = mode;
    flag = 1;
    i34 = 0;
    i38 = 0;
    if (m > 0) {
        if (m > 2) {
            if (m == 3)
                i34 = (int)g_g->c->d->f;
        } else {
            V3* p = &a;
            g_g->c->d->sub->Get(p);
            b.x = p->x;
            b.y = p->y;
            b.z = p->z;
        }
    }
}
