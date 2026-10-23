#include "gen/hulkfight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151810[];
class Ref_151810 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_151810 {
  public:
    void Fn();
};
struct GroundSlideAction_nv_151810 {
    void Fn();
};
class HitReactionAction_151810 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_151810* m20;
    Sub_151810 m24;
    char p28[0x24];
    Ref_151810* m4c;
    void f();
};
void HitReactionAction_151810::f() {
    vptr = g_vftable_151810;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->f1();
        m4c = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn();
    ((GroundSlideAction_nv_151810*)(((hulkfight::motion::GroundSlideAction*)(((hulkfight::motion::GroundSlideAction*)this)))))->Fn();
}
