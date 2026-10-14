struct Ref_11e100 {
    virtual void AddRef();
    virtual void Release();
};
struct B_11e100 {
    B_11e100() throw();
    virtual void V0();
    char pad04[0x18];
};
struct SL : B_11e100 {
    int m1c;
    Ref_11e100* m20;
    int m24;
    SL(int a, Ref_11e100* r);
    virtual void V0();
};
SL::SL(int a, Ref_11e100* r) {
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
