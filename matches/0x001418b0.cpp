#include "gen/fight.h"

extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004ad4d0;
namespace fight {
class ConditionFactoryCaster_1418b0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class WallVelocityCondition_1418b0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastCheck(p, 0, &DAT_00491ca8, &DAT_004ad4d0, 0) != 0;
}
