#include "compat/ptr.h"
extern "C" char DAT_0042c8c4[];
struct Sub_289ea0 {
    void f();
};
class AnimationGroup {
  public:
    virtual AnimationGroup* vfunc_0(unsigned char);
    virtual void vfunc_1();
    char pad[4];
};
extern void __cdecl thunk_FUN_00267090(AnimationGroup*);
AnimationGroup* AnimationGroup::vfunc_0(unsigned char param_2) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8c4);
    AnimationGroup::vfunc_1();
    ((Sub_289ea0*)((char*)this + 8))->f();
    if (param_2 & 1)
        thunk_FUN_00267090(this);
    return this;
}
