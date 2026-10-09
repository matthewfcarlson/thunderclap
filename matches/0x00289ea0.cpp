struct Sub { void f(); };
class AnimationGroup {
public:
    virtual AnimationGroup* vfunc_0(unsigned char);
    virtual void vfunc_1();
    char pad[4];
};
extern void __cdecl thunk_FUN_00267090(AnimationGroup*);
AnimationGroup* AnimationGroup::vfunc_0(unsigned char param_2) {
    *(void**)this = (void*)0x42c8c4;
    AnimationGroup::vfunc_1();
    ((Sub*)((char*)this + 8))->f();
    if (param_2 & 1) thunk_FUN_00267090(this);
    return this;
}
