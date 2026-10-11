void* operator new(unsigned int);
struct Base {
    Base(int) throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* f();
    int m4, m8;
};
struct Cond : Base {
    int mc, m10;
    Cond() throw() : Base(0) {
        mc = 0;
        m10 = 0;
    }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* f();
};
struct Fac {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* vfunc_5();
};
Base* Fac::vfunc_5() {
    return new Cond;
}
