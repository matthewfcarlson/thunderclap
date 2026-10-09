class Arg {
  public:
    virtual void AddRef();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    int vf;
    char pad[0x18];
    Arg* mArg;
};
class CDeathAction : public CAction {
  public:
    CDeathAction(Arg*);
};
CDeathAction::CDeathAction(Arg* a) {
    vf = 0x3f3390;
    mArg = 0;
    if (a)
        a->AddRef();
    if (mArg)
        mArg->Release();
    mArg = a;
    vf = 0x3f3ce0;
}
