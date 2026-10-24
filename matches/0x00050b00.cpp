#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

class ConditionFactoryCaster_50b00 {
  public:
    virtual int vfunc_0(void* obj);
    virtual int vfunc_1(void* obj);
};

template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, (void*)0x491ca8, (void*)0x492c90, 0) != 0);
}
