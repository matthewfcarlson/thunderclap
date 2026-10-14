class Thing_15eb20 {
  public:
    virtual void A();
    virtual void B();
};
class Base_15eb20 {
  public:
    virtual void X();
    Base_15eb20();
};
class ClimbLocomotionAction : public Base_15eb20 {
  public:
    virtual void A();
    char pad[0x18];
    Thing_15eb20* mThing;
    int m20;
    int m24;
    ClimbLocomotionAction(Thing_15eb20*);
};
ClimbLocomotionAction::ClimbLocomotionAction(Thing_15eb20* p) {
    mThing = 0;
    m20 = 0;
    m24 = 0;
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
