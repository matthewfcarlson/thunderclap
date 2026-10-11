class RefCounted {
  public:
    virtual void AddRef() throw() = 0;
    virtual void Release() throw() = 0;
};
class Base {
  public:
    Base() throw();
    virtual void BaseVirtual() throw();
    char pad[0x18];
};
class ChargeAction : public Base {
  public:
    ChargeAction(void* a, RefCounted* b) throw();
    virtual void V1() throw();
    void* mA;
    RefCounted* mB;
    int mC;
};
ChargeAction::ChargeAction(void* a, RefCounted* b) throw() {
    void** q = &mA;
    *q = 0;
    mB = 0;
    mC = 0;
    mA = a;
    if (b)
        b->AddRef();
    if (mB)
        mB->Release();
    mB = b;
}
