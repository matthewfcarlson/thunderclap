#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_51200 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CSmartPropAngleCondition_51200;
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00493e80;
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, &DAT_00491ca8, &DAT_00493e80, 0) != 0;
}
