// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// FUN_00240190 @ 0x00240190
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

  void __cdecl FUN_00247570(void *p); owners::Text_240190 *owners::Text_240190::FUN_00240190(const owners::Text_240190 *other) { if (other != this) { if (kind == 2) { short *count = (short *)(data - 4); if (*count == 1) { if (data != (*(char**)&DAT_004cc02c)) FUN_00247570(data - 8); } else --*count; } FUN_00240090(other); } return this; }