extern void* __cdecl FUN_0008d690(unsigned int);
class VelocityYCondition {
  public:
    virtual void dummy();
    int pad1;
    int pad2;
    int b;
    int c;
    VelocityYCondition(int);
};
class ConditionFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual VelocityYCondition* vfunc_5();
};
VelocityYCondition* ConditionFactory::vfunc_5() {
    VelocityYCondition* p = (VelocityYCondition*)FUN_0008d690(0x14);
    if (p) {
        p->VelocityYCondition::VelocityYCondition(0);
        *(int*)p = 0x4166d8;
        p->b = 0;
        p->c = 0;
        return p;
    } else {
        return (VelocityYCondition*)0;
    }
}
