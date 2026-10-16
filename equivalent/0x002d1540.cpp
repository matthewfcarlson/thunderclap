// STATUS: equivalent (tools/equiv.py level 3: 2241 inputs, branch coverage 4/4)
// FUN_002d1540 @ 0x002d1540
// FUN_002d1540 @ 0x002d1540: re-rolls an entry's random byte once enough time has passed since the last roll
#include "decls/data/engine/pure3d.h"

struct RandomState_2d1540 {
    unsigned int first;
    unsigned int second;
    void FUN_0022aba0(int seed);
};

struct Limits_2d1540 {
    char pad00[8];
    unsigned int range;
    float interval;
};

struct Owner_2d1540 {
    char pad00[0x1bc];
    Limits_2d1540 *limits;
};

struct Entry_2d1540 {
    char pad00[0x19];
    unsigned char roll;
    char pad1a[0x2c - 0x1a];
    float now;
    char pad30[4];
    float last;
};

void __cdecl FUN_002d1540(int a, Owner_2d1540 *owner, Entry_2d1540 *entry)
{
    if (!(DAT_00554bf8 & 1)) {
        DAT_00554bf8 |= 1;
        (*(RandomState_2d1540*)&DAT_00554bf0).FUN_0022aba0(0);
    }
    Limits_2d1540 *limits = owner->limits;
    if (entry->now - entry->last > limits->interval) {
        entry->last = entry->now;
        unsigned int bound = limits->range - 1;
        unsigned int first = ((*(RandomState_2d1540*)&DAT_00554bf0).first & 0xffff) * 0x9069u + ((*(RandomState_2d1540*)&DAT_00554bf0).first >> 16);
        unsigned int second = ((*(RandomState_2d1540*)&DAT_00554bf0).second & 0xffff) * 0x4650u + ((*(RandomState_2d1540*)&DAT_00554bf0).second >> 16);
        (*(RandomState_2d1540*)&DAT_00554bf0).second = second;
        (*(RandomState_2d1540*)&DAT_00554bf0).first = first;
        entry->roll = (unsigned char)(((first << 16) + (second & 0xffff)) % (bound + 1));
    }
}
