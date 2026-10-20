// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
struct RefCounted_129650 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_129650[];
extern "C" void opdel(void*);

namespace hulkfight { namespace ai { class ClearProjectileDistanceAction {
  public:
    void Cleanup();
    ClearProjectileDistanceAction* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_129650* m_20;
}; }}

hulkfight::ai::ClearProjectileDistanceAction* hulkfight::ai::ClearProjectileDistanceAction::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (hulk_intptr)&g_vt_129650;
    RefCounted_129650* q = (RefCounted_129650*)p[8];
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
