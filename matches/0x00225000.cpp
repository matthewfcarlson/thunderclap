#include "compat/ptr.h"
extern "C" char DAT_00427368[];
struct Inner_225000 {
    virtual void A();
    virtual void B();
};
extern int gCount_225000;
struct AnimationDriver {
    void* vptr;
    char pad[0x1c];
    Inner_225000* mInner;
    void F();
    void Tail();
};
void AnimationDriver::F() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427368);
    mInner->B();
    --gCount_225000;
    Tail();
}