struct Sub {
    void Copy(const Sub* o);
    char p[8];
};
struct Base {
    Base();
    virtual void f0();
    int b4;
    Sub s;
};
struct DH : Base {
    DH(const DH& o);
    virtual void f1();
    int m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38;
};
DH::DH(const DH& o) {
    m10 = 0;
    s.Copy(&o.s);
    m14 = o.m14;
    m18 = o.m18;
    m1c = o.m1c;
    m20 = o.m20;
    m24 = o.m24;
    m28 = o.m28;
    m2c = o.m2c;
    m30 = o.m30;
    m34 = o.m34;
    m38 = o.m38;
}
