void* operator new(unsigned int) throw();
class BaseCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
    BaseCondition(int) throw();
};
class LeashedCondition : public BaseCondition {
  public:
    virtual void v0();
    char enabled;
    LeashedCondition() throw() : BaseCondition(0) { enabled = 1; }
};
class ConditionFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual BaseCondition* vfunc_5();
};
BaseCondition* ConditionFactory::vfunc_5() {
    return new LeashedCondition;
}