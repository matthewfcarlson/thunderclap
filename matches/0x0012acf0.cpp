void* __cdecl operator new(unsigned int) throw();
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class TargetFirstShotCondition : public BaseCondition {
  public:
    TargetFirstShotCondition() throw() : BaseCondition(0) { flag = 1; }
    virtual void v0();
    char flag;
};
class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual BaseCondition* vfunc_5();
};
BaseCondition* ConditionFactory::vfunc_5() {
    return new TargetFirstShotCondition;
}