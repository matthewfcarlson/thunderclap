// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_156f30 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_156f30[];
extern "C" void opdel(void*);

class HitPauseAction_156f30 {
  public:
    void Cleanup();
    HitPauseAction_156f30* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_156f30* m_20;
};

HitPauseAction_156f30* HitPauseAction_156f30::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_156f30;
    RefCounted_156f30* q = (RefCounted_156f30*)p[8];
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
