class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Base {
  public:
    virtual void Fn();
    char pad[0x18];
    Base();
};
struct Slot {
    volatile int value;
    Slot() : value(0) {}
};
class JointPivotTrackerAction : public Base {
  public:
    virtual void Fn();
    Slot a;
    int b, c;
    char pad2[0x58];
    int d;
    JointPivotTrackerAction(int, Ref*);
};
JointPivotTrackerAction::JointPivotTrackerAction(int x, Ref* r) : Base() {
    b = 0;
    c = 0;
    d = 0;
    a.value = x;
    if (r)
        r->Add();
    if (b)
        ((Ref*)b)->Release();
    b = (int)r;
}