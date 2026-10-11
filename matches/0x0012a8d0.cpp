extern "C" char DAT_0040fe54[];
class TargetVelocityYCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    TargetVelocityYCondition(int);
    int pad1;
    int pad2;
    int a;
    int b;
};
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual TargetVelocityYCondition* v5();
};
extern void* __cdecl FUN_0008d690(unsigned int);
TargetVelocityYCondition* ConditionFactoryTemplate::v5() {
    TargetVelocityYCondition* p = (TargetVelocityYCondition*)FUN_0008d690(0x14);
    if (p) {
        p->TargetVelocityYCondition::TargetVelocityYCondition(0);
        *(int*)p = ((int)DAT_0040fe54);
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}