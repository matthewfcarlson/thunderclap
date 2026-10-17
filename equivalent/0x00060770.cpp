// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060770 @ 0x00060770
#include "decls/data/game/unknown.h"

struct Angles { float x, y, z; }; struct Object { char pad[0x44]; Angles angles; void FUN_00060770(Angles *out); };  void Object::FUN_00060770(Angles *out) { Angles source = angles; out->x = source.x * (*(float*)&DAT_003f3ef4); out->y = source.y * (*(float*)&DAT_003f3ef4); out->z = source.z * (*(float*)&DAT_003f3ef4); }