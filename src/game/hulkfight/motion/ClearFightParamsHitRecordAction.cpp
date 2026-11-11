// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001575f0..0x00157800 (kind game, layer game, confidence medium), dominant class hulkfight::motion::ClearFightParamsHitRecordAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fb6d97ec {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb6d97ec {} using namespace fn_fb6d97ec;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb6d97ec {
struct RefCounted_1575f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004146b4[];
namespace hulkfight { namespace motion {
class ClearFightParamsHitRecordAction {
  public:
    void Cleanup_002326a0();
    ClearFightParamsHitRecordAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1575f0* m_20;
};
} }


// 0x001575f0 hulkfight::motion::ClearFightParamsHitRecordAction::vfunc_2 (71 B): matches/0x001575f0.cpp
// sym: ?vfunc_2@ClearFightParamsHitRecordAction@motion@hulkfight@fn_fb6d97ec@@QAEPAV1234@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
hulkfight::motion::ClearFightParamsHitRecordAction* hulkfight::motion::ClearFightParamsHitRecordAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004146b4;
    RefCounted_1575f0* q = *(RefCounted_1575f0* volatile*)&m_20;
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

} // namespace fn_fb6d97ec
