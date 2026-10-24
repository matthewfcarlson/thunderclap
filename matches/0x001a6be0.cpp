#include "gen/fight.h"

extern char DAT_00491ca8;
extern char DAT_004c2350;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1a6be0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_PropTypeCondition_1a6be0;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2350, 0) != 0;
}
