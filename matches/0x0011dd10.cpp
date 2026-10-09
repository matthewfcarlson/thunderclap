class Base {
  public:
    Base();
    virtual void Fn();
    virtual void Release();
};
class StrafeCircleHBAction : public Base {
  public:
    char pad[0x1c - 4];
    int mArg;
    Base* mObj;
    int mOther;
    StrafeCircleHBAction(int a, Base* b);
};
StrafeCircleHBAction::StrafeCircleHBAction(int a, Base* b) : Base() {
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