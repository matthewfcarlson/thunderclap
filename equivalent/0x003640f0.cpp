// STATUS: equivalent (tools/equiv.py level 3: 1258 inputs, branch coverage 2/2)
// FUN_003640f0 @ 0x003640f0
#include "decls/data/game/global.h"

struct Item { char bytes[8]; void FUN_0027af50(); };
void FUN_003640f0() {
    Item* p = ((Item*)&DAT_004e58c0);
    for (int i = 0; i < 0x108; ++i) {
        p -= 4;
        (p + 1)->FUN_0027af50();
        p->FUN_0027af50();
        (p - 1)->FUN_0027af50();
    }
}