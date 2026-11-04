// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"
struct RefCounted_1888c0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_1888c0[];
extern "C" void opdel(void*);

class PropActorThinkingAction_1888c0 {
  public:
    PropActorThinkingAction_1888c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1888c0* m_20;
};

PropActorThinkingAction_1888c0* PropActorThinkingAction_1888c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1888c0;
    RefCounted_1888c0* q = *(RefCounted_1888c0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
