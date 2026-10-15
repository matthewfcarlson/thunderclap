typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
class ShoreNearCondition : public BaseCondition {
  public:
    virtual void f();
    bool enabled;
    ShoreNearCondition(int x) throw() : BaseCondition(x), enabled(true) {}
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::motion::ShoreNearCondition* vfunc_5();
};
} // namespace fight
hulkfight::motion::ShoreNearCondition* fight::ConditionFactoryTemplate::vfunc_5() {
    return new hulkfight::motion::ShoreNearCondition(0);
}