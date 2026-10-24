#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_110f60 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class DefendingCondition_110f60 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a3ab0;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a3ab0, 0) != 0;
}
