#include "gen/fight.h"
extern char DAT_00491ca8;
extern char DAT_00492c90;

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

class ConditionFactoryCaster_50b00 {
  public:
    virtual int vfunc_0(void* obj);
    virtual int vfunc_1(void* obj);
};

template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, (void*)&DAT_00491ca8, (void*)&DAT_00492c90, 0) != 0);
}
