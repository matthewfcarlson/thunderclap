class Base {
  public:
    virtual void X();
    Base();
};
class Other {
  public:
    virtual void Fn();
    virtual void Fn2();
};
extern int vt;
class Action : public Base {
  public:
    Action(int a, Other* b);
    virtual void V0();
    char pad[0x18];
    int mValue;
    Other* mOther;
    int mUnused;
};
void Action::V0() {}
Action::Action(int a, Other* b) : Base() {
    *(int*)this = (int)&vt;
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
