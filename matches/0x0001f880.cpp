struct Ref_1f880 {
    virtual void AddRef();
    virtual void Release();
};
struct B_1f880 {
    B_1f880() throw();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : B_1f880 {
    Ref_1f880* m1c;
    int m20;
    CAction(Ref_1f880* r, int a) {
        Ref_1f880** q = &m1c;
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
    CCameraDramaticAction(int a, Ref_1f880* r);
    virtual void V0();
};
CCameraDramaticAction::CCameraDramaticAction(int a, Ref_1f880* r) : CAction(r, a) {
    m24 = 0;
}
