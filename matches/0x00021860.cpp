#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21860[];
void operator delete(void*);
class Ref_21860 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21860 {
  public:
    void* vptr;
};
class COpportunityBallAction_21860 : public CAction_21860 {
  public:
    char pad[0x1c - 4];
    Ref_21860* m;
    COpportunityBallAction_21860* f2(unsigned char flags);
};
COpportunityBallAction_21860* COpportunityBallAction_21860::f2(unsigned char flags) {
    vptr = g_vftable_21860;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21860 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
