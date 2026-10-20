#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_127dc0 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int g1, g2;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}
