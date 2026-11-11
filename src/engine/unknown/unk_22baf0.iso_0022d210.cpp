// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x0022d210 FUN_0022d210 (48 B): matches/0x0022d210.cpp [isolated: lost its match in the tree (call sequence differs); on include/gen/ and not mergeable]
// sym: ?FUN_0022d210@Obj_22d210@owners@@QAEXPAU12@@Z
#include "gen/owners.h"
struct Arg_22d210 {
};
void owners::Obj_22d210::FUN_0022d210(owners::Obj_22d210* a) {
    unsigned int t[3];
    ((owners::Mat_22c2b0 *)(((Arg_22d210*)a)))->FUN_0022c2b0((float *)(owners :: Obj_22d210 *)this, (float *)t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}

