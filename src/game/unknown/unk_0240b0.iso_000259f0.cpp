// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000240b0..0x0002c4f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000259f0 FUN_000259f0 (33 B): matches/0x000259f0.cpp [isolated: conflict: FUN_002672f0; on include/gen/ and not mergeable]
// sym: ?FUN_000259f0@Obj_259f0@owners@@QAEHH@Z
#include "gen/owners.h"
struct R {
    int a;
    int b;
};
R __cdecl FUN_002672f0(int a, int b, int c);
hulk_intptr owners::Obj_259f0::FUN_000259f0(hulk_intptr a) {
    R r = FUN_002672f0(((int)a), 0, 0);
    return Sub(r.a, r.b);
}

