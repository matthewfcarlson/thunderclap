#include "gen/fight.h"

extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b24c8;
namespace fight {
class ConditionFactoryCaster_154400 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitPushbackVelocityCondition_154400 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastCheck(p, 0, &DAT_00491ca8, &DAT_004b24c8, 0) != 0;
}
