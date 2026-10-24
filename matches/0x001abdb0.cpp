#include "gen/fight.h"

class ConditionFactoryCaster_1abdb0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004c3430;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3430, 0) != 0;
}
