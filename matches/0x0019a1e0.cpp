#include "gen/fight.h"

class Base {
  public:
    virtual int Test(void*);
    virtual void v1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c0c00;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c0c00, 0) != 0;
}
