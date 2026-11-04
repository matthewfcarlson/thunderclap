// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_157150 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_157150[];
extern "C" void opdel(void*);

namespace hulkfight { namespace motion { class NoHitPushbackAction {
  public:
    void Cleanup();
    NoHitPushbackAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_157150* m_20;
}; }}

hulkfight::motion::NoHitPushbackAction* hulkfight::motion::NoHitPushbackAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_157150;
    RefCounted_157150* q = *(RefCounted_157150* volatile*)&m_20;
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
