struct Ref_1484f0 {
    virtual void AddRef();
    virtual void Release();
};
struct B_1484f0 {
    B_1484f0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct GA : B_1484f0 {
    int m1c;
    Ref_1484f0* m20;
    int m24;
    GA(int a, Ref_1484f0* r);
    virtual void V0();
};
GA::GA(int a, Ref_1484f0* r) {
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
