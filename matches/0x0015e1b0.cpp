class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_15e1b0 {
  public:
    virtual void f();
    char pad[24];
    Action_15e1b0();
};
class LocomotionSprintAction : public Action_15e1b0 {
  public:
    int x;
    Ref* p;
    int a, b, c;
    LocomotionSprintAction(int, Ref*);
    virtual void f();
};
LocomotionSprintAction::LocomotionSprintAction(int v, Ref* q) : Action_15e1b0() {
    volatile int* px = &x;
    *px = 0;
    p = 0;
    a = 0;
    b = 0;
    c = 0;
    x = v;
    if (q)
        q->Add();
    if (p)
        p->Release();
    p = q;
}