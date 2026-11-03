// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0030d850 @ 0x0030d850
#include "gen/owners.h"
typedef unsigned int uint;
void owners::Range_30d850::FUN_0030d850(uint first, uint firstValue, uint second, uint secondValue, hulk_uintptr last)
{
    if (first < second) {
        low = first;
        lowValue = firstValue;
        high = second;
        highValue = secondValue;
    } else {
        low = second;
        lowValue = secondValue;
        high = first;
        highValue = firstValue;
    }
    extra = ((uint)last);
}