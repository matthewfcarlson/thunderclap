#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"

extern "C" char DAT_00428afc[];
class Sub_23d360 {
  public:
};
class Obj_23d360 {
  public:
    void Init();
    char pad[8];
    Sub_23d360 sub;
};
extern void* __cdecl alloc(hulk_uintptr);
class FactoryBase {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class Caster_23d360 : public FactoryBase {
  public:
    char pad[4];
};

template <> void* fight::ConditionFactoryCasterTemplate<fight::FalseCondition>::vfunc_1(void* __p0) { void * a = (void *)__p0;

    Obj_23d360* p = (Obj_23d360*)alloc(16);
    if (p) {
        p->Init();
        *((void**)p) = (void*)((hulk_intptr)DAT_00428afc);
        ((owners::Target_27b040 *)&(p->sub))->FUN_0027b040((hulk_uintptr)a);
        return (void*)(p);
    }
    return (void*)(0);
}
