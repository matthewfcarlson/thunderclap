#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1758e0[];
class Ref_1758e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1758e0 {
  public:
    void* vptr;
};
class TeleportAction_1758e0 : public Action_1758e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1758e0* m20;
    ~TeleportAction_1758e0();
};
TeleportAction_1758e0::~TeleportAction_1758e0() {
    vptr = g_vftable_1758e0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1758e0 *)this)->FUN_002326a0();
}
