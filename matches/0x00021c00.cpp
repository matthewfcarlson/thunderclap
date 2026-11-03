#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21c00[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21c00 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21c00 {
  public:
    void* vptr;
};
class CDamageAction_21c00 : public CAction_21c00 {
  public:
    char pad[0x1c - 4];
    Ref_21c00* m1c;
    CDamageAction_21c00* f2(unsigned char flags);
};
CDamageAction_21c00* CDamageAction_21c00::f2(unsigned char flags) {
    vptr = g_vftable_21c00;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21c00 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
