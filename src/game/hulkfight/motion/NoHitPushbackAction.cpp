// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00157150..0x001571a0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::NoHitPushbackAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fc6b2057 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc6b2057 {} using namespace fn_fc6b2057;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc6b2057 {
struct RefCounted_157150 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004145f0[];
namespace hulkfight { namespace motion {
class NoHitPushbackAction {
  public:
    void Cleanup_002326a0();
    NoHitPushbackAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_157150* m_20;
};
} }


// 0x00157150 hulkfight::motion::NoHitPushbackAction::vfunc_2 (71 B): matches/0x00157150.cpp
// sym: ?vfunc_2@NoHitPushbackAction@motion@hulkfight@fn_fc6b2057@@QAEPAV1234@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
hulkfight::motion::NoHitPushbackAction* hulkfight::motion::NoHitPushbackAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004145f0;
    RefCounted_157150* q = *(RefCounted_157150* volatile*)&m_20;
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

} // namespace fn_fc6b2057
