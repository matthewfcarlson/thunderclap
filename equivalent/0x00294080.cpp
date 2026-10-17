// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 4/4)
// FUN_00294080 @ 0x00294080
#include "decls/data/game/global.h"

struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void FUN_00294080_slot(); }; struct State { char pad[8]; int value; };  struct Owner { char pad[0x3c]; Item *items[32]; void FUN_00294080(); }; void Owner::FUN_00294080() { (*(State**)&DAT_0052c2b4)->value = 0; for (int i = 0; i < 32; ++i) { Item *item = items[i]; if (item) item->FUN_00294080_slot(); } }