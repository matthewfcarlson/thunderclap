// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 12/14, incomplete)
// FUN_00036350 @ 0x00036350
#include "gen/owners.h"
float __cdecl FUN_000964e0();


void owners::Owner_36350::FUN_00036350(int index, float offset)
{
    if (index < 0 || index >= 14)
        return;
    bool odd = (index % 2) != 0;
    if (odd == (flip != 0))
        values[index] = FUN_000964e0() + offset;
    else
        values[index] = FUN_000964e0();
    dirty[index] = 1;
}
