#include "gen/hulkfight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15eb70[];
class Ref_15eb70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct HeliLocomotionAction_15eb70 {
    void Fn();
};
class ClimbLocomotionAction_15eb70 {
  public:
    void* vptr;
    char p[0x18];
    Ref_15eb70* m1c;
    Ref_15eb70* m20;
    Ref_15eb70* m24;
    void f();
};
void ClimbLocomotionAction_15eb70::f() {
    vptr = g_vftable_15eb70;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c) {
        m1c->f1();
        m1c = 0;
    }
    ((HeliLocomotionAction_15eb70*)(((hulkfight::motion::HeliLocomotionAction*)this)))->Fn();
}
