#include "gen/fight.h"

extern char DAT_00491ca8;
extern char DAT_004bd288;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_186680 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0(void* __p0) { void * value = (void *)__p0;

    return FUN_00344e74(value, 0, &DAT_00491ca8, &DAT_004bd288, 0) != 0;
}
