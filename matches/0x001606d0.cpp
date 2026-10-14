// Same code shape as 0x00018af0 (propagated; names are from that function)
class Ref_1606d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_1606d0 {
  public:
    virtual void V();
    Base_1606d0();
};
class CAction : public Base_1606d0 {
  public:
    virtual void V2();
    char pad[0x18];
    Ref_1606d0* mRef;
    CAction(Ref_1606d0*);
};
CAction::CAction(Ref_1606d0* arg) : Base_1606d0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}