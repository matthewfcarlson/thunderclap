// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021940..0x00021960 (kind game, layer game, confidence medium), dominant class CPushBackAnimationAction
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f428945e {
#define TREE_TU_END }
namespace fn_f428945e {} using namespace fn_f428945e;
#include "game/global.h"


// 0x00021940 CPushBackAnimationAction::vfunc_2 (30 B): matches/0x00021940.cpp
// sym: ?vfunc_2@CPushBackAnimationAction_21940@fn_00021940@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `CPushBackAnimationAction::~CPushBackAnimationAction() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x0001cf90, then (flags & 1) operator delete.
namespace fn_00021940 {
struct CPushBackAnimationAction_21940 {
    void FUN_0001cf90();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* CPushBackAnimationAction_21940::vfunc_2(unsigned int flags) {
    FUN_0001cf90();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00021940
// (x64t21) the destructor itself, which other objects' code references:
CPushBackAnimationAction::~CPushBackAnimationAction() {}

