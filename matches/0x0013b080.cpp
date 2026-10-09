class Base {
  public:
    Base();
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    virtual void A();
    virtual void B();
};
class AnimationVelocityScaledAction : public Base {
  public:
    int p[6];
    int mArg;
    Owner* mOwner;
    int mValue;
    AnimationVelocityScaledAction(int, Owner*);
};
AnimationVelocityScaledAction::AnimationVelocityScaledAction(int x, Owner* o) : Base() {
    int* q = &mArg;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    mArg = x;
    if (o)
        o->A();
    if (mOwner)
        mOwner->B();
    mOwner = o;
}
