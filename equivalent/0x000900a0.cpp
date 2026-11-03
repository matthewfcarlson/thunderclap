// STATUS: equivalent (tools/equiv.py level 3: 2676 inputs, branch coverage 10/10)
// FUN_000900a0 @ 0x000900a0
#include "gen/owners.h"
struct Stat {
    int value;
    char pad[0x3c];
};

struct Stats_900a0 {
    char pad[0x38];
    Stat stats[1];
    void FUN_000900a0(int amount);
};

void Stats_900a0::FUN_000900a0(int amount)
{
    int idx = ((owners::Table_90050 *)this)->FUN_00090050((char *)"xp");
    if (idx == -1)
        return;
    int xp = stats[idx].value + amount;
    stats[idx].value = xp;
    if (xp > 999999999)
        stats[idx].value = 999999999;
    if (amount > 0) {
        idx = ((owners::Table_90050 *)this)->FUN_00090050((char *)"xpaccumulated");
        if (idx != -1) {
            int total = stats[idx].value + amount;
            stats[idx].value = total;
            if (total > 999999999)
                stats[idx].value = 999999999;
        }
    }
}
