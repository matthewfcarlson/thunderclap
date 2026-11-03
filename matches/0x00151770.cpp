#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_151770 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151770 {
  public:
    void* vptr;
};
class HitPauseAction_151770 : public Action_151770 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_151770* m20;
    ~HitPauseAction_151770() throw();
};
HitPauseAction_151770::~HitPauseAction_151770() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151770 *)this)->FUN_002326a0();
}
