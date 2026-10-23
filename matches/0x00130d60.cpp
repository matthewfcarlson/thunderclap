#include "gen/fight.h"

class ConditionFactoryCaster_130d60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class GameStateCondition_130d60 {};
extern void* gA;
extern void* gB;
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::GameStateCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &gA, &gB, 0) != 0;
}
