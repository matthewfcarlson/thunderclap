#include "gen/fight.h"

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a3940;
namespace fight {
class ConditionFactoryCaster_110e60 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class OnBlockedTriangleCondition_110e60;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a3940, 0) != 0;
}
