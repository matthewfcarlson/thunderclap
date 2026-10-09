class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    Base();
    virtual void X();
    virtual void Y();
};
class FlyingBrakeAction : public Base {
  public:
    FlyingBrakeAction(void* p, Thing* t);
    char pad[0x1c - 4];
    int mF[9];
};
FlyingBrakeAction::FlyingBrakeAction(void* p, Thing* t) : Base() {
    int i;
    for (i = 0; i < 9; i++)
        mF[i] = 0;
    mF[0] = (int)p;
    if (t)
        t->A();
    if (mF[1])
        ((Thing*)mF[1])->B();
    mF[1] = (int)t;
}
