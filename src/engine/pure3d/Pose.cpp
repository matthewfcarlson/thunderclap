// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002849c0..0x00284a10 (kind game, layer engine, confidence medium), dominant class pure3d::Pose
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f31e307f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f31e307f {} using namespace fn_f31e307f;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f31e307f {
extern void* hulk_at_0042c588[];
} // namespace fn_f31e307f
void operator delete(void*);
namespace fn_f31e307f {
class Ref_2849c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class NonCopyable_2849c0 {
  public:
    void* vptr;
};
class Pose_2849c0 : public NonCopyable_2849c0 {
  public:
    char pad[4];
    Ref_2849c0* m8;
    char pad2[0x1c];
    void* m28;
    Pose_2849c0* f2(unsigned char flags);
};


// 0x002849c0 pure3d::Pose::vfunc_2 (69 B): matches/0x002849c0.cpp
// sym: ?f2@Pose_2849c0@fn_f31e307f@@QAEPAV12@E@Z
Pose_2849c0* Pose_2849c0::f2(unsigned char flags) {
    vptr = hulk_at_0042c588;
    _ReadWriteBarrier();
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    operator delete[](m28);
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f31e307f
