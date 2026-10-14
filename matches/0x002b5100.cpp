void* __cdecl alloc(unsigned int) throw();
struct V3_2b5100 {
    unsigned a, b, c;
    void Set(const V3_2b5100& s) {
        a = s.a;
        b = s.b;
        c = s.c;
    }
};
struct B0_2b5100 {
    virtual ~B0_2b5100() throw();
};
struct Init1_2b5100 {
    unsigned m4;
    Init1_2b5100() throw() { m4 = 0; }
};
struct M_2b5100 : B0_2b5100, Init1_2b5100 {
    unsigned m8, mc;
    V3_2b5100* m10;
    V3_2b5100* m14;
    M_2b5100(const M_2b5100& o) throw();
    virtual ~M_2b5100() throw();
};
M_2b5100::M_2b5100(const M_2b5100& o) throw() {
    unsigned i = 0;
    m8 = o.m8;
    mc = o.mc;
    m10 = (V3_2b5100*)alloc(m8 * 12);
    m14 = (V3_2b5100*)alloc(mc * 12);
    for (; i < m8; i++)
        m10[i].Set(o.m10[i]);
    for (i = 0; i < mc; i++)
        m14[i].Set(o.m14[i]);
}
