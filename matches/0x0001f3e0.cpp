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
class CAction : public Root {
  public:
    CAction(Ref* r, int b);
    virtual void Run();
    Ref* ref;
    int x;
};
class CSmartPropEventAction : public CAction {
  public:
    CSmartPropEventAction(Ref* r, int a, int b);
    virtual void Run();
    int y;
};
CAction::CAction(Ref* r, int b) {
    ref = 0;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
    x = b;
}
CSmartPropEventAction::CSmartPropEventAction(Ref* r, int a, int b) : CAction(r, b) {
    y = a;
}