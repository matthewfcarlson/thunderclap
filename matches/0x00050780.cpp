#include "gen/fight.h"

class CButtonReleaseCondition_50780;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00492368;
namespace fight {
class ConditionFactoryCaster_50780 {
  public:
    virtual bool vfunc_0(CButtonReleaseCondition_50780*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition>::vfunc_0(void* __p0) { CButtonReleaseCondition_50780 * p = (CButtonReleaseCondition_50780 *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492368, 0) != 0;
}
