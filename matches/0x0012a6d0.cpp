#include "gen/fight.h"

extern "C" char DAT_0040fdf4[];
extern void* __cdecl alloc(unsigned int);
struct Target_12a6d0 {
    unsigned int vt;
    unsigned int a;
    unsigned int b;
    unsigned int zero;
    float angle;
};
struct Init_12a6d0 {
    void initialize(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetOrientationCondition>::vfunc_5() {
    Target_12a6d0* p = (Target_12a6d0*)alloc(0x14);
    if (p) {
        ((Init_12a6d0*)p)->initialize(0);
        p->vt = ((int)DAT_0040fdf4);
        p->zero = 0;
        p->angle = 3.1415927f;
        return (void*)(p);
    }
    return (void*)(0);
}
