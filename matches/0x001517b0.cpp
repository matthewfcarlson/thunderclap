// Same code shape as 0x00148840 (propagated; names are from that function)
class Ref {
  public:
    virtual void F();
    virtual void G();
};
class Root {
  public:
    virtual void V();
    Root();
};
class Sub {
  public:
    Sub();
    char pad[0x28];
};
class Action : public Root {
  public:
    char pad[0x18];
    int* mA;
    Ref* mB;
    Sub sub;
    int x;
    int y;
    unsigned char z;
    Action(int* a, Ref* b);
};
Action::Action(int* a, Ref* b) : mA(0), mB(0), sub() {
    x = 0;
    y = 0;
    z = 0;
    mA = a;
    if (b)
        b->F();
    if (mB)
        mB->G();
    mB = b;
}
