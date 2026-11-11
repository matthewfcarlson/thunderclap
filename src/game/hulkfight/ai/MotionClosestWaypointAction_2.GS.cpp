// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
#include "tree_prelude.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fef696d1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fef696d1 {} using namespace fn_fef696d1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fef696d1 {
struct Bounds_117da0 { char pad[0x18]; float lowX, highX, lowY, highY; };
struct Result_117da0;
struct Link_117da0 { Result_117da0* FUN_00059a30(); };
struct Source_117da0 {  };
struct Item_117da0 { char pad[0xb4]; unsigned valueB4, valueB8; unsigned FUN_001034d0(); };
struct Provider_117da0 { Item_117da0* FUN_000fdc40(); };
struct Result_117da0 { char pad[0x10]; unsigned* id; char pad2[0x1ca0-0x14]; Provider_117da0* provider; };
struct Text_117da0 { char data[0x5c]; void FUN_001ca2e0(unsigned, unsigned, unsigned, int); };
struct Packet_117da0 { Text_117da0 text; };
struct Sink_117da0 { void FUN_001cbc20(Packet_117da0*); };
} // namespace fn_fef696d1
struct World { char pad[0x30]; Sink_117da0* sink; };
namespace fn_fef696d1 {
struct Target_117da0 { char pad[0x1c]; Bounds_117da0* bounds; Source_117da0* source; char pad2[0xc]; float magnitude, x, y; char pad3[0xc]; unsigned value; bool run(); };


// 0x00117da0 FUN_00117da0 (290 B): equivalent/0x00117da0.cpp
// sym: ?run@Target_117da0@fn_fef696d1@@QAE_NXZ @76d29fa3a002 @wbeb7bbee6d6f
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 24/24)
// FUN_00117da0 @ 0x00117da0
bool Target_117da0::run() {
 bool inX = x <= bounds->highX && x >= bounds->lowX;
 bool inY = y <= bounds->highY && y >= bounds->lowY;
 union { float f; unsigned u; } absolute;
 absolute.f = magnitude; absolute.u &= 0x7fffffff;
 bool ok = inX && inY && absolute.f <= 1e-05f;
 if (source) {
  Link_117da0* link = ((Link_117da0 *)((owners::Object_592a0 *)source)->FUN_000592a0());
  Result_117da0* result = link->FUN_00059a30();
  if (result && ok) {
   Item_117da0* item = result->provider->FUN_000fdc40();
   if (item) {
    Sink_117da0* sink = DAT_004dd700->sink;
    unsigned v = value;
    unsigned id = *result->id;
    unsigned token = item->FUN_001034d0();
    Packet_117da0 packet;
    packet.text.FUN_001ca2e0(token, id, v, 1);
    sink->FUN_001cbc20(&packet);
    item->valueB8 = value;
    item->valueB4 = value;
   }
  }
 }
 return ok;
}

} // namespace fn_fef696d1
