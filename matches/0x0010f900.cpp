extern "C" void _ReadWriteBarrier();
class Ref_10f900 {
  public:
    virtual void A();
    virtual void Release();
};
class Base_10f900 {
  public:
    virtual void A();
    virtual void B();
    void Finish();
};
extern void* vtable_10f900[];
class AIHistorySetAction : public Base_10f900 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    Ref_10f900* mRef;
    Ref_10f900* mAction;
    void Clean();
};
void AIHistorySetAction::Clean() {
    *(void**)this = vtable_10f900;
    _ReadWriteBarrier();
    if (mAction) {
        mAction->Release();
        mAction = 0;
    }
    if (mRef)
        mRef = 0;
    ((Base_10f900*)this)->Finish();
}