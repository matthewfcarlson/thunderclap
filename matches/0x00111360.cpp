#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_111360 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class InActiveCondition_111360 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a4068;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_00491ca8, &DAT_004a4068, 0) != 0;
}
