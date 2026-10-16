// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035ebb0 @ 0x0035ebb0
// Static init: hash the eight door/switch state names.
#include "decls/data/game/global.h"

extern unsigned __int64 FUN_0027afb0(const char *name);
void FUN_0035ebb0() {
    (*(unsigned __int64*)&DAT_004e2560) = FUN_0027afb0("clean");
    (*(unsigned __int64*)&DAT_004e2568) = FUN_0027afb0("opening");
    (*(unsigned __int64*)&DAT_004e2570) = FUN_0027afb0("open");
    (*(unsigned __int64*)&DAT_004e2578) = FUN_0027afb0("closing");
    (*(unsigned __int64*)&DAT_004e2580) = FUN_0027afb0("closed");
    (*(unsigned __int64*)&DAT_004e2588) = FUN_0027afb0("on");
    (*(unsigned __int64*)&DAT_004e2590) = FUN_0027afb0("off");
    (*(unsigned __int64*)&DAT_004e2598) = FUN_0027afb0("destroyed");
}
