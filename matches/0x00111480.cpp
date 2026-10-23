#include "gen/fight.h"

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a41d8;
namespace fight {
class ConditionFactoryCaster_111480 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class PropsToSuckCondition_111480;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a41d8, 0) != 0;
}
