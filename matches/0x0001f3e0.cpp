class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Root {
  public:
    Root();
    virtual void Run();
    char pad[24];
};
class CSmartPropEventAction_1f3e0 : public Root {
  public:
    CSmartPropEventAction_1f3e0(Ref* r, int b);
    virtual void Run();
    Ref* ref;
    int x;
};
class CSmartPropEventAction : public CSmartPropEventAction_1f3e0 {
  public:
    CSmartPropEventAction(Ref* r, int a, int b);
    virtual void Run();
    int y;
};
CSmartPropEventAction_1f3e0::CSmartPropEventAction_1f3e0(Ref* r, int b) {
    ref = 0;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
    x = b;
}
CSmartPropEventAction::CSmartPropEventAction(Ref* r, int a, int b) : CSmartPropEventAction_1f3e0(r, b) {
    y = a;
}