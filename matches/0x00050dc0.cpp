#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004933d8;
namespace fight {
class ConditionFactoryCaster_50dc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CGrappleFightNodeTimeCondition_50dc0 {};
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004933d8, 0) != 0;
}
