#include "compat/ptr.h"
class Ref_1d100 {
  public:
    virtual void A();
    virtual void B();
};
extern int actionVftable;
extern int keyVftable;
class Action {
  public:
    Action();
    virtual void A();
    virtual void B();
    char pad[0x18];
    Ref_1d100* mRef;
    int mValue;
    int m9;
    int m10;
    int m11;
};
class CKeyPoseAction_1d100 : public Action {
  public:
    CKeyPoseAction_1d100(int, Ref_1d100*);
    virtual void A();
};
CKeyPoseAction_1d100::CKeyPoseAction_1d100(int value, Ref_1d100* ref) : Action() {
    *(hulk_intptr*)this = (hulk_intptr)&actionVftable;
    mRef = 0;
    if (ref)
        ref->A();
    if (mRef)
        mRef->B();
    mRef = ref;
    mValue = value;
    m9 = 0;
    m10 = 0;
    m11 = 0;
    *(hulk_intptr*)this = (hulk_intptr)&keyVftable;
}