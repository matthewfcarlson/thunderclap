struct Ref {
    virtual void AddRef();
    virtual void Release();
};
struct B {
    B() throw();
    virtual void V0();
    char pad04[0x18];
};
struct S {
    S() throw();
    char p[0x28];
};
struct EA : B {
    Ref* m1c;
    int m20;
    Ref* m24;
    int m28;
    Ref* m2c;
    Ref* m30;
    Ref* m34;
    S s;
    int m60;
    char m64;
    EA(Ref* a, Ref* b, Ref* c, int d, Ref* e, Ref* f, Ref* g);
    virtual void V0();
};
EA::EA(Ref* a, Ref* b, Ref* c, int d, Ref* e, Ref* f, Ref* g)
    : m1c(0), m20(0), m24(0), m28(d), m2c(e), m30(f), m34(0) {
    m60 = 0;
    m64 = 0;
    if (a)
        a->AddRef();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = (int)b;
    if (c)
        c->AddRef();
    if (m24)
        m24->Release();
    m24 = c;
    if (g)
        g->AddRef();
    if (m34)
        m34->Release();
    m34 = g;
}
