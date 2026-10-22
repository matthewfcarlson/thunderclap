class RefCounted_1510f0 {
  public:
    virtual void AddRef() throw() = 0;
    virtual void Release() throw() = 0;
};
class Action_1510f0 {
  public:
    Action_1510f0() throw();
    virtual void BaseVirtual() throw();
    char pad[0x18];
};
class HitWaitAction : public Action_1510f0 {
  public:
    HitWaitAction(void* a, RefCounted_1510f0* b) throw();
    virtual void V1() throw();
    void* mA;
    RefCounted_1510f0* mB;
    int mC;
};
HitWaitAction::HitWaitAction(void* a, RefCounted_1510f0* b) throw() {
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
