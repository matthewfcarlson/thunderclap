class Action_151de0 {
  public:
    Action_151de0();
    virtual void f();
    char pad[24];
};
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
struct Value {
    volatile int v;
    Value() : v(0) {}
    void Set(int x) { v = x; }
};
class HitFloatAction : public Action_151de0 {
  public:
    HitFloatAction(int, Ref*);
    virtual void f();
    Value a;
    Ref* b;
    int c, d, e, f0, g;
};
HitFloatAction::HitFloatAction(int x, Ref* r) : Action_151de0(), b(0), c(0), d(0), e(0), f0(0), g(0) {
    a.Set(x);
    if (r)
        r->Add();
    if (b)
        b->Release();
    b = r;
}