typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace scenario {
class Base {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
    Base(int) throw();
};
class Event_LocomotionStateNamePreviousCondition : public Base {
  public:
    Event_LocomotionStateNamePreviousCondition() throw();
    virtual void v0();
    int a, b;
};
Event_LocomotionStateNamePreviousCondition::Event_LocomotionStateNamePreviousCondition() throw()
    : Base(0), a(0), b(0) {}
} // namespace scenario
} // namespace hulkfight
namespace fight {
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::scenario::Event_LocomotionStateNamePreviousCondition* vfunc_5();
};
hulkfight::scenario::Event_LocomotionStateNamePreviousCondition* ConditionFactoryTemplate::vfunc_5() {
    return new hulkfight::scenario::Event_LocomotionStateNamePreviousCondition;
}
} // namespace fight