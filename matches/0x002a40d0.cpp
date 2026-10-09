struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
struct Grp {
    int m0;
    Obj** b;
    Obj** e;
    int mc;
};
struct DC {
    char p[0x44];
    Grp* gb;
    Grp* ge;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
void DC::v6(int a, int b) {
    unsigned n = ge - gb;
    for (unsigned i = 0; i < n; i++) {
        Grp* g = &gb[i];
        unsigned m = g->e - g->b;
        for (unsigned j = 0; j < m; j++) {
            Obj* o = g->b[j];
            if (o)
                o->v6(a, b);
        }
    }
}
