struct H2_2fd5a0;
struct H3_2fd5a0;
struct H1 {
    H2_2fd5a0* first(int);
};
struct H2_2fd5a0 {
    H3_2fd5a0* second();
};
struct H3_2fd5a0 {
    struct SimStateArticulated* third();
};
struct SimState {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
struct SimStateArticulated : SimState {
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    char pad[0x84];
    H1* member;
    SimStateArticulated* vfunc_4(int);
};
SimStateArticulated* SimStateArticulated::vfunc_4(int p) {
    if (p >= 0 && member)
        return member->first(p)->second()->third();
    return (SimStateArticulated*)((char*)this + 0x10);
}