// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_188b50 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_188b50[];
extern "C" void opdel(void*);

class PropSetStateByIndexAction_188b50 {
  public:
    void Cleanup();
    PropSetStateByIndexAction_188b50* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_188b50* m_20;
};

PropSetStateByIndexAction_188b50* PropSetStateByIndexAction_188b50::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_188b50;
    RefCounted_188b50* q = (RefCounted_188b50*)p[8];
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
