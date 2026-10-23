#include "gen/fight.h"

extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004bd5b8;
namespace fight {
class ConditionFactoryCaster_186860 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropMassCondition_186860 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004bd5b8, 0) != 0;
}
