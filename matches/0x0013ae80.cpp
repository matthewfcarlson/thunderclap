class Ref {
  public:
    virtual void Fn0();
    virtual void Fn();
};
class Base {
  public:
    virtual void F();
    Base();
};
class AnimationPhaseMatchedAction : public Base {
  public:
    virtual void G();
    char pad04[0x18];
    int mA;
    Ref* mRef;
    int mC;
    AnimationPhaseMatchedAction(int a, Ref* r);
};
AnimationPhaseMatchedAction::AnimationPhaseMatchedAction(int a, Ref* r) : Base() {
    int* p = &mA;
    *p = 0;
    mRef = 0;
    mC = 0;
    mA = a;
    if (r)
        r->Fn0();
    if (mRef) {
        Ref* q = mRef;
        q->Fn();
    }
    mRef = r;
}