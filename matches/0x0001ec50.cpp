// Same code shape as 0x0001d420 (propagated; names are from that function)
class Arg_1ec50 {
  public:
    virtual void F0();
    virtual void F1();
};
extern int vtableAction;
extern int vtableSweep;
struct Ctor_00232660 {
    Ctor_00232660();
};
class CSweepAction : public Ctor_00232660 {
  public:
    CSweepAction(int value, Arg_1ec50* arg);
    char pad[0x1c];
    Arg_1ec50* mThing;
    int mValue;
    int mA;
    int mB;
};
CSweepAction::CSweepAction(int value, Arg_1ec50* arg) : Ctor_00232660() {
    *(int*)this = (int)&vtableAction;
    mThing = 0;
    if (arg)
        arg->F0();
    if (mThing)
        mThing->F1();
    mThing = arg;
    mValue = value;
    *(int*)this = (int)&vtableSweep;
    mA = 0;
    mB = 0;
}