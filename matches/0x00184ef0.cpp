class Ref_184ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_184ef0 {
  public:
    Action_184ef0();
    virtual void V0();
    char pad[0x18];
};
class BallAndChainReturnAction_184ef0 : public Action_184ef0 {
  public:
    int mArg;
    Ref_184ef0* mRef;
    int x24, x28, x2c, x30, x34;
    float x38;
    int x3c, x40, x44;
    BallAndChainReturnAction_184ef0(int, Ref_184ef0*);
    virtual void V0();
};
BallAndChainReturnAction_184ef0::BallAndChainReturnAction_184ef0(int a, Ref_184ef0* b) : Action_184ef0() {
    int* q = &mArg;
    *q = 0;
    mRef = 0;
    x24 = 0;
    x28 = 0;
    x2c = 0;
    x30 = 0;
    x34 = 0;
    x38 = -1.0f;
    x3c = 0;
    x40 = 0;
    x44 = 0;
    mArg = a;
    if (b)
        b->A();
    if (mRef)
        mRef->B();
    mRef = b;
}
