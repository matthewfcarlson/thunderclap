#include "gen/fight.h"

extern char DAT_00491ca8;
extern char DAT_004921a0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_506c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CAxisUpCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004921a0, 0) != 0;
}
