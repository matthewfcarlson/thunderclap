// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001afb00 @ 0x001afb00
#include "decls/data/game/global.h"

struct Obj { char pad[0x230]; float value; float FUN_001afb00(); }; unsigned int __cdecl FUN_001d64a0();   float Obj::FUN_001afb00() { if (value < (*(float*)&DAT_003f32e0)) { switch (FUN_001d64a0()) { case 0: return DAT_004c3728; case 2: case 6: return DAT_004c371c; case 3: case 7: return DAT_004c3720; case 4: return DAT_004c3724; case 5: return DAT_004c3718; default: return (*(float*)&DAT_003f32e0); } } return value; }