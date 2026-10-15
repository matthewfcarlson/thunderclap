typedef unsigned int size_t;
void* __cdecl operator new(size_t);
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
} // namespace fight
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
    int a;
    int b;
};
class RageModeStateCondition : public BaseCondition {
  public:
    RageModeStateCondition(int x) throw() : BaseCondition(x) {
        a = 0;
        b = 0;
    }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryTemplate : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
template <> void* ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_5() {
    return new hulkfight::motion::RageModeStateCondition(0);
}
} // namespace fight