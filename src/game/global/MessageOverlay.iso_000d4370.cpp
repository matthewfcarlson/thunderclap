// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d40e0..0x000d6e00 (kind game, layer game, confidence high), dominant class MessageOverlay
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000d4370 FUN_000d4370 (31 B): matches/0x000d4370.cpp [isolated: lost its match in the tree (call sequence differs); on include/gen/ and not mergeable]
// sym: ?FUN_000d4370@Obj_d4370@owners@@QAEXH@Z
#include "gen/owners.h"
class Other_d4370 {
  public:
};
void owners::Obj_d4370::FUN_000d4370(hulk_intptr x) {
    ((owners::Slots_d6dd0 *)(((Other_d4370*)x)))->FUN_000d6dd0((hulk_intptr)(owners :: Obj_d4370 *)this);
    a = 0;
    b = 1;
}

