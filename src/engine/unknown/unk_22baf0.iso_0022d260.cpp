// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x0022d260 FUN_0022d260 (48 B): matches/0x0022d260.cpp [isolated: lost its match in the tree (call sequence differs); on include/gen/ and not mergeable]
// sym: ?FUN_0022d260@Obj_22d260@owners@@QAEXPAU12@@Z
// Same code shape as 0x0022d210 (propagated; names are from that function)
#include "gen/owners.h"
struct Arg_22d260 {
};
void owners::Obj_22d260::FUN_0022d260(owners::Obj_22d260* a) {
    unsigned int t[3];
    ((owners::M_22c3b0 *)(((Arg_22d260*)a)))->FUN_0022c3b0((float *)(owners :: Obj_22d260 *)this, (float *)t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}

