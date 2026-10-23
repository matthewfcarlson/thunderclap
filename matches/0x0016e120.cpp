#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace fight {
class ConditionFactory_16e120 {
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
class RageModeStateCondition_16e120 : public BaseCondition {
  public:
    RageModeStateCondition_16e120(int x) throw() : BaseCondition(x) {
        a = 0;
        b = 0;
    }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::RageModeStateCondition_16e120(0));
}
