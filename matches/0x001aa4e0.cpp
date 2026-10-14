void* operator new(unsigned int);
struct Base_1aa4e0 {
    Base_1aa4e0(int) throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_1aa4e0* f();
    int m4, m8;
};
struct Cond_1aa4e0 : Base_1aa4e0 {
    char mc;
    Cond_1aa4e0() throw() : Base_1aa4e0(0) { mc = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_1aa4e0* f();
};
struct Fac_1aa4e0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_1aa4e0* vfunc_5();
};
Base_1aa4e0* Fac_1aa4e0::vfunc_5() {
    return new Cond_1aa4e0;
}
