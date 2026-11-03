#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22560[];
void operator delete(void*);
class Ref_22560 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22560 {
  public:
    void* vptr;
};
class CStageAction_22560 : public CAction_22560 {
  public:
    char pad[0x1c - 4];
    Ref_22560* m;
    CStageAction_22560* f2(unsigned char flags);
};
CStageAction_22560* CStageAction_22560::f2(unsigned char flags) {
    vptr = g_vftable_22560;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22560 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
