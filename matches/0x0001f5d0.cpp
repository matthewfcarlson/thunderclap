class Actor {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor* mActor;
};
class CIntangibleToActorsAction : public CAction {
  public:
    CIntangibleToActorsAction(Actor*);
    virtual void V1();
};
extern int vtAction;
extern int vtDerived;
CIntangibleToActorsAction::CIntangibleToActorsAction(Actor* a) {
    *(int*)this = (int)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(int*)this = (int)&vtDerived;
}
