// Same code shape as 0x00148840 (propagated; names are from that function)
class Ref_1518f0 {
  public:
    virtual void F();
    virtual void G();
};
class Root_1518f0 {
  public:
    virtual void V();
    Root_1518f0();
};
class Sub_1518f0 {
  public:
    Sub_1518f0();
    char pad[0x28];
};
class HitReactionFloatAction_1518f0 : public Root_1518f0 {
  public:
    char pad[0x18];
    int* mA;
    Ref_1518f0* mB;
    Sub_1518f0 sub;
    int x;
    int y;
    unsigned char z;
    HitReactionFloatAction_1518f0(int* a, Ref_1518f0* b);
};
HitReactionFloatAction_1518f0::HitReactionFloatAction_1518f0(int* a, Ref_1518f0* b) : mA(0), mB(0), sub() {
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
