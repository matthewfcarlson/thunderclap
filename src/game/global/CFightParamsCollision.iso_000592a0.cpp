// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00059260..0x0005a4c0 (kind game, layer game, confidence high), dominant class CFightParamsCollision
// (tree_prelude.h: not needed)


// 0x000592a0 FUN_000592a0 (21 B): equivalent/0x000592a0.cpp [isolated: conflict: DAT_004dd700; on include/gen/ and not mergeable]
// sym: ?FUN_000592a0@Object_592a0@owners@@QAEHXZ @717ab046d7f6 @wa4536000b23d
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_000592a0 @ 0x000592a0
// FUN_000592a0 @ 0x000592a0
#include "gen/owners.h"
struct Handler { int FUN_00059ba0(int value); };
struct Manager { char pad[0x44]; Handler *handler; };
extern Manager *DAT_004dd700;
hulk_intptr owners::Object_592a0::FUN_000592a0() { return DAT_004dd700->handler->FUN_00059ba0(value); }

