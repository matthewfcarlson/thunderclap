// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029b100..0x0029b120 (kind game, layer engine, confidence medium), dominant class pure3d::CompositeDrawable::ActivePrimitiveList
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f13cc4b1 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f13cc4b1 {} using namespace fn_f13cc4b1;
#include "engine/pure3d.h"


// 0x0029b100 pure3d::CompositeDrawable::ActivePrimitiveList::vfunc_2 (30 B): matches/0x0029b100.cpp
// sym: ?vfunc_2@ActivePrimitiveList_29b100@fn_0029b100@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::CompositeDrawable::ActivePrimitiveList::~ActivePrimitiveList() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x00299fa0, then (flags & 1) operator delete.
namespace fn_0029b100 {
struct ActivePrimitiveList_29b100 {
    void FUN_00299fa0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* ActivePrimitiveList_29b100::vfunc_2(unsigned int flags) {
    FUN_00299fa0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0029b100
// (x64t21) the destructor itself, which other objects' code references:
pure3d::CompositeDrawable::ActivePrimitiveList::~ActivePrimitiveList() {}

