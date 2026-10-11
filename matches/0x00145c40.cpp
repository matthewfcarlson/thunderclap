extern "C" void _ReadWriteBarrier();
typedef unsigned int u32;
struct SlowMotionAction {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual SlowMotionAction* vfunc_2(unsigned char flags);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[0x18];
    u32 member;
    void helper();
};
void destroy(SlowMotionAction* p);
SlowMotionAction* SlowMotionAction::vfunc_2(unsigned char flags) {
    *(void**)this = (void*)0x41306c;
    _ReadWriteBarrier();
    if (member)
        member = 0;
    helper();
    if (flags & 1)
        destroy(this);
    return this;
}
