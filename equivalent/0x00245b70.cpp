// STATUS: equivalent (tools/equiv.py level 3: 1792 inputs, branch coverage 12/12)
// FUN_00245b70 @ 0x00245b70
#include "gen/owners.h"

unsigned char owners::RingReader_245b70::FUN_00245b70(unsigned int index)
{
    if (index >= limit)
        return 0;
    if (index < base)
        return 0;
    if (index >= windowStart && index < windowLen + base)
        return buf[(windowStart - base + index) & 0x7f];
    while (index < windowStart || index >= windowLen + base)
        FUN_002459d0();
    return buf[(index - base + windowStart) & 0x7f];
}
