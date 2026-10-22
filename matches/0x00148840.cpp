class Ref_148840 {
  public:
    virtual void F();
    virtual void G();
};
class Action_148840 {
  public:
    virtual void V();
    Action_148840();
};
class Sub_148840 {
  public:
    Sub_148840();
    char pad[0x28];
};
class GrappleHitReactionAction_148840 : public Action_148840 {
  public:
    char pad[0x18];
    int* mA;
    Ref_148840* mB;
    Sub_148840 sub;
    int x;
    int y;
    unsigned char z;
    GrappleHitReactionAction_148840(int* a, Ref_148840* b);
};
GrappleHitReactionAction_148840::GrappleHitReactionAction_148840(int* a, Ref_148840* b) : mA(0), mB(0), sub() {
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
