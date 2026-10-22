#include "gen/hulkfight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_14adb0[];
class Ref_14adb0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_14adb0 {
  public:
    void Fn();
};
struct GrappleThrowAction_nv_14adb0 {
    void Fn();
};
class GrappleThrowAction_14adb0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_14adb0* m20;
    Sub_14adb0 m24;
    GrappleThrowAction_14adb0* f2(unsigned char flags);
};
void operator delete(void*);
GrappleThrowAction_14adb0* GrappleThrowAction_14adb0::f2(unsigned char flags) {
    vptr = g_vftable_14adb0;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn();
    ((GrappleThrowAction_nv_14adb0*)(((hulkfight::motion::GrappleThrowAction*)this)))->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
