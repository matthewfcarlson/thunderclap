class Base_13b080 {
  public:
    Base_13b080();
    virtual void A();
    virtual void B();
};
class Owner_13b080 {
  public:
    virtual void A();
    virtual void B();
};
class AnimationVelocityScaledAction : public Base_13b080 {
  public:
    int p[6];
    int mArg;
    Owner_13b080* mOwner;
    int mValue;
    AnimationVelocityScaledAction(int, Owner_13b080*);
};
AnimationVelocityScaledAction::AnimationVelocityScaledAction(int x, Owner_13b080* o) : Base_13b080() {
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
