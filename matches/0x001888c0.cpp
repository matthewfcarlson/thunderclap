// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_1888c0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_1888c0[];
extern "C" void opdel(void*);

class PropActorThinkingAction_1888c0 {
  public:
    void Cleanup();
    PropActorThinkingAction_1888c0* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_1888c0* m_20;
};

PropActorThinkingAction_1888c0* PropActorThinkingAction_1888c0::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_1888c0;
    RefCounted_1888c0* q = (RefCounted_1888c0*)p[8];
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
