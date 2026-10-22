class Target {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1fc60 {
  public:
    Action_1fc60();
    virtual void V();
};
class CAction : public Action_1fc60 {
  public:
    virtual void V();
    char pad[24];
    Target* target;
    int arg;
    int val;
    CAction(Target* t, int b) : Action_1fc60() {
        target = 0;
        if (t)
            t->Add();
        if (target)
            target->Release();
        target = t;
        val = b;
    }
};
class COrientTargetAction : public CAction {
  public:
    COrientTargetAction(int a, Target* t, int b);
    virtual void V();
    int zero;
};
COrientTargetAction::COrientTargetAction(int a, Target* t, int b) : CAction(t, b) {
    zero = 0;
    arg = a;
}