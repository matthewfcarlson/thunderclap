#include "compat/ptr.h"
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_173c00 {
  public:
    virtual void Fn();
    char pad[0x18];
    Action_173c00();
};
struct Slot {
    volatile int value;
    Slot() : value(0) {}
};
class JointPivotTrackerAction : public Action_173c00 {
  public:
    virtual void Fn();
    Slot a;
    hulk_intptr b, c;
    char pad2[0x58];
    int d;
    JointPivotTrackerAction(int, Ref*);
};
JointPivotTrackerAction::JointPivotTrackerAction(int x, Ref* r) : Action_173c00() {
    b = 0;
    c = 0;
    d = 0;
    a.value = x;
    if (r)
        r->Add();
    if (b)
        ((Ref*)b)->Release();
    b = (hulk_intptr)r;
}