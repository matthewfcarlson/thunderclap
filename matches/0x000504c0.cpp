#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_504c0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CAlertStatusCondition_504c0;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int g1, g2;
template <> bool fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &g1, &g2, 0) != 0;
}
