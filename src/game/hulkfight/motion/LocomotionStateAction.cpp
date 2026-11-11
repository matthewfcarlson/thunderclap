// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017afd0..0x0017b020 (kind game, layer game, confidence medium), dominant class hulkfight::motion::LocomotionStateAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fc50511e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc50511e {} using namespace fn_fc50511e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc50511e {
struct RefCounted_17afd0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17afd0[];
namespace hulkfight { namespace motion {
class LocomotionStateAction {
  public:
    void Cleanup();
    LocomotionStateAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17afd0* m_20;
};
} }


// 0x0017afd0 hulkfight::motion::LocomotionStateAction::vfunc_2 (71 B): matches/0x0017afd0.cpp
// sym: ?vfunc_2@LocomotionStateAction@motion@hulkfight@fn_fc50511e@@QAEPAV1234@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
hulkfight::motion::LocomotionStateAction* hulkfight::motion::LocomotionStateAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17afd0;
    RefCounted_17afd0* q = *(RefCounted_17afd0* volatile*)&m_20;
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

} // namespace fn_fc50511e
