class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_12bff0 {
  public:
    Action_12bff0();
    virtual void f();
    char pad[24];
};
struct Fields {
    int a;
    Ref* p;
    int c;
    Fields() : a(0), p(0), c(0) {}
};
class ThreatBallAction : public Action_12bff0 {
  public:
    ThreatBallAction(int, Ref*);
    virtual void f();
    Fields m;
};
ThreatBallAction::ThreatBallAction(int v, Ref* q) : Action_12bff0() {
    m.a = v;
    if (q)
        q->Add();
    if (m.p)
        m.p->Release();
    m.p = q;
}