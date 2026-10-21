// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// FUN_000a03c0 @ 0x000a03c0
#include "decls/data/game/global.h"
#include "compat/ptr.h"

float __cdecl FUN_000a0330(float);
float __cdecl FUN_000a02a0(float);
hulk_freg Clamp3(float a, float b, float c) {
 float span = FUN_000a0330(c - b);
 if (FUN_000a0330(a - b) > span) {
  if (FUN_000a02a0(a - (span * (*(float*)&DAT_003f32f4) + b)) > (*(float*)&DAT_003f32e0))
   return FUN_000a02a0(c);
  return FUN_000a02a0(b);
 }
 return FUN_000a02a0(a);
}
