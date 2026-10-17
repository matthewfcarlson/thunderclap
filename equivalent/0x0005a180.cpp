// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005a180 @ 0x0005a180
#include "decls/data/game/unknown.h"

struct Vec3 { float x, y, z; };  struct Obj { char pad[0x34]; float x, y, z; unsigned FUN_0005a180(const Vec3* v); }; unsigned Obj::FUN_0005a180(const Vec3* v) { z = v->z * (*(float*)&DAT_003f32b8); y = v->y * (*(float*)&DAT_003f32b8); x = v->x * (*(float*)&DAT_003f32b8); return ((unsigned)v & 0xffffff00u) | 1u; }