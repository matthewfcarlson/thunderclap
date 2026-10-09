class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    virtual void B();
    char pad[0x18];
    Base();
};
class Sub {
  public:
    char pad[0x28];
    Sub();
};
class GrappleThrowAction : public Base {
  public:
    virtual void V();
    int mA;
    Ref* mObj;
    Sub sub;
    int mCount;
    char mFlag;
    GrappleThrowAction(int a, Ref* p);
};
GrappleThrowAction::GrappleThrowAction(int a, Ref* p) : Base(), mA(0), mObj(0), sub(), mCount(0), mFlag(0) {
    mA = a;
    if (p)
        p->AddRef();
    if (mObj)
        mObj->Release();
    mObj = p;
}
