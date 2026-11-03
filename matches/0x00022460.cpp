#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22460[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_22460 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22460 {
  public:
    void* vptr;
};
class CDriftAction_22460 : public CAction_22460 {
  public:
    char pad[0x18];
    Ref_22460* m;
    CDriftAction_22460* f2(unsigned char flags);
};
CDriftAction_22460* CDriftAction_22460::f2(unsigned char flags) {
    vptr = g_vftable_22460;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22460 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
