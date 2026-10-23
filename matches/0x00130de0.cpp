#include "gen/fight.h"

namespace hulkfight {
class DebugPrintCondition_130de0;
}
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_130de0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* a;
extern void* b;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::DebugPrintCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
