#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_50d80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CGrappleFightNodeParentCondition_50d80 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00493328;
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493328, 0) != 0;
}
