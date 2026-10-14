// STATUS: equivalent (tools/equiv.py level 3: 2676 inputs, branch coverage 10/10)
// FUN_000900a0 @ 0x000900a0
struct Stat {
    int value;
    char pad[0x3c];
};

struct Stats_900a0 {
    char pad[0x38];
    Stat stats[1];
    int FUN_00090050(const char *name);
    void FUN_000900a0(int amount);
};

void Stats_900a0::FUN_000900a0(int amount)
{
    int idx = FUN_00090050("xp");
    if (idx == -1)
        return;
    int xp = stats[idx].value + amount;
    stats[idx].value = xp;
    if (xp > 999999999)
        stats[idx].value = 999999999;
    if (amount > 0) {
        idx = FUN_00090050("xpaccumulated");
        if (idx != -1) {
            int total = stats[idx].value + amount;
            stats[idx].value = total;
            if (total > 999999999)
                stats[idx].value = 999999999;
        }
    }
}
