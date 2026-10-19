// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b35d0 @ 0x001b35d0
#include "decls/data/game/global.h"

struct Obj { char pad0[12]; int index; char pad1[12]; float limit; float FUN_001b35d0(float time); int FUN_001b3250(float); }; float Obj::FUN_001b35d0(float time) { int savedIndex = index; if (savedIndex < 0) return (*(float*)&DAT_003f32e0); if (time < (*(float*)&DAT_0041d97c)) time = 0.02f; if (time >= limit) return (*(float*)&DAT_003f32e0); int pos = FUN_001b3250(time); return ((float*)((char*)&DAT_004e1830 + 144))[(unsigned int)pos + savedIndex * 45]; }