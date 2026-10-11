class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    Base();
    virtual void V0();
    char pad[0x18];
};
class Action : public Base {
  public:
    int mArg;
    Ref* mRef;
    int x24, x28, x2c, x30, x34;
    float x38;
    int x3c, x40, x44;
    Action(int, Ref*);
    virtual void V0();
};
Action::Action(int a, Ref* b) : Base() {
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
