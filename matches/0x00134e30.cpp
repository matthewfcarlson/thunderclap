class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    virtual void fn();
    char pad[24];
    Base();
};
struct Fields {
    volatile int a;
    Ref* ref;
    int c, d, e, f, g;
    Fields() : a(0), ref(0), c(0), d(0), e(0), f(0), g(0) {}
};
class FallAction : public Base {
  public:
    Fields fields;
    FallAction(int, Ref*);
    virtual void fn();
};
FallAction::FallAction(int v, Ref* p) : Base(), fields() {
    fields.a = v;
    if (p)
        p->AddRef();
    if (fields.ref)
        fields.ref->Release();
    fields.ref = p;
}