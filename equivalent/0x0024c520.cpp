// STATUS: equivalent (tools/equiv.py level 3: 965 inputs, branch coverage 0/0)
// FUN_0024c520 @ 0x0024c520
#include "decls/data/engine/audio.h"

struct FmtEntry {
    unsigned int scaleA;
    unsigned int scaleB;
    unsigned int pad[4];
};


unsigned int FUN_0024c520(unsigned int *packed, unsigned int value)
{
    unsigned int w = *packed;
    const FmtEntry &e = ((FmtEntry*)&DAT_004cc254)[(int)(w << 28) >> 28];
    unsigned int unit = ((w >> 4) & 0x1f) * e.scaleB;
    unsigned int q = value / unit;
    unsigned int r = value % unit;
    unsigned int scaled = (r * e.scaleA) / unit + q * e.scaleA;
    unsigned int divisor = (w >> 9) & 0x1ffff;
    unsigned int whole = scaled / divisor;
    unsigned int rem = scaled % divisor;
    return whole * 1000 + (rem * 1000) / divisor;
}
