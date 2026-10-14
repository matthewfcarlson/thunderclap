class Base_152480 {
  public:
    virtual void X();
    Base_152480();
};
class Other_152480 {
  public:
    virtual void Fn();
    virtual void Fn2();
};
extern int vt_152480;
class Action : public Base_152480 {
  public:
    Action(int a, Other_152480* b);
    virtual void V0();
    char pad[0x18];
    int mValue;
    Other_152480* mOther;
    int mUnused;
};
void Action::V0() {}
Action::Action(int a, Other_152480* b) : Base_152480() {
    *(int*)this = (int)&vt_152480;
    volatile int* p = &mValue;
    *p = 0;
    mOther = 0;
    mUnused = 0;
    mValue = a;
    if (b)
        b->Fn();
    if (mOther)
        mOther->Fn2();
    mOther = b;
}
