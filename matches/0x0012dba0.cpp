extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f();
    virtual void Release();
};
class Base {
  public:
    virtual void Dummy();
    void Finish();
};
class PostEvent_StringAction : public Base {
  public:
    void Clean();
    char pad0[0x20 - 4];
    Ref* mRef;
};
void PostEvent_StringAction::Clean() {
    *(void**)this = (void*)0x411110;
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    Finish();
}
