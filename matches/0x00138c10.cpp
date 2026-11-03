#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_138c10[];
void operator delete(void*);
class Ref_138c10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_138c10 {
  public:
    void* vptr;
};
class HoverAction_138c10 : public Action_138c10 {
  public:
    char pad[0x20 - 4];
    Ref_138c10* m;
    HoverAction_138c10* f2(unsigned char flags);
};
HoverAction_138c10* HoverAction_138c10::f2(unsigned char flags) {
    vptr = g_vftable_138c10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_138c10 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
