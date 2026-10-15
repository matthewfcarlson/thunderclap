void* __cdecl operator new(unsigned int);
class BaseCondition {
  public:
    virtual void f0();
    BaseCondition(int) throw();
    char pad[8];
};
class CSmartPropCSMableCondition : public BaseCondition {
  public:
    CSmartPropCSMableCondition() throw();
    virtual void f0();
    int value;
};
CSmartPropCSMableCondition::CSmartPropCSMableCondition() throw() : BaseCondition(0) {
    value = 0;
}
namespace fight {
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CSmartPropCSMableCondition* vfunc_5();
};
} // namespace fight
CSmartPropCSMableCondition* fight::ConditionFactoryTemplate::vfunc_5() {
    return new CSmartPropCSMableCondition;
}