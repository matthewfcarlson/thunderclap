extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class CMotionTrailAction {
  public:
    virtual void V0();
    virtual void V1();
    virtual CMotionTrailAction* vfunc_2(int);
    char pad[0x18];
    Ref* mRef;
};
extern void* CActionVftable;
class Helper {
  public:
    void Destroy();
};
void __cdecl thunk(CMotionTrailAction*);
CMotionTrailAction* CMotionTrailAction::vfunc_2(int flags) {
    *(void**)this = &CActionVftable;
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    ((Helper*)this)->Destroy();
    if (flags & 1)
        thunk(this);
    return this;
}
