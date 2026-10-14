class Arg_1d420 {
  public:
    virtual void F0();
    virtual void F1();
};
extern int vtableAction;
extern int vtableSweep;
void __cdecl FUN_00232660();
class CSweepAction {
  public:
    CSweepAction(int value, Arg_1d420* arg);
    char pad[0x1c];
    Arg_1d420* mThing;
    int mValue;
    int mA;
    int mB;
};
CSweepAction::CSweepAction(int value, Arg_1d420* arg) {
    FUN_00232660();
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