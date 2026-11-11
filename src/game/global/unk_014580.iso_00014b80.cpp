// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014580..0x00014bb0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x00014b80 CKeyPoseAction::vfunc_4 (37 B): matches/0x00014b80.cpp [isolated: conflict: FUN_00059a40; on include/gen/ and not mergeable]
// sym: ?vfunc_4@CKeyPoseAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
#include "gen/global.h"

struct R_14b80 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_14b80* __fastcall FUN_00059a40(void*);

void CKeyPoseAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_14b80* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}

