#include "gen/fight.h"

class ConditionFactoryCaster_1280c0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class AcquireTargetCondition_1280c0 {};
extern char DAT_00491ca8;
extern char DAT_004a8818;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8818, 0) != 0;
}
