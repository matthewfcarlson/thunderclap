extern "C" void _ReadWriteBarrier();
struct RelObj {
  public:
    virtual void A();
    virtual void Release();
};
extern "C" void __cdecl freeA(void*);
extern "C" void __cdecl freeB(void*);
extern void* FEAnimation_vftable;

class FEAnimation {
  public:
    virtual FEAnimation* vfunc_0(unsigned char param);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    void* mPtr;
    char pad[4];
    RelObj* mRel;
};

FEAnimation* FEAnimation::vfunc_0(unsigned char param) {
    *(void**)this = &FEAnimation_vftable;
    _ReadWriteBarrier();
    if (mRel != 0) {
        mRel->Release();
        mRel = 0;
    }
    if (mPtr != 0) {
        freeA(mPtr);
        mPtr = 0;
    }
    if (param & 1) {
        freeB(this);
    }
    return this;
}
