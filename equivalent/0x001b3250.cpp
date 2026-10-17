// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3250 @ 0x001b3250
#include "decls/data/game/global.h"

struct Entry { float low; float middle; float high; char pad[0xa8]; };
struct Object { char pad[12]; int index; int FUN_001b3250(float value); };
int Object::FUN_001b3250(float value) {
 int i = index;
 if (i < 0 || value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].low) return 0;
 if (value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].middle) return 1;
 return value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].high ? 2 : 3;
}