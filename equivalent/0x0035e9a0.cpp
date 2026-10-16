// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035e9a0 @ 0x0035e9a0
#include "decls/data/game/global.h"

extern unsigned __int64 FUN_0027afb0(const char *name);
void FUN_0035e9a0() {
    (*(unsigned __int64*)&DAT_004e24c0) = FUN_0027afb0("none");
    (*(unsigned __int64*)&DAT_004e24c8) = FUN_0027afb0("glass");
    (*(unsigned __int64*)&DAT_004e24d0) = FUN_0027afb0("hardwood");
    (*(unsigned __int64*)&DAT_004e24d8) = FUN_0027afb0("softwood");
    (*(unsigned __int64*)&DAT_004e24e0) = FUN_0027afb0("hardrubber");
    (*(unsigned __int64*)&DAT_004e24e8) = FUN_0027afb0("softrubber");
    (*(unsigned __int64*)&DAT_004e24f0) = FUN_0027afb0("hardmetal");
    (*(unsigned __int64*)&DAT_004e24f8) = FUN_0027afb0("softmetal");
    (*(unsigned __int64*)&DAT_004e2500) = FUN_0027afb0("concrete");
    (*(unsigned __int64*)&DAT_004e2508) = FUN_0027afb0("sticky");
    (*(unsigned __int64*)&DAT_004e2510) = FUN_0027afb0("icy");
}
