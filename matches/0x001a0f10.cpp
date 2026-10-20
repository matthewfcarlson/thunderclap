#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041b2e8[];
extern void* operator_new(unsigned int);
struct Sub_1a0f10 {
    void Init();
};
struct MPT {
    hulk_intptr vf;
    int a;
    int b;
    int c;
    float z;
    float w;
    Sub_1a0f10 sub;
    void BaseInit();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_5() {
    MPT* p = (MPT*)operator_new(0x24);
    if (p) {
        p->BaseInit();
        p->vf = ((hulk_intptr)DAT_0041b2e8);
        p->c = 0;
        p->z = -1.0f;
        p->w = 6.2831855f;
        p->sub.Init();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
