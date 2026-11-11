// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001c9aa0 FUN_001c9aa0 (136 B): equivalent/0x001c9aa0.cpp [isolated: conflict: World; on include/gen/ and not mergeable]
// sym: ?FUN_001c9aa0@ChargeEvent_1c9aa0@owners@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c9aa0 @ 0x001c9aa0
#include "decls/address.h"
#include "gen/owners.h"
struct Actor_1c9aa0 { const char* FUN_00036d00(); };
struct ActorTable_1c9aa0 {  };
struct World { char pad[0x44]; ActorTable_1c9aa0* actors; };
struct Writer_1c9aa0 {
 void FUN_001d1d10();
};
Writer_1c9aa0* FUN_001d4c90();
bool owners::ChargeEvent_1c9aa0::FUN_001c9aa0() {
 Writer_1c9aa0* w = FUN_001d4c90();
 if (w && ((owners::Obj_1d2e80 *)w)->FUN_001d2e80()) {
  ((owners::Obj_1d1dd0 *)w)->FUN_001d1dd0((hulk_intptr)"charge_type", chargeType);
  ((owners::Obj_1d1d90 *)w)->FUN_001d1d90((hulk_intptr)"charge", charge);
  if (DAT_004dd700) {
   Actor_1c9aa0* a = ((Actor_1c9aa0 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->actors))->FUN_00059c10((void *)(hulk_uintptr)(int)actorId));
   const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
   ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name);
   w->FUN_001d1d10();
   return true;
  }
  w->FUN_001d1d10();
 }
 return false;
}

