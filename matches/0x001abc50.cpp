#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_1abc50 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_FirstTimeCondition_1abc50 {};
} // namespace scenario
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c31b8;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c31b8, 0) != 0;
}
