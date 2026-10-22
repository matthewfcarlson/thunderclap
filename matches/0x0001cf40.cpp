struct Ref_1cf40 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1cf40 {
    Action_1cf40() throw();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : Action_1cf40 {
    Ref_1cf40* m1c;
    int m20;
    CAction(Ref_1cf40* r, int a) {
        Ref_1cf40** q = &m1c;
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
struct CProceduralDurationAnimationAction : CAction {
    int m24;
    CProceduralDurationAnimationAction(int a, Ref_1cf40* r);
    virtual void V0();
};
CProceduralDurationAnimationAction::CProceduralDurationAnimationAction(int a, Ref_1cf40* r) : CAction(r, a) {
    m24 = 0;
}
