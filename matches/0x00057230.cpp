class CButtonDownCondition {
  public:
    CButtonDownCondition();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vft_57230;
class Factory_57230 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CButtonDownCondition* vfunc_5();
};
CButtonDownCondition* Factory_57230::vfunc_5() {
    CButtonDownCondition* p = (CButtonDownCondition*)FUN_0008d690(0x20);
    if (p) {
        p->CButtonDownCondition::CButtonDownCondition();
        *(int*)p = (int)&g_vft_57230;
        return p;
    }
    return 0;
}