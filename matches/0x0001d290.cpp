struct Ref_1d290 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1d290 {
    Action_1d290() throw();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : Action_1d290 {
    Ref_1d290* m1c;
    int m20;
    CAction(Ref_1d290* r, int a) {
        Ref_1d290** q = &m1c;
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
struct CMoveAction : CAction {
    int m24;
    CMoveAction(int a, Ref_1d290* r);
    virtual void V0();
};
CMoveAction::CMoveAction(int a, Ref_1d290* r) : CAction(r, a) {
    m24 = 0;
}
