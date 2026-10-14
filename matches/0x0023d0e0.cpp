extern "C" char DAT_00428a24[];
typedef unsigned int u32_23d0e0;
struct NotCondition {
    virtual void a();
    virtual void b();
    virtual void c();
};
extern void* __cdecl FUN_0008d690(unsigned int);
struct Helper_23d0e0 {
    void f(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NotCondition* vfunc_5();
};
NotCondition* ConditionFactoryTemplate::vfunc_5() {
    NotCondition* p = (NotCondition*)FUN_0008d690(0xc);
    if (p) {
        ((Helper_23d0e0*)p)->f(2);
        *(u32_23d0e0*)p = ((int)DAT_00428a24);
        return p;
    }
    return (NotCondition*)0;
}