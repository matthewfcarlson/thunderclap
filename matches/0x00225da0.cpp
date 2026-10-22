#include "compat/ptr.h"
extern "C" char DAT_00427368[];
extern "C" void* __cdecl alloc(hulk_uintptr);
int gCount_225da0;
int gMax_225da0;
struct AnimationDriver_225da0 {
    hulk_intptr v;
    void InitA(void*);
    void InitB(void*);
};
struct Factory_225da0 {
    AnimationDriver_225da0* Make();
};
AnimationDriver_225da0* Factory_225da0::Make() {
    AnimationDriver_225da0* p = (AnimationDriver_225da0*)alloc(0x240);
    if (p != 0) {
        p->InitA(this);
        p->v = ((hulk_intptr)DAT_00427368);
        p->InitB(this);
        ++gCount_225da0;
        if (gCount_225da0 > gMax_225da0)
            gMax_225da0 = gCount_225da0;
        return p;
    }
    return 0;
}