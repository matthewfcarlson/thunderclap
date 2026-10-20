#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c8e8[];
extern "C" void _ReadWriteBarrier();
typedef unsigned char byte_289e60;
struct Ref_289e60 {
    virtual void a();
    virtual void release();
};
struct AnimationLoader {
    virtual void v0();
    virtual void v1();
    virtual AnimationLoader* vfunc_2(byte_289e60);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad18[0x10];
    Ref_289e60* mRef;
};
extern void destroy(AnimationLoader*);
AnimationLoader* AnimationLoader::vfunc_2(byte_289e60 flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8e8);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->release();
        mRef = 0;
    }
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        destroy(this);
    return this;
}