void* operator new(unsigned int) throw();
class Condition_114240 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
    Condition_114240(int) throw();
};
class LeashedCondition : public Condition_114240 {
  public:
    virtual void v0();
    char enabled;
    LeashedCondition() throw() : Condition_114240(0) { enabled = 1; }
};
class ConditionFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Condition_114240* vfunc_5();
};
Condition_114240* ConditionFactory::vfunc_5() {
    return new LeashedCondition;
}