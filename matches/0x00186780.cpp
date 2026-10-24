#include "gen/fight.h"

class ConditionFactoryCaster_186780 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class GrapplePropStateByNameCondition_186780 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004bd420;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd420, 0) != 0;
}
