extern "C" char DAT_003f9098[];
class CAxisDownCondition {
  public:
    CAxisDownCondition();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    CAxisDownCondition* p = (CAxisDownCondition*)FUN_0008d690(0x20);
    if (p) {
        p->CAxisDownCondition::CAxisDownCondition();
        *(void**)p = (void*)((int)DAT_003f9098);
        return p;
    }
    return 0;
}