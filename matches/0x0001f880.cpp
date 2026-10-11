struct Ref {
    virtual void AddRef();
    virtual void Release();
};
struct B {
    B() throw();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : B {
    Ref* m1c;
    int m20;
    CAction(Ref* r, int a) {
        Ref** q = &m1c;
        *q = 0;
        if (r)
            r->AddRef();
        if (m1c)
            m1c->Release();
        m1c = r;
        m20 = a;
    }
    virtual void V0();
};
struct CCameraDramaticAction : CAction {
    int m24;
    CCameraDramaticAction(int a, Ref* r);
    virtual void V0();
};
CCameraDramaticAction::CCameraDramaticAction(int a, Ref* r) : CAction(r, a) {
    m24 = 0;
}
