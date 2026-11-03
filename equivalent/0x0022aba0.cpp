// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0022aba0 @ 0x0022aba0
#include "gen/owners.h"

void owners::Random_22aba0::FUN_0022aba0(unsigned int seed)
{
    if (seed == 0)
        seed = 0xfc7d2ba2;
    b = seed & 0xffff;
    a = (seed >> 16) * 0x9069;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    a = (a & 0xffff) * 0x9069 + (a >> 16);
    b = (b & 0xffff) * 0x4650 + (b >> 16);
}
