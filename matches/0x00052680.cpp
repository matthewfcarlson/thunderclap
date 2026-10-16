#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace fight {
class Arg;
class Part {
  public:
    Part(Arg*) throw();
    char data[8];
};
class BaseCond {
  public:
    BaseCond() throw();
    virtual void f();
    char pad[4];
};
class CIsInvincibleCondition_52680 : public BaseCond {
  public:
    CIsInvincibleCondition_52680(Arg* a) throw() : BaseCond(), part(a) {}
    virtual void f();
    Part part;
};
class ConditionFactoryCaster_52680 {
  public:
    virtual void vfunc_0();
    virtual CIsInvincibleCondition_52680* vfunc_1(Arg*);
};

} // namespace fight
template <> void* fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_1(void* __p0) { Arg * a = (Arg *)__p0;

    return (void*)(new CIsInvincibleCondition_52680(a));
}
