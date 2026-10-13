// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 24/24)
// FUN_00117da0 @ 0x00117da0
extern unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned);
struct Bounds { char pad[0x18]; float lowX, highX, lowY, highY; };
struct Result;
struct Link { Result* FUN_00059a30(); };
struct Source { Link* FUN_000592a0(); };
struct Item { char pad[0xb4]; unsigned valueB4, valueB8; unsigned FUN_001034d0(unsigned, unsigned, int); };
struct Provider { Item* FUN_000fdc40(); };
struct Result { char pad[0x10]; unsigned* id; char pad2[0x1ca0-0x14]; Provider* provider; };
struct Text { char data[80]; void FUN_001ca2e0(unsigned); };
struct Packet { char prefix[12]; Text text; };
struct Sink { void FUN_001cbc20(Packet*); };
struct Manager { char pad[0x30]; Sink* sink; };
extern Manager* DAT_004dd700;
struct Target { char pad[0x1c]; Bounds* bounds; Source* source; char pad2[0xc]; float magnitude, x, y; char pad3[0xc]; unsigned value; bool run(); };
bool Target::run() {
 unsigned cookie = DAT_004d9968;
 bool inX = x <= bounds->highX && x >= bounds->lowX;
 bool inY = y <= bounds->highY && y >= bounds->lowY;
 union { float f; unsigned u; } absolute;
 absolute.f = magnitude; absolute.u &= 0x7fffffff;
 bool ok = inX && inY && absolute.f <= 1e-05f;
 if (source) {
  Link* link = source->FUN_000592a0();
  Result* result = link->FUN_00059a30();
  if (result && ok) {
   Item* item = result->provider->FUN_000fdc40();
   if (item) {
    Sink* sink = DAT_004dd700->sink;
    unsigned token = item->FUN_001034d0(*result->id, value, 1);
    Packet packet;
    packet.text.FUN_001ca2e0(token);
    sink->FUN_001cbc20(&packet);
    item->valueB8 = value;
    item->valueB4 = value;
   }
  }
 }
 __security_check_cookie(cookie);
 return ok;
}