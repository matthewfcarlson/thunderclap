class Ref_18af0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_18af0 {
  public:
    virtual void V();
    Action_18af0();
};
class CAction : public Action_18af0 {
  public:
    virtual void V2();
    char pad[0x18];
    Ref_18af0* mRef;
    CAction(Ref_18af0*);
};
CAction::CAction(Ref_18af0* arg) : Action_18af0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}