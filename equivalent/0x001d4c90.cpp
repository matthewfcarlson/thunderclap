// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d4c90 @ 0x001d4c90
#include "decls/data/game/global.h"

struct Object { Object* FUN_001d4830(); };  void* __cdecl FUN_0008d690(unsigned int); Object* FUN_001d4c90() { if (!(*(Object**)&DAT_004e23cc)) { void* memory = FUN_0008d690(0x5494); if (memory) (*(Object**)&DAT_004e23cc) = ((Object*)memory)->FUN_001d4830(); else (*(Object**)&DAT_004e23cc) = 0; } return (*(Object**)&DAT_004e23cc); }