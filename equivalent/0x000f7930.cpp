// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f7930 @ 0x000f7930
#include "decls/data/game/global.h"
#include "gen/owners.h"

owners::State_f7930* owners::State_f7930::FUN_000f7930() {
    scale = (*(float*)&DAT_004a1734);
    field10 = 0;
    field14 = -1;
    value = 0;
    flag = false;
    fieldC = 0;
    field20 = -1;
    amount = 20.0f;
    flag18 = false;
    return this;
}