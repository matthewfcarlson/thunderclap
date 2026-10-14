struct Ref_18f610 {
    virtual void AddRef();
    virtual void Release();
};
struct Base_18f610 {
    Base_18f610();
    virtual void f0();
    char p[0x18];
};
struct Tank : Base_18f610 {
    Tank(int a, Ref_18f610* r);
    virtual void f1();
    int m1c;
    Ref_18f610* m20;
    int m24, m28;
    char flags[4];
    char pad[0x90 - 0x30];
    int m90;
    int arr[4];
};
Tank::Tank(int a, Ref_18f610* r) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m90 = 0;
    m1c = a;
    if (r)
        r->AddRef();
    if (m20)
        m20->Release();
    m20 = r;
    for (int i = 0; i < 4; i++) {
        arr[i] = 0;
        flags[i] = 1;
    }
}
