// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b45a0..0x000b4cf0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000b4b00 FUN_000b4b00 (93 B): equivalent/0x000b4b00.cpp [isolated: conflict: DAT_004dd700; on include/gen/ and not mergeable]
// sym: ?FUN_000b4b00@Obj_b4b00@owners@@QAEXH@Z @72b4c2b93b1f @w89bbb9f36058
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b4b00 @ 0x000b4b00
#include "gen/owners.h"
struct Temp { char bytes[32];  }; struct Service { void FUN_001cbc20(Temp *); }; struct Holder { char pad[0x30]; Service *field; }; extern Holder *DAT_004dd700; extern "C" void __cdecl FUN_000fc300();  void owners::Obj_b4b00::FUN_000b4b00(int choice) { Temp temp; char *s; if (choice == 1) s = first; else if (choice == 2) s = second; else return; if (*s != '\0') { ((owners::Result_1cae40 *)&temp)->FUN_001cae40((hulk_uintptr)s); DAT_004dd700->field->FUN_001cbc20(&temp); } FUN_000fc300(); }

