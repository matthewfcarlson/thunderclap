extern "C" char DAT_003f3390[];
extern "C" void _ReadWriteBarrier();
class Ref_224a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class CUninterruptibleAction {
  public:
    volatile int vptr;
    char pad[0x18];
    volatile Ref_224a0* mRef;
    CUninterruptibleAction* f2(unsigned char flags);
    void Cleanup();
};
extern void __cdecl thunk_FUN_00267090(CUninterruptibleAction*);
CUninterruptibleAction* CUninterruptibleAction::f2(unsigned char flags) {
    vptr = ((int)DAT_003f3390);
    _ReadWriteBarrier();
    if (mRef) {
        ((Ref_224a0*)mRef)->Release();
        mRef = 0;
    }
    Cleanup();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}