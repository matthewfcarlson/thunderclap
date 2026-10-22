#include "gen/hulkfight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_161770[];
class Ref_161770 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct HeliLocomotionAction_nv_161770 {
    void Fn();
};
class HeliLocomotionAction_161770 {
  public:
    void* vptr;
    char p[0x1c];
    Ref_161770* m20;
    Ref_161770* m24;
    HeliLocomotionAction_161770* f2(unsigned char flags);
};
void operator delete(void*);
HeliLocomotionAction_161770* HeliLocomotionAction_161770::f2(unsigned char flags) {
    vptr = g_vftable_161770;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    m20->f1();
    ((HeliLocomotionAction_nv_161770*)(((hulkfight::motion::HeliLocomotionAction*)this)))->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
