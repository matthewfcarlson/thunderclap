#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004aa7c0;
namespace fight {
class ConditionFactoryCaster_130ce0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class UnlockableCondition_130ce0 {};
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aa7c0, 0) != 0;
}
