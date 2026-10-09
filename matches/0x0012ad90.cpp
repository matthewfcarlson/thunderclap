extern void* __cdecl Allocate(unsigned int);
class TargetInvincibleCondition {
  public:
    TargetInvincibleCondition(int);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    unsigned char flag;
};
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual TargetInvincibleCondition* vfunc_5();
};
TargetInvincibleCondition* ConditionFactoryTemplate::vfunc_5() {
    TargetInvincibleCondition* p = (TargetInvincibleCondition*)Allocate(0x10);
    if (p) {
        p->TargetInvincibleCondition::TargetInvincibleCondition(0);
        *(unsigned int*)p = 0x40ff34;
        p->flag = 1;
        return p;
    }
    return (TargetInvincibleCondition*)0;
}