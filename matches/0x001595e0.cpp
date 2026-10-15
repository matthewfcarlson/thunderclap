typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    BaseCondition(int) throw();
};
class CollisionSourceIsMissileCondition : public BaseCondition {
  public:
    CollisionSourceIsMissileCondition() throw() : BaseCondition(0) { flag = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    char flag;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual T* vfunc_5();
};
template <>
hulkfight::motion::CollisionSourceIsMissileCondition*
ConditionFactoryTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_5() {
    return new hulkfight::motion::CollisionSourceIsMissileCondition;
}
} // namespace fight