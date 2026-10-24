#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c2280;
namespace fight {
class ConditionFactoryCaster_1a6b80 {
  public:
    virtual int Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_PropStateDescCondition_1a6b80 {};
} // namespace scenario
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2280, 0) != 0;
}
