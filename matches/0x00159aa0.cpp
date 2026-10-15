typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[8];
    int value;
};
namespace hulkfight {
namespace motion {
class CollisionInterruptPriorityCondition : public BaseCondition {
  public:
    CollisionInterruptPriorityCondition() throw() : BaseCondition(0) { value = 0; }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual T* vfunc_5();
};
template <>
hulkfight::motion::CollisionInterruptPriorityCondition*
ConditionFactoryTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_5() {
    return new hulkfight::motion::CollisionInterruptPriorityCondition();
}
} // namespace fight
