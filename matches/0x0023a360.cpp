extern "C" void _ReadWriteBarrier();
class IRef {
  public:
    virtual void f0();
    virtual void Release();
};
class Member {
  public:
    void dtor();
    char x;
};
extern char vft_428558[];
void __cdecl opDelete(void*);
class QueuedNodeAction {
  public:
    void* vptr;
    QueuedNodeAction* vfunc_2(int flag);
    void baseCleanup();
    char pad1[0x18];
    IRef* mA;
    char pad2[8];
    IRef* mB;
    Member mC;
};
QueuedNodeAction* QueuedNodeAction::vfunc_2(int flag) {
    vptr = vft_428558;
    _ReadWriteBarrier();
    if (mB) {
        mB->Release();
        mB = 0;
    }
    if (mA) {
        mA->Release();
        mA = 0;
    }
    mC.dtor();
    baseCleanup();
    if (flag & 1)
        opDelete(this);
    return this;
}
