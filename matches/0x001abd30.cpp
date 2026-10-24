#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
class ConditionFactoryCaster_1abd30 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class Event_CharacterTemplateCondition_1abd30;
extern char DAT_00491ca8;
extern char DAT_004c3350;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3350, 0) != 0;
}
