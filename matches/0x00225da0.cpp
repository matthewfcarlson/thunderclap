#include "decls/data/engine/choreo2.h"
// data: gCount_225da0 = DAT_004e5ab4

#include "compat/ptr.h"
extern "C" char DAT_00427368[];
extern "C" void* __cdecl alloc(hulk_uintptr);
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
        ++DAT_004e5ab4;
        if (DAT_004e5ab4 > DAT_004e5ab8)
            DAT_004e5ab8 = DAT_004e5ab4;
        return p;
    }
    return 0;
}