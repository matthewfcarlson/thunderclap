extern "C" char DAT_003f3390[];
extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void F();
    virtual void Release();
};
class CSmartPropThrowingAction {
  public:
    volatile int vptr;
    char pad[0x18];
    Ref* member;
    CSmartPropThrowingAction* V2(int);
};
class Helper {
  public:
    void Go();
};
extern void thunk_FUN_00267090(CSmartPropThrowingAction*);
CSmartPropThrowingAction* CSmartPropThrowingAction::V2(int flag) {
    vptr = ((int)DAT_003f3390);
    _ReadWriteBarrier();
    if (member) {
        member->Release();
        member = 0;
    }
    ((Helper*)this)->Go();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}