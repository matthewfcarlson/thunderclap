// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1d70..0x000e1dd0 (kind game, layer game, confidence medium), dominant class FEAnimationHolder
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fd669bc1 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd669bc1 {} using namespace fn_fd669bc1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd669bc1 {
struct X_e1d70 {
    int pad;
    unsigned int value;
};


// 0x000e1d70 FEAnimationHolder::vfunc_0 (4 B): matches/0x000e1d70.cpp
// sym: ?FUN_000e1d70@fn_fd669bc1@@YIIPAUX_e1d70@1@@Z
// Same code shape as 0x00086270 (propagated; names are from that function)
unsigned int __fastcall FUN_000e1d70(X_e1d70* p) {
    return p->value;
}

} // namespace fn_fd669bc1
