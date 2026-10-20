#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f();
    char pad[8];
};
class CCollisionHeightCondition_57800 : public Base {
  public:
    CCollisionHeightCondition_57800() throw() : Base(0), a(0), b(0) {}
    virtual void f();
    int a, b;
};
namespace fight {
} // namespace fight
template <> void* fight::ConditionFactoryTemplate<CCollisionHeightCondition>::vfunc_5() {
    return (void*)(new CCollisionHeightCondition_57800);
}
