#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_149c90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CivilianAttachedCondition_149c90 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004af148;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004af148, 0) != 0;
}
