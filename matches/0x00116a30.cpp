class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    volatile int v;
    Base();
};
class MotionTargetAction : public Base {
  public:
    char pad[24];
    volatile int a;
    Ref* b;
    int c;
    MotionTargetAction(int x, Ref* r);
};
MotionTargetAction::MotionTargetAction(int x, Ref* r) : Base() {
    v = 0x40ecd8;
    a = 0;
    b = 0;
    c = 0;
    a = x;
    if (r)
        r->AddRef();
    if (b)
        b->Release();
    b = r;
}