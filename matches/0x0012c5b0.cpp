#include "gen/fight.h"

class Object_12c5b0 {};
class ConditionFactoryCaster_12c5b0 {
  public:
    virtual bool vfunc_0(Object_12c5b0*);
    virtual void vfunc_1();
};
class ThreatCondition_12c5b0 {};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);
extern void* a;
extern void* b;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatCondition>::vfunc_0(void* __p0) { Object_12c5b0 * p = (Object_12c5b0 *)__p0;

    return DynamicCast(p, 0, &a, &b, 0) != 0;
}
