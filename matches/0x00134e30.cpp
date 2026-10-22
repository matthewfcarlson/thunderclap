class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_134e30 {
  public:
    virtual void fn();
    char pad[24];
    Action_134e30();
};
struct Fields {
    volatile int a;
    Ref* ref;
    int c, d, e, f, g;
    Fields() : a(0), ref(0), c(0), d(0), e(0), f(0), g(0) {}
};
class FallAction : public Action_134e30 {
  public:
    Fields fields;
    FallAction(int, Ref*);
    virtual void fn();
};
FallAction::FallAction(int v, Ref* p) : Action_134e30(), fields() {
    fields.a = v;
    if (p)
        p->AddRef();
    if (fields.ref)
        fields.ref->Release();
    fields.ref = p;
}