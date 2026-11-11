// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00189050..0x001890a0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::ShieldArcAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f9e817e8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9e817e8 {} using namespace fn_f9e817e8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9e817e8 {
struct RefCounted_189050 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419774[];
namespace hulkfight { namespace motion {
class ShieldArcAction {
  public:
    void Cleanup_002326a0();
    ShieldArcAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_189050* m_20;
};
} }


// 0x00189050 hulkfight::motion::ShieldArcAction::vfunc_2 (71 B): matches/0x00189050.cpp
// sym: ?vfunc_2@ShieldArcAction@motion@hulkfight@fn_f9e817e8@@QAEPAV1234@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
hulkfight::motion::ShieldArcAction* hulkfight::motion::ShieldArcAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419774;
    RefCounted_189050* q = *(RefCounted_189050* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_f9e817e8
