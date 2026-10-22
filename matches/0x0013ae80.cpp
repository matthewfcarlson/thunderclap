class Ref_13ae80 {
  public:
    virtual void Fn0();
    virtual void Fn();
};
class Action_13ae80 {
  public:
    virtual void F();
    Action_13ae80();
};
class AnimationPhaseMatchedAction : public Action_13ae80 {
  public:
    virtual void G();
    char pad04[0x18];
    int mA;
    Ref_13ae80* mRef;
    int mC;
    AnimationPhaseMatchedAction(int a, Ref_13ae80* r);
};
AnimationPhaseMatchedAction::AnimationPhaseMatchedAction(int a, Ref_13ae80* r) : Action_13ae80() {
    int* p = &mA;
    *p = 0;
    mRef = 0;
    mC = 0;
    mA = a;
    if (r)
        r->Fn0();
    if (mRef) {
        Ref_13ae80* q = mRef;
        q->Fn();
    }
    mRef = r;
}