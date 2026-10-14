struct Base_58fd0 {
    virtual void f0();
    Base_58fd0() throw();
    char pad[0x14];
};
struct CNameFlagCondition : Base_58fd0 {
    CNameFlagCondition() throw() {}
    virtual void f0();
};
void* operator new(unsigned int);
struct F_58fd0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_58fd0* vfunc_5();
};
Base_58fd0* F_58fd0::vfunc_5() {
    return new CNameFlagCondition;
}
