#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_50700 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CButtonDownCondition_50700;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CButtonDownCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)0x491ca8, (void*)0x492238, 0) != 0;
}
