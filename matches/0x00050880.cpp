#include "gen/fight.h"

extern char DAT_00491ca8;
extern char DAT_004925f8;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_50880 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CCharacterTemplateVariationCondition_50880;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004925f8, 0) != 0;
}
