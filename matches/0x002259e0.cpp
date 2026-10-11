extern "C" char DAT_00427368[];
typedef unsigned char u8;
struct Load {
    virtual void f0();
    virtual void f1();
};
struct AnimationDriver {
    void* vptr;
    char pad[0x1c];
    Load* member;
    void Cleanup();
    AnimationDriver* vfunc_2(u8 flag);
};
extern int g_count;
void thunk(AnimationDriver*);
AnimationDriver* AnimationDriver::vfunc_2(u8 flag) {
    this->vptr = (void*)((int)DAT_00427368);
    this->member->f1();
    --g_count;
    this->Cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}
