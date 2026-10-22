class Action_11dd10 {
  public:
    Action_11dd10();
    virtual void Fn();
    virtual void Release();
};
class StrafeCircleHBAction : public Action_11dd10 {
  public:
    char pad[0x1c - 4];
    int mArg;
    Action_11dd10* mObj;
    int mOther;
    StrafeCircleHBAction(int a, Action_11dd10* b);
};
StrafeCircleHBAction::StrafeCircleHBAction(int a, Action_11dd10* b) : Action_11dd10() {
    int* q = &mArg;
    *q = 0;
    mObj = 0;
    mOther = 0;
    mArg = a;
    if (b)
        b->Fn();
    if (mObj)
        mObj->Release();
    mObj = b;
}