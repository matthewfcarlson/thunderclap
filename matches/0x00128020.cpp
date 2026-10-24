#include "gen/fight.h"

extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern "C" const char DAT_00491ca8[];
extern "C" const char DAT_004a8758[];
namespace fight {
class ConditionFactoryCaster_128020 {
  public:
    virtual int f0(void*);
    virtual int f1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDistanceXZCondition_128020;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, DAT_00491ca8, DAT_004a8758, 0) != 0;
}
