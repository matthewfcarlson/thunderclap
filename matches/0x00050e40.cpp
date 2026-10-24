#include "gen/fight.h"

extern char DAT_00491ca8;
extern char DAT_00493528;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_50e40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CGrappleSizeCondition_50e40 {};
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493528, 0) != 0;
}
