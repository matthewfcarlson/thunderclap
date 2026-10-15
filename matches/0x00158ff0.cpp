typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void a();
    int x;
    int y;
    Base(int) throw();
};
class CollisionSourceForceMagnitudeCondition : public Base {
  public:
    CollisionSourceForceMagnitudeCondition() throw();
    virtual void a();
    int val1;
    int val2;
};
CollisionSourceForceMagnitudeCondition::CollisionSourceForceMagnitudeCondition() throw()
    : Base(0), val1(0), val2(0) {}
} // namespace motion
} // namespace hulkfight
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
template <class T> class ConditionFactoryTemplate : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
template <>
void* ConditionFactoryTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_5() {
    return new hulkfight::motion::CollisionSourceForceMagnitudeCondition();
}
} // namespace fight