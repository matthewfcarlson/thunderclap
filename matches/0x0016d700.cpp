#include "gen/fight.h"

struct Turning {
    int vptr;
    int x;
    int y;
    int z;
    int w;
    void Init(int);
};
extern "C" void* __cdecl Alloc(unsigned int);
extern int turning_vftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_5() {
    Turning* p = (Turning*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (int)&turning_vftable;
        p->z = 0;
        p->w = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
