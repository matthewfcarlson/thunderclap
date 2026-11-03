// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0008fe90 @ 0x0008fe90
#include "gen/owners.h"

hulk_intptr owners::BitPool_8fe90::FUN_0008fe90(int unused)
{
    unsigned int index = cursor;
    unsigned int mask = 1u << (index & 0x1f);
    unsigned int word = index >> 5;
    if (index < count) {
        unsigned int *p = bitmap + word;
        do {
            if ((*p & mask) == 0) {
                p = bitmap + word;
                *p |= mask;
                int taken = cursor;
                cursor = taken + 1;
                return elemSize * taken + base;
            }
            cursor = cursor + 1;
            if ((int)mask < 0) {
                word++;
                p++;
                mask = 1;
            } else {
                mask <<= 1;
            }
        } while (cursor < count);
    }
    return 0;
}
