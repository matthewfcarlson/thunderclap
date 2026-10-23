#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_127ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class HasTargetCondition_127ec0 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a8530;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8530, 0) != 0;
}
