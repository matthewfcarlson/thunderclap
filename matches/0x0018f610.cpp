struct Ref {
    virtual void AddRef();
    virtual void Release();
};
struct Base {
    Base();
    virtual void f0();
    char p[0x18];
};
struct Tank : Base {
    Tank(int a, Ref* r);
    virtual void f1();
    int m1c;
    Ref* m20;
    int m24, m28;
    char flags[4];
    char pad[0x90 - 0x30];
    int m90;
    int arr[4];
};
Tank::Tank(int a, Ref* r) {
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
