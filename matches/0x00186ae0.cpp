#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_186ae0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropMissileCountCondition_186ae0 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_004bd988;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_00491ca8, &DAT_004bd988, 0) != 0;
}
