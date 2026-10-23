#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_149d50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern int a, b;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &a, &b, 0) != 0;
}
