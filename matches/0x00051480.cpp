#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(int, int, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_00494510;
namespace fight {
class ConditionFactoryCaster_51480 {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
class CStageCondition_51480;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CStageCondition>::vfunc_0(void* __p0) { int x = (int)__p0;

    return FUN_00344e74(x, 0, &DAT_00491ca8, &DAT_00494510, 0) != 0;
}
