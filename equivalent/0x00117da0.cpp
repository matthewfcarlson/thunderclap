// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 24/24)
// FUN_00117da0 @ 0x00117da0
// cl-flags: /GS
#include "decls/address.h"
struct Bounds_117da0 { char pad[0x18]; float lowX, highX, lowY, highY; };
struct Result_117da0;
struct Link_117da0 { Result_117da0* FUN_00059a30(); };
struct Source_117da0 { Link_117da0* FUN_000592a0(); };
struct Item_117da0 { char pad[0xb4]; unsigned valueB4, valueB8; unsigned FUN_001034d0(unsigned, unsigned, int); };
struct Provider_117da0 { Item_117da0* FUN_000fdc40(); };
struct Result_117da0 { char pad[0x10]; unsigned* id; char pad2[0x1ca0-0x14]; Provider_117da0* provider; };
struct Text_117da0 { char data[80]; void FUN_001ca2e0(unsigned); };
struct Packet_117da0 { char prefix[12]; Text_117da0 text; };
struct Sink_117da0 { void FUN_001cbc20(Packet_117da0*); };
struct World { char pad[0x30]; Sink_117da0* sink; };
struct Target_117da0 { char pad[0x1c]; Bounds_117da0* bounds; Source_117da0* source; char pad2[0xc]; float magnitude, x, y; char pad3[0xc]; unsigned value; bool run(); };
bool Target_117da0::run() {
 bool inX = x <= bounds->highX && x >= bounds->lowX;
 bool inY = y <= bounds->highY && y >= bounds->lowY;
 union { float f; unsigned u; } absolute;
 absolute.f = magnitude; absolute.u &= 0x7fffffff;
 bool ok = inX && inY && absolute.f <= 1e-05f;
 if (source) {
  Link_117da0* link = source->FUN_000592a0();
  Result_117da0* result = link->FUN_00059a30();
  if (result && ok) {
   Item_117da0* item = result->provider->FUN_000fdc40();
   if (item) {
    Sink_117da0* sink = DAT_004dd700->sink;
    unsigned token = item->FUN_001034d0(*result->id, value, 1);
    Packet_117da0 packet;
    packet.text.FUN_001ca2e0(token);
    sink->FUN_001cbc20(&packet);
    item->valueB8 = value;
    item->valueB4 = value;
   }
  }
 }
 return ok;
}