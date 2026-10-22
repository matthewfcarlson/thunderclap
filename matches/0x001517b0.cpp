// Same code shape as 0x00148840 (propagated; names are from that function)
class Ref_1517b0 {
  public:
    virtual void F();
    virtual void G();
};
class Action_1517b0 {
  public:
    virtual void V();
    Action_1517b0();
};
class Sub_1517b0 {
  public:
    Sub_1517b0();
    char pad[0x28];
};
class HitReactionAction_1517b0 : public Action_1517b0 {
  public:
    char pad[0x18];
    int* mA;
    Ref_1517b0* mB;
    Sub_1517b0 sub;
    int x;
    int y;
    unsigned char z;
    HitReactionAction_1517b0(int* a, Ref_1517b0* b);
};
HitReactionAction_1517b0::HitReactionAction_1517b0(int* a, Ref_1517b0* b) : mA(0), mB(0), sub() {
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
