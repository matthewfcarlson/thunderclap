// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 12/12)
// FUN_00207850 @ 0x00207850
#include "gen/owners.h"

bool owners::LoadInventory_207850::FUN_00207850(int flag)
{
    if (blocked == 0 && pending != 0) {
        int n = (char)flag ? FUN_002037a0() : FUN_00204c10(1);
        if (n >= 1) {
            FUN_00207580(n, flag);
            return true;
        }
        pending = 0;
        for (;;) {
            int m = FUN_00204c10(0);
            if (m <= 0)
                break;
            FUN_00207080(m);
        }
        return false;
    }
    return pending != 0;
}
