#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041d3ec[];
struct Obj_1ac6a0 {
    unsigned int vt;
    char pad[8];
    int value;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::EventCondition>::vfunc_5() {
    Obj_1ac6a0* p = (Obj_1ac6a0*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_0041d3ec);
        p->value = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
