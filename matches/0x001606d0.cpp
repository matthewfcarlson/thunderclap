// Same code shape as 0x00018af0 (propagated; names are from that function)
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    virtual void V();
    Base();
};
class CAction : public Base {
  public:
    virtual void V2();
    char pad[0x18];
    Ref* mRef;
    CAction(Ref*);
};
CAction::CAction(Ref* arg) : Base() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}