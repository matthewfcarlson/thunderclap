class Base {
  public:
    virtual void Fn();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    char pad[0x18];
    Base* mRef;
    int mValue;
    int mOther;
};
class CSmartPropSpawnAction : public CAction {
  public:
    CSmartPropSpawnAction(int, Base*);
    virtual void A();
};
extern int vtAction;
extern int vtSpawn;
CSmartPropSpawnAction::CSmartPropSpawnAction(int value, Base* ref) {
    *(int*)this = (int)&vtAction;
    mRef = 0;
    if (ref)
        ref->Fn();
    if (mRef)
        mRef->Release();
    mRef = ref;
    mValue = value;
    *(int*)this = (int)&vtSpawn;
    mOther = 0;
}