#include "gen/fight.h"

class SmartPropIsCargoCondition_186be0 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004bdb20;
namespace fight {
class ConditionFactoryCaster_186be0 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bdb20, 0) != 0;
}
