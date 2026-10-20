#include "compat/ptr.h"
class Actor_1f5d0 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f5d0* mActor;
};
class CIntangibleToActorsAction : public CAction {
  public:
    CIntangibleToActorsAction(Actor_1f5d0*);
    virtual void V1();
};
extern int vtAction;
extern int vtDerived;
CIntangibleToActorsAction::CIntangibleToActorsAction(Actor_1f5d0* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&vtDerived;
}
