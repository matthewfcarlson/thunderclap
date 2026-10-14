extern "C" char DAT_00428a44[];
typedef unsigned int u32_23d180;
extern void* __cdecl FUN_0008d690(unsigned int);
struct Init_23d180 {
    void init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    Init_23d180* p = (Init_23d180*)FUN_0008d690(12);
    if (p) {
        p->init(1);
        *(u32_23d180*)p = ((int)DAT_00428a44);
        return p;
    }
    return 0;
}