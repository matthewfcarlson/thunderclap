// Same code shape as 0x00018af0 (propagated; names are from that function)
class Ref_1764d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_1764d0 {
  public:
    virtual void V();
    Base_1764d0();
};
class TargetBreakAction_1764d0 : public Base_1764d0 {
  public:
    virtual void V2();
    char pad[0x18];
    Ref_1764d0* mRef;
    TargetBreakAction_1764d0(Ref_1764d0*);
};
TargetBreakAction_1764d0::TargetBreakAction_1764d0(Ref_1764d0* arg) : Base_1764d0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}