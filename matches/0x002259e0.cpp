#include "decls/data/engine/choreo2.h"
// data: g_count_2259e0 = DAT_004e5ab4

#include "compat/ptr.h"
extern "C" char DAT_00427368[];
typedef unsigned char u8_2259e0;
struct Load {
    virtual void f0();
    virtual void f1();
};
struct AnimationDriver {
    void* vptr;
    char pad[0x1c];
    Load* member;
    void Cleanup();
    AnimationDriver* vfunc_2(u8_2259e0 flag);
};
void thunk(AnimationDriver*);
AnimationDriver* AnimationDriver::vfunc_2(u8_2259e0 flag) {
    this->vptr = (void*)((hulk_intptr)DAT_00427368);
    this->member->f1();
    --DAT_004e5ab4;
    this->Cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}
