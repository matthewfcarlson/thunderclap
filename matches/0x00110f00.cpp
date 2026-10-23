#include "gen/fight.h"

namespace hulkfight {
namespace ai {
class AIFightNodeCondition_110f00 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl Cast(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_110f00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_00491ca8;
extern char DAT_004a3a00;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Cast(p, 0, &DAT_00491ca8, &DAT_004a3a00, 0) != 0;
}
