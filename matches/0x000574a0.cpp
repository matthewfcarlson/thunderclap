struct Base_574a0 {
    virtual void f0();
    Base_574a0() throw();
    char pad[0x14];
};
struct CButtonUpCondition : Base_574a0 {
    CButtonUpCondition() throw() {}
    virtual void f0();
};
void* operator new(unsigned int);
struct F_574a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_574a0* vfunc_5();
};
Base_574a0* F_574a0::vfunc_5() {
    return new CButtonUpCondition;
}
