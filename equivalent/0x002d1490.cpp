// STATUS: equivalent (tools/equiv.py level 3: 2266 inputs, branch coverage 4/4)
// FUN_002d1490 @ 0x002d1490
// FUN_002d1490 @ 0x002d1490: re-rolls an entry's random byte once enough time has passed since the last roll
struct RandomState_2d1490 {
    unsigned int first;
    unsigned int second;
    void FUN_0022aba0(int seed);
};
extern RandomState_2d1490 DAT_00554be4;
extern unsigned int DAT_00554bec;

struct Limits_2d1490 {
    char pad00[8];
    unsigned int range;
    float interval;
};

struct Owner_2d1490 {
    char pad00[0x1bc];
    Limits_2d1490 *limits;
};

struct Entry_2d1490 {
    char pad00[0x19];
    unsigned char roll;
    char pad1a[0x2c - 0x1a];
    float now;
    char pad30[4];
    float last;
};

void __cdecl FUN_002d1490(int a, int b, Owner_2d1490 *owner, Entry_2d1490 *entry)
{
    if (!(DAT_00554bec & 1)) {
        DAT_00554bec |= 1;
        DAT_00554be4.FUN_0022aba0(0);
    }
    Limits_2d1490 *limits = owner->limits;
    if (entry->now - entry->last > limits->interval) {
        entry->last = entry->now;
        unsigned int bound = limits->range - 1;
        unsigned int first = (DAT_00554be4.first & 0xffff) * 0x9069u + (DAT_00554be4.first >> 16);
        unsigned int second = (DAT_00554be4.second & 0xffff) * 0x4650u + (DAT_00554be4.second >> 16);
        DAT_00554be4.second = second;
        DAT_00554be4.first = first;
        entry->roll = (unsigned char)(((first << 16) + (second & 0xffff)) % (bound + 1));
    }
}
