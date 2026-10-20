// Same code shape as 0x0001f5d0 (propagated; names are from that function)
#include "compat/ptr.h"
class Actor_1f1f0 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f1f0* mActor;
};
class CSmartPropDetachAction_1f1f0 : public CAction {
  public:
    CSmartPropDetachAction_1f1f0(Actor_1f1f0*);
    virtual void V1();
};
extern int vtAction;
extern int vtDerived;
CSmartPropDetachAction_1f1f0::CSmartPropDetachAction_1f1f0(Actor_1f1f0* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&vtDerived;
}
