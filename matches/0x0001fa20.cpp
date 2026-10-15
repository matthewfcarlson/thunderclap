class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Root {
  public:
    Root();
    virtual void v0();
};
class CAction : public Root {
  public:
    CAction(Ref* r);
    virtual void v0();
    char pad[0x18];
    Ref* ref;
    int value;
};
class COrientAction : public CAction {
  public:
    COrientAction(int n, Ref* r);
    virtual void v0();
    int extra;
};
inline CAction::CAction(Ref* r) : Root() {
    ref = 0;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
}
COrientAction::COrientAction(int n, Ref* r) : CAction(r) {
    value = n;
    extra = 0;
}
