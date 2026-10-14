class Ref_148a60 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_148a60 {
  public:
    virtual void B();
    char pad[0x18];
    Base_148a60();
};
class Sub_148a60 {
  public:
    char pad[0x28];
    Sub_148a60();
};
class GrappleThrowAction : public Base_148a60 {
  public:
    virtual void V();
    int mA;
    Ref_148a60* mObj;
    Sub_148a60 sub;
    int mCount;
    char mFlag;
    GrappleThrowAction(int a, Ref_148a60* p);
};
GrappleThrowAction::GrappleThrowAction(int a, Ref_148a60* p) : Base_148a60(), mA(0), mObj(0), sub(), mCount(0), mFlag(0) {
    mA = a;
    if (p)
        p->AddRef();
    if (mObj)
        mObj->Release();
    mObj = p;
}
