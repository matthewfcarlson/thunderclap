struct Obj_2a40d0 {
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
    Obj_2a40d0** b;
    Obj_2a40d0** e;
    int mc;
};
struct DC_2a40d0 {
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
void DC_2a40d0::v6(int a, int b) {
    unsigned n = ge - gb;
    for (unsigned i = 0; i < n; i++) {
        Grp* g = &gb[i];
        unsigned m = g->e - g->b;
        for (unsigned j = 0; j < m; j++) {
            Obj_2a40d0* o = g->b[j];
            if (o)
                o->v6(a, b);
        }
    }
}
