#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_130c60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class MissionProgressCondition_130c60 {};
} // namespace hulkfight
extern "C" int __cdecl helper(const char*, int, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_004aa710;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return helper(s, 0, &DAT_00491ca8, &DAT_004aa710, 0) != 0;
}
