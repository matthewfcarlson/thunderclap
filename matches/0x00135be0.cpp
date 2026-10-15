class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Base {
  public:
    Base();
    virtual void Fn();
    char pad[24];
};
struct Fields {
    int val;
    Ref* ref;
    int a, b, c, d;
    Fields() {
        *(volatile int*)&val = 0;
        ref = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
};
class FlyingDashAction : public Base {
  public:
    FlyingDashAction(int, Ref*);
    virtual void Fn();
    Fields fields;
};
FlyingDashAction::FlyingDashAction(int x, Ref* p) : Base() {
    fields.val = x;
    if (p)
        p->Add();
    if (fields.ref)
        fields.ref->Release();
    fields.ref = p;
}