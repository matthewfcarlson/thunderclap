#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c1558;
namespace fight {
class ConditionFactoryCaster_1a1a30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class LuaCondition_1a1a30 {};
} // namespace scenario
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1558, 0) != 0;
}
