#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1a69c0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class NodeIsNotRunningCondition_1a69c0 {};
} // namespace scenario
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004c1e58;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1e58, 0) != 0;
}
