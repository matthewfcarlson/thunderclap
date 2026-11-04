// Same code shape as 0x0010bd90 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"
struct RefCounted_156d40 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_156d40[];
extern "C" void opdel(void*);

class InterruptPriorityAction_156d40 {
  public:
    InterruptPriorityAction_156d40* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_156d40* m_20;
};

InterruptPriorityAction_156d40* InterruptPriorityAction_156d40::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_156d40;
    RefCounted_156d40* q = *(RefCounted_156d40* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
