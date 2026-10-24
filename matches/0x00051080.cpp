#include "gen/fight.h"

struct TypeInfo {
    int x;
};
extern char DAT_00491ca8;
extern char DAT_00493ad0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_51080 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
class CMotionClimbAngleCondition_51080;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493ad0, 0) != 0;
}
