// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00085e60 @ 0x00085e60
#include "decls/data/game/global.h"

double __cdecl FUN_00085e60(unsigned int low, unsigned int high)
{
    unsigned __int64 bits = ((unsigned __int64)high << 32) | low;
    return (double)bits * (*(float*)&DAT_003ffaa4);
}
