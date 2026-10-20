#include "gen/fight.h"

extern int gA;
extern int gB;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1111e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &gA, &gB, 0) != 0;
}
