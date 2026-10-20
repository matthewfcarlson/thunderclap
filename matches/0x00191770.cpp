// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_191770 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_191770[];
extern "C" void opdel(void*);

class SimulationAction_191770 {
  public:
    void Cleanup();
    SimulationAction_191770* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_191770* m_20;
};

SimulationAction_191770* SimulationAction_191770::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_191770;
    RefCounted_191770* q = (RefCounted_191770*)p[8];
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
