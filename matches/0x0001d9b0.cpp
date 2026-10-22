class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1d9b0 {
  public:
    Action_1d9b0();
    virtual void f();
};
class CAction : public Action_1d9b0 {
  public:
    CAction(Ref* p, int x) : ref(0) {
        if (p)
            p->AddRef();
        if (ref)
            ref->Release();
        ref = p;
        a = x;
    }
    virtual void f();
    char pad[24];
    Ref* ref;
    int a;
    int b;
};
class CDamageAction : public CAction {
  public:
    CDamageAction(Ref*, int, int);
    virtual void f();
};
CDamageAction::CDamageAction(Ref* p, int x, int y) : CAction(p, x) {
    b = y;
}