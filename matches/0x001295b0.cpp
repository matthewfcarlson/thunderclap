// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_1295b0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_1295b0[];
extern "C" void opdel(void*);

namespace hulkfight { namespace ai { class AcquireTargetAction {
  public:
    void Cleanup();
    AcquireTargetAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1295b0* m_20;
}; }}

hulkfight::ai::AcquireTargetAction* hulkfight::ai::AcquireTargetAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1295b0;
    RefCounted_1295b0* q = *(RefCounted_1295b0* volatile*)&m_20;
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
