extern "C" char DAT_004167d8[];
class TargetingCondition {
  public:
    TargetingCondition(int);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init(int);
    char pad[12];
    char flag;
};
extern void* operator_new(unsigned int);
class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual TargetingCondition* vfunc_5();
};
TargetingCondition* ConditionFactoryTemplate::vfunc_5() {
    TargetingCondition* p = (TargetingCondition*)operator_new(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_004167d8);
        *((char*)p + 0xc) = 1;
    } else {
        p = 0;
    }
    return p;
}