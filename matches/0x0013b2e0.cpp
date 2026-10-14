struct Ref_13b2e0 {
    virtual void AddRef();
    virtual void Release();
};
struct B_13b2e0 {
    B_13b2e0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct AL : B_13b2e0 {
    int m1c;
    Ref_13b2e0* m20;
    int m24;
    AL(int a, Ref_13b2e0* r);
    virtual void V0();
};
AL::AL(int a, Ref_13b2e0* r) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m1c = a;
    if (r)
        r->AddRef();
    if (m20)
        m20->Release();
    m20 = r;
}
