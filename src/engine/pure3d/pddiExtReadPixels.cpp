// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00320130..0x00320160 (kind game, layer engine, confidence medium), dominant class pure3d::pddiExtReadPixels
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f27a3dfe {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f27a3dfe {} using namespace fn_f27a3dfe;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f27a3dfe {
class pddiExtension_320130 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public pddiExtension_320130 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00320130 pure3d::pddiExtReadPixels::vfunc_0 (31 B): matches/0x00320130.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f27a3dfe@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f27a3dfe
