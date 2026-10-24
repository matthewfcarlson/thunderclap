#include "gen/fight.h"

class CGrappleAlertStatusCondition_50cc0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_50cc0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_00491ca8;
extern char DAT_00493118;
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493118, 0) != 0;
}
