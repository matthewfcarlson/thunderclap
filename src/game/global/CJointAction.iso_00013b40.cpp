// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000139b0..0x00013b70 (kind game, layer game, confidence medium), dominant class CJointAction
// (tree_prelude.h: not needed)


// 0x00013b40 CJointAction::vfunc_4 (37 B): matches/0x00013b40.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_4@CJointAction@@UAEXXZ
#include "gen/global.h"

struct R_13b40 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_13b40* __fastcall FUN_00059a40(void*);

void CJointAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_13b40* b = FUN_00059a40(a);
    if (b)
        b->call((*(void * *)&this->f_24), 0);
}

