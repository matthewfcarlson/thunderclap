#include "compat/ptr.h"
extern "C" char DAT_0040ecd8[];
class Ref_116a30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_116a30 {
  public:
    volatile hulk_intptr v;
    Action_116a30();
};
class MotionTargetAction : public Action_116a30 {
  public:
    char pad[24];
    volatile int a;
    Ref_116a30* b;
    int c;
    MotionTargetAction(int x, Ref_116a30* r);
};
MotionTargetAction::MotionTargetAction(int x, Ref_116a30* r) : Action_116a30() {
    v = ((hulk_intptr)DAT_0040ecd8);
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