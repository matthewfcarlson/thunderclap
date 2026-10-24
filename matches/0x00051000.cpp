#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00493990;
class ConditionFactoryCaster_51000 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CIsInvincibleCondition_51000 {};

template <> bool fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493990, 0) != 0;
}
