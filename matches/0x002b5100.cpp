void* __cdecl alloc(unsigned int) throw();
struct V3 {
    unsigned a, b, c;
    void Set(const V3& s) {
        a = s.a;
        b = s.b;
        c = s.c;
    }
};
struct B0 {
    virtual ~B0() throw();
};
struct Init1 {
    unsigned m4;
    Init1() throw() { m4 = 0; }
};
struct M : B0, Init1 {
    unsigned m8, mc;
    V3* m10;
    V3* m14;
    M(const M& o) throw();
    virtual ~M() throw();
};
M::M(const M& o) throw() {
    unsigned i = 0;
    m8 = o.m8;
    mc = o.mc;
    m10 = (V3*)alloc(m8 * 12);
    m14 = (V3*)alloc(mc * 12);
    for (; i < m8; i++)
        m10[i].Set(o.m10[i]);
    for (i = 0; i < mc; i++)
        m14[i].Set(o.m14[i]);
}
