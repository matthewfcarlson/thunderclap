#include "compat/ptr.h"
class Ref_15d460 {
  public:
    virtual void A();
    virtual void B();
};
extern int vtable_15d460;
struct Action_15d460 {
    void InitBase();
};
struct LocomotionStrafeAction : Action_15d460 {
    char pad[0x1c];
    Ref_15d460* mRef;
    int mOther;
    LocomotionStrafeAction* Init(Ref_15d460*);
};
LocomotionStrafeAction* LocomotionStrafeAction::Init(Ref_15d460* p) {
    InitBase();
    *(hulk_intptr*)this = (hulk_intptr)&vtable_15d460;
    mRef = 0;
    mOther = 0;
    if (p)
        p->A();
    if (mRef)
        mRef->B();
    mRef = p;
    return this;
}