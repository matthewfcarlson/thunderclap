typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    BaseCondition(int) throw();
};
class HasTargetCondition : public BaseCondition {
  public:
    HasTargetCondition(int) throw();
    char flag;
};
HasTargetCondition::HasTargetCondition(int n) throw() : BaseCondition(n) {
    flag = 1;
}
} // namespace ai
} // namespace hulkfight
namespace fight {
class ConditionFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};
class HasTargetFactory : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
void* HasTargetFactory::vfunc_5() {
    return new hulkfight::ai::HasTargetCondition(0);
}
} // namespace fight