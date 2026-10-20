#include "compat/ptr.h"
class Arg_1d420 {
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
    CSweepAction(int value, Arg_1d420* arg);
    char pad[0x1c];
    Arg_1d420* mThing;
    int mValue;
    int mA;
    int mB;
};
CSweepAction::CSweepAction(int value, Arg_1d420* arg) : Ctor_00232660() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableAction;
    mThing = 0;
    if (arg)
        arg->F0();
    if (mThing)
        mThing->F1();
    mThing = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&vtableSweep;
    mA = 0;
    mB = 0;
}