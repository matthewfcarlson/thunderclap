typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace motion {
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
class PhaseCondition : public Base {
  public:
    PhaseCondition() throw() : Base(0), c(0), d(0) {}
    virtual void f0();
    int c;
    int d;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class ConditionFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
template <class T> class ConditionFactoryTemplate : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
template <> void* ConditionFactoryTemplate<hulkfight::motion::PhaseCondition>::vfunc_5() {
    return new hulkfight::motion::PhaseCondition;
}
} // namespace fight