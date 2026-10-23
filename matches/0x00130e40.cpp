#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_130e40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class LocationCondition_130e40 {};
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004aa9b8;
extern "C" int __cdecl check(void*, int, void*, void*, int);
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004aa9b8, 0) != 0;
}
