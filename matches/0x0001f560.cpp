// Same code shape as 0x0001f5d0 (propagated; names are from that function)
#include "compat/ptr.h"
class Actor_1f560 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f560* mActor;
};
class CIntangibleAction_1f560 : public CAction {
  public:
    CIntangibleAction_1f560(Actor_1f560*);
    virtual void V1();
};
extern int vtAction;
extern int vtDerived;
CIntangibleAction_1f560::CIntangibleAction_1f560(Actor_1f560* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&vtDerived;
}
