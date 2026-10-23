#include "gen/fight.h"

class ShoreNearCondition_16abb0;
extern char DAT_00491ca8;
extern char DAT_004b7890;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_16abb0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7890, 0) != 0;
}
