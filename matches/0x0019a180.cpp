#include "gen/fight.h"

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c0b38;
namespace fight {
class ConditionFactoryCaster_19a180 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropGrabbableIsMissileCondition_19a180 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004c0b38, 0) != 0;
}
