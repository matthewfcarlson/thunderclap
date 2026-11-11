// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188d30..0x00188d80 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropDropAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fe8e611e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe8e611e {} using namespace fn_fe8e611e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fe8e611e {
struct RefCounted_188d30 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_188d30[];
namespace hulkfight { namespace motion {
class PropDropAction {
  public:
    void Cleanup();
    PropDropAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188d30* m_20;
};
} }


// 0x00188d30 hulkfight::motion::PropDropAction::vfunc_2 (71 B): matches/0x00188d30.cpp
// sym: ?vfunc_2@PropDropAction@motion@hulkfight@fn_fe8e611e@@QAEPAV1234@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
hulkfight::motion::PropDropAction* hulkfight::motion::PropDropAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_188d30;
    RefCounted_188d30* q = *(RefCounted_188d30* volatile*)&m_20;
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

} // namespace fn_fe8e611e
