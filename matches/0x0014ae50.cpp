// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_14ae50 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_14ae50[];
extern "C" void opdel(void*);

class CivilianThrowAction_14ae50 {
  public:
    void Cleanup();
    CivilianThrowAction_14ae50* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_14ae50* m_20;
};

CivilianThrowAction_14ae50* CivilianThrowAction_14ae50::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_14ae50;
    RefCounted_14ae50* q = (RefCounted_14ae50*)p[8];
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
