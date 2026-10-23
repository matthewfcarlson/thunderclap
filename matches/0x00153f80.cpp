#include "gen/fight.h"

extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_153f80 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class InterruptAccumulatorCondition_153f80 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004b1bf0;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b1bf0, 0) != 0;
}
