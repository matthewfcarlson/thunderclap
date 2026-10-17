// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0024c1c0 @ 0x0024c1c0
#include "decls/data/engine/audio.h"

struct Entry { int value; int unused; int *key; char rest[12]; };  int __cdecl FUN_0024c1c0(const int *key) { for (int i = 0; i < 6; ++i) { if (*key == *((Entry*)&DAT_004cc248)[i].key) return ((Entry*)&DAT_004cc248)[i].value; } return 7; }