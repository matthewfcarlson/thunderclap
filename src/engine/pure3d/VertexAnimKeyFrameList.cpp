// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e6550..0x002e6570 (kind game, layer engine, confidence medium), dominant class pure3d::VertexAnimKeyFrameList
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f712804e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f712804e {} using namespace fn_f712804e;
#include "engine/pure3d.h"


// 0x002e6550 pure3d::VertexAnimKeyFrameList::vfunc_2 (30 B): matches/0x002e6550.cpp
// sym: ?vfunc_2@VertexAnimKeyFrameList_2e6550@fn_002e6550@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::VertexAnimKeyFrameList::~VertexAnimKeyFrameList() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x002e6270, then (flags & 1) operator delete.
namespace fn_002e6550 {
struct VertexAnimKeyFrameList_2e6550 {
    void FUN_002e6270();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* VertexAnimKeyFrameList_2e6550::vfunc_2(unsigned int flags) {
    FUN_002e6270();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002e6550
// (x64t21) the destructor itself, which other objects' code references:
pure3d::VertexAnimKeyFrameList::~VertexAnimKeyFrameList() {}

