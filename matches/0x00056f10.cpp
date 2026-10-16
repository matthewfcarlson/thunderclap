typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseCondition {
  public:
    BaseCondition() throw();
    virtual void v0();
    char pad[28];
};
class CAxisPressCondition : public BaseCondition {
  public:
    CAxisPressCondition() throw() : BaseCondition() {}
    virtual void v0();
};
class ConditionFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BaseCondition* v5();
};
BaseCondition* ConditionFactory::v5() {
    return new CAxisPressCondition;
}
