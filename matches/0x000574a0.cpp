struct Base {
    virtual void f0();
    Base() throw();
    char pad[0x14];
};
struct CButtonUpCondition : Base {
    CButtonUpCondition() throw() {}
    virtual void f0();
};
void* operator new(unsigned int);
struct F {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* vfunc_5();
};
Base* F::vfunc_5() {
    return new CButtonUpCondition;
}
