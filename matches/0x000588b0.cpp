void* __cdecl operator new(unsigned int);
class CCondition_588b0 {
  public:
    virtual void f0();
    CCondition_588b0(int) throw();
    char pad[8];
};
class CSmartPropCSMableCondition : public CCondition_588b0 {
  public:
    CSmartPropCSMableCondition() throw();
    virtual void f0();
    int value;
};
CSmartPropCSMableCondition::CSmartPropCSMableCondition() throw() : CCondition_588b0(0) {
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