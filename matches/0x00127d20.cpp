#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a82f8;
namespace fight {
class ConditionFactoryCaster_127d20 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDistanceYCondition_127d20 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a82f8, 0) != 0;
}
