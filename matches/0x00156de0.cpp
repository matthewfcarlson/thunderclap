// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_156de0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_156de0[];
extern "C" void opdel(void*);

class HitWaitAction_156de0 {
  public:
    void Cleanup();
    HitWaitAction_156de0* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_156de0* m_20;
};

HitWaitAction_156de0* HitWaitAction_156de0::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_156de0;
    RefCounted_156de0* q = (RefCounted_156de0*)p[8];
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
