#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class TimerCondition_18dc10;
}
} // namespace hulkfight
namespace fight {
class ConditionFactoryCaster_18dc10 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004bf228;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bf228, 0) != 0;
}
