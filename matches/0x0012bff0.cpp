class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Base {
  public:
    Base();
    virtual void f();
    char pad[24];
};
struct Fields {
    int a;
    Ref* p;
    int c;
    Fields() : a(0), p(0), c(0) {}
};
class ThreatBallAction : public Base {
  public:
    ThreatBallAction(int, Ref*);
    virtual void f();
    Fields m;
};
ThreatBallAction::ThreatBallAction(int v, Ref* q) : Base() {
    m.a = v;
    if (q)
        q->Add();
    if (m.p)
        m.p->Release();
    m.p = q;
}