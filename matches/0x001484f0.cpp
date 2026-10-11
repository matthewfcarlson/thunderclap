struct Ref {
    virtual void AddRef();
    virtual void Release();
};
struct B {
    B() throw();
    virtual void V0();
    char pad04[0x18];
};
struct GA : B {
    int m1c;
    Ref* m20;
    int m24;
    GA(int a, Ref* r);
    virtual void V0();
};
GA::GA(int a, Ref* r) {
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
