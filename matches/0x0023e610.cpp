#include "compat/ptr.h"
class Ref_23e610 {
  public:
    virtual void Add();
    virtual void Release();
};
class Parent_23e610 {
  public:
    void Init();
};
extern int StopVtable;
class StopAction : public Parent_23e610 {
  public:
    char pad[0x1c];
    Ref_23e610* mRef;
    int mValue;
    int mArg;
    Ref_23e610* mOther;
    StopAction(Ref_23e610*, int, int, Ref_23e610*);
};
StopAction::StopAction(Ref_23e610* a, int b, int c, Ref_23e610* d) {
    Init();
    *(hulk_intptr*)this = (hulk_intptr)&StopVtable;
    mArg = c;
    mOther = 0;
    mRef = a;
    a->Add();
    mValue = b;
    if (d)
        d->Add();
    if (mOther)
        mOther->Release();
    mOther = d;
}