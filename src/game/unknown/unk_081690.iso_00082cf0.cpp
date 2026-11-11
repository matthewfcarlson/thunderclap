// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00081690..0x000832e0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x00082cf0 FUN_00082cf0 (21 B): equivalent/0x00082cf0.cpp [isolated: conflict: World; on include/gen/ and not mergeable]
// sym: ?FUN_00082cf0@Owner_82cf0@owners@@QAEHXZ @e47e606db893 @w841424a1588d
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00082cf0 @ 0x00082cf0
// FUN_00082cf0 @ 0x00082cf0
#include "decls/address.h"
#include "gen/owners.h"
struct Recipient { int FUN_001dc3b0(int); }; struct World { char pad[12]; Recipient* recipient; };   hulk_intptr owners::Owner_82cf0::FUN_00082cf0() { return DAT_004dd700->recipient->FUN_001dc3b0(value); }

