struct Obj31 {
    char p[0x31];
    char f;
};
struct Mgr_1a8ee0 {
    Obj31* Get();
};
struct Hnd {
    void Rel();
};
struct Ent_1a8ee0 {
    char p[0xa8];
    char f;
};
struct Hulk {
    Ent_1a8ee0* Fn(int);
    void Fn2(int);
};
struct Sub_1a8ee0 {
    char p[0x124];
    Hulk* h;
};
struct Gl {
    char p[0x20];
    Sub_1a8ee0* s;
    char q[0x30];
    Mgr_1a8ee0* m;
};
extern Gl* g_1a8ee0;
struct A_1a8ee0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char p[0x20c - 4];
    Hnd* h;
    char pad[4];
    char fl;
    void Inner();
};
void A_1a8ee0::v4() {
    g_1a8ee0->m->Get()->f = 1;
    Inner();
    if (fl) {
        h->Rel();
        fl = 0;
    }
    Hulk* x = g_1a8ee0->s->h;
    if (x) {
        x->Fn(1)->f = 1;
        x->Fn2(0);
    }
}
