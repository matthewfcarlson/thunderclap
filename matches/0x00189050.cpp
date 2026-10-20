// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_189050 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_189050[];
extern "C" void opdel(void*);

namespace hulkfight { namespace motion { class ShieldArcAction {
  public:
    void Cleanup();
    ShieldArcAction* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_189050* m_20;
}; }}

hulkfight::motion::ShieldArcAction* hulkfight::motion::ShieldArcAction::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_189050;
    RefCounted_189050* q = (RefCounted_189050*)p[8];
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
