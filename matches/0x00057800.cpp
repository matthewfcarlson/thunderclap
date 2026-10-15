typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f();
    char pad[8];
};
class CCollisionHeightCondition : public Base {
  public:
    CCollisionHeightCondition() throw() : Base(0), a(0), b(0) {}
    virtual void f();
    int a, b;
};
namespace fight {
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCollisionHeightCondition* vfunc_5();
};
} // namespace fight
CCollisionHeightCondition* fight::ConditionFactoryTemplate::vfunc_5() {
    return new CCollisionHeightCondition;
}