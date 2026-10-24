#include "gen/fight.h"

class CCollisionDirectionCondition_50940;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004927d8;
namespace fight {
class ConditionFactoryCaster_50940 {
  public:
    virtual bool vfunc_0(CCollisionDirectionCondition_50940*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::vfunc_0(void* __p0) { CCollisionDirectionCondition_50940 * p = (CCollisionDirectionCondition_50940 *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004927d8, 0) != 0;
}
