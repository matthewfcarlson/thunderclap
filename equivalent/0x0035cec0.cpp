// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035cec0 @ 0x0035cec0
// Static init: hash the cow animation names and record whether each loops.
#include "decls/address.h"
#include "decls/data/game/hulkfight.h"

struct AnimKey {
    unsigned __int64 key;
    char loops;
    char pad[7];
};


void FUN_0035cec0() {
    (*(AnimKey*)&DAT_004dd270).key = FUN_0027b020("cow_amb_idle");
    (*(AnimKey*)&DAT_004dd270).loops = 1;
    (*(AnimKey*)&DAT_004dd280).key = FUN_0027b020("cow_loco_walk_n");
    (*(AnimKey*)&DAT_004dd280).loops = 1;
    (*(AnimKey*)&DAT_004dd290).key = FUN_0027b020("cow_loco_180_turn");
    (*(AnimKey*)&DAT_004dd290).loops = 0;
    (*(AnimKey*)&DAT_004dd2a0).key = FUN_0027b020("cow_loco_run_n");
    (*(AnimKey*)&DAT_004dd2a0).loops = 1;
    (*(AnimKey*)&DAT_004dd2b0).key = FUN_0027b020("cow_amb_flail");
    (*(AnimKey*)&DAT_004dd2b0).loops = 1;
    (*(AnimKey*)&DAT_004dd2c0).key = FUN_0027b020("cow_loco_getup");
    (*(AnimKey*)&DAT_004dd2c0).loops = 0;
}
