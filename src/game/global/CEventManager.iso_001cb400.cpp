// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001cb400 FUN_001cb400 (205 B): equivalent/0x001cb400.cpp [isolated: code differs from its standalone build]
// sym: ?check@Handler_1cb400@fn_f88062eb@@QAE_NPAUItem_1cb400@2@@Z
#include "gen/owners.h"
namespace fn_f88062eb {} using namespace fn_f88062eb;
namespace fn_f88062eb {
// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 21/25, incomplete)
// FUN_001cb400 @ 0x001cb400
struct Item_1cb400 {
 char pad0[4]; unsigned int kind; char pad8[0x28]; int value30; int value34;
};
struct Lookup_1cb400 { int FUN_00059ba0(int); };
struct Owner_1cb400 { char pad[0x44]; Lookup_1cb400* lookup; };
struct Handler_1cb400 { char pad[4]; Owner_1cb400* owner; bool check(Item_1cb400*); };
bool Handler_1cb400::check(Item_1cb400* item) {
 switch(item->kind) {
 case 4: case 15: case 16: case 17: case 18: case 21: case 29: case 30:
 { int value = ((owners::C_1c96e0 *)item)->FUN_001c96e0(2); return owner->lookup->FUN_00059ba0(value)==0; }
 case 20: case 23:
 { int value = ((owners::C_1c96e0 *)item)->FUN_001c96e0(2); if(owner->lookup->FUN_00059ba0(value)==0) { item->value34=0; item->value30=0; ((owners::Thing_1c9700 *)item)->FUN_001c9700(2, 0); } break; }
 }
 return false;
}
} // namespace fn_f88062eb

