#include "gen/fight.h"

class ConditionFactoryCaster_1a6a20 {
  public:
    virtual int check(const char*);
    virtual void other();
};
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_004c1f20;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_00491ca8, &DAT_004c1f20, 0) != 0;
}
