extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class Base {
  public:
    virtual void A();
    virtual void B();
    void Finish();
};
extern void* vtable[];
class AIHistorySetAction : public Base {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    Ref* mRef;
    Ref* mAction;
    void Clean();
};
void AIHistorySetAction::Clean() {
    *(void**)this = vtable;
    _ReadWriteBarrier();
    if (mAction) {
        mAction->Release();
        mAction = 0;
    }
    if (mRef)
        mRef = 0;
    ((Base*)this)->Finish();
}