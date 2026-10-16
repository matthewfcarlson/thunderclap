typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
class CivilianAttachedCondition : public BaseCondition {
  public:
    virtual void f();
    unsigned char flag;
    CivilianAttachedCondition(int x) throw() : BaseCondition(x), flag(1) {}
};
} // namespace motion
} // namespace hulkfight
void* fight::ConditionFactory::vfunc_5() {
    return new hulkfight::motion::CivilianAttachedCondition(0);
}