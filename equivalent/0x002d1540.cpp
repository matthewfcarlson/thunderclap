// STATUS: equivalent (tools/equiv.py level 3: 2241 inputs, branch coverage 4/4)
// FUN_002d1540 @ 0x002d1540
// FUN_002d1540 @ 0x002d1540: re-rolls an entry's random byte once enough time has passed since the last roll
struct RandomState {
    unsigned int first;
    unsigned int second;
    void FUN_0022aba0(int seed);
};
extern RandomState DAT_00554bf0;
extern unsigned int DAT_00554bf8;

struct Limits {
    char pad00[8];
    unsigned int range;
    float interval;
};

struct Owner {
    char pad00[0x1bc];
    Limits *limits;
};

struct Entry {
    char pad00[0x19];
    unsigned char roll;
    char pad1a[0x2c - 0x1a];
    float now;
    char pad30[4];
    float last;
};

void __cdecl FUN_002d1540(int a, Owner *owner, Entry *entry)
{
    if (!(DAT_00554bf8 & 1)) {
        DAT_00554bf8 |= 1;
        DAT_00554bf0.FUN_0022aba0(0);
    }
    Limits *limits = owner->limits;
    if (entry->now - entry->last > limits->interval) {
        entry->last = entry->now;
        unsigned int bound = limits->range - 1;
        unsigned int first = (DAT_00554bf0.first & 0xffff) * 0x9069u + (DAT_00554bf0.first >> 16);
        unsigned int second = (DAT_00554bf0.second & 0xffff) * 0x4650u + (DAT_00554bf0.second >> 16);
        DAT_00554bf0.second = second;
        DAT_00554bf0.first = first;
        entry->roll = (unsigned char)(((first << 16) + (second & 0xffff)) % (bound + 1));
    }
}
