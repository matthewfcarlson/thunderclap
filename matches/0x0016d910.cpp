typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    BaseCondition(int) throw();
    char pad[8];
};
class GrappleReactionTypeCondition : public BaseCondition {
  public:
    GrappleReactionTypeCondition() throw() : BaseCondition(0), a(0), b(0) {}
    virtual void f5();
    int a, b;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual hulkfight::motion::GrappleReactionTypeCondition* vfunc_5();
};
hulkfight::motion::GrappleReactionTypeCondition* Factory::vfunc_5() {
    return new hulkfight::motion::GrappleReactionTypeCondition;
}
} // namespace fight