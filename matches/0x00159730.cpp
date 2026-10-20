#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414110[];
extern "C" void* __cdecl alloc(unsigned int);
struct Obj_159730 {
    int vf;
    char pad[8];
    char flag;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_5() {
    Obj_159730* p = (Obj_159730*)alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((hulk_intptr)DAT_00414110);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
