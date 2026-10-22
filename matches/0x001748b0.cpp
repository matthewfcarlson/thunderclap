class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1748b0 {
  public:
    virtual void dummy();
    char pad[24];
    Action_1748b0();
};
struct Group {
    Ref* a;
    Ref* b;
    Ref* c;
    Group() : a(0), b(0), c(0) {}
};
class PushOutAction : public Action_1748b0 {
  public:
    Group g;
    PushOutAction(int, Ref*);
    virtual void dummy();
};
PushOutAction::PushOutAction(int x, Ref* p) {
    g.a = (Ref*)x;
    if (p)
        p->Add();
    if (g.b)
        g.b->Release();
    g.b = p;
}