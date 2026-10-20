// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_001ec310 @ 0x001ec310
// cl-flags: /GS
#include "decls/data/game/global.h"

struct Item_1ec310 { unsigned int FUN_0008a2d0(); unsigned int FUN_000897f0(); };
struct Source_1ec310 { Item_1ec310* FUN_00086310(); };
struct Sink_1ec310 { void FUN_001eb060(unsigned int, unsigned int); };
struct Handler_1ec310 { void FUN_001f3950(float); };
struct Owner_1ec310 { Handler_1ec310* handler; Sink_1ec310* sink; void FUN_001efa40(int, unsigned int, unsigned int); };
struct Target_1ec310 { Owner_1ec310* owner; Source_1ec310* source; unsigned char enabled; char padding[3]; float value; void FUN_001ec310(unsigned int); };
void Target_1ec310::FUN_001ec310(unsigned int) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 if (!(*(unsigned char*)&DAT_004e36e0) && enabled) {
  Item_1ec310* item = source->FUN_00086310();
  Sink_1ec310* sink = owner->sink;
  unsigned int a = item->FUN_0008a2d0();
  unsigned int b = item->FUN_000897f0();
  sink->FUN_001eb060(b,a);
  a = item->FUN_0008a2d0();
  b = item->FUN_000897f0();
  owner->FUN_001efa40(1,b,a);
  float v = value;
  if (!(v < 0.0f) && !(v > 100.0f)) owner->handler->FUN_001f3950(v);
  (*(unsigned char*)&DAT_004e36e0) = 1;
 }
}
