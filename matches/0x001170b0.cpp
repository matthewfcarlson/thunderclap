class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1170b0 {
  public:
    Action_1170b0();
    virtual void Fn();
    char pad[24];
};
struct Triple {
    int a;
    Ref* p;
    int b;
    Triple() : a(0), p(0), b(0) {}
    void Set(Ref* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
class MotionBoostAction : public Action_1170b0 {
  public:
    MotionBoostAction(int, Ref*);
    virtual void Fn();
    Triple t;
    int c;
    int d;
    int e;
};
MotionBoostAction::MotionBoostAction(int x, Ref* r) : Action_1170b0() {
    t.a = x;
    t.Set(r);
    e = 0;
    d = 0;
    c = 0;
}