extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c8e8[];
extern "C" void _ReadWriteBarrier();
typedef unsigned char byte;
struct Ref {
    virtual void a();
    virtual void release();
};
struct AnimationLoader {
    virtual void v0();
    virtual void v1();
    virtual AnimationLoader* vfunc_2(byte);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad18[0x10];
    Ref* mRef;
};
extern void destroy(AnimationLoader*);
AnimationLoader* AnimationLoader::vfunc_2(byte flags) {
    *(void**)this = (void*)((int)DAT_0042c8e8);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->release();
        mRef = 0;
    }
    *(void**)this = (void*)((int)DAT_003f6098);
    if (flags & 1)
        destroy(this);
    return this;
}