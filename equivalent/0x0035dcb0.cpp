// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035dcb0 @ 0x0035dcb0
// Static initialiser for a table of nine {lo, hi, level} bands.
#include "decls/data/game/global.h"

struct Band {
    float lo;
    float hi;
    int level;
};

void FUN_0035dcb0()
{
    ((Band*)&DAT_004de8d0)[0].lo = 1.0471975803375244f;
    ((Band*)&DAT_004de8d0)[0].hi = 2.094395160675049f;
    ((Band*)&DAT_004de8d0)[0].level = 0;
    ((Band*)&DAT_004de8d0)[1].lo = 2.094395160675049f;
    ((Band*)&DAT_004de8d0)[1].hi = 2.6179938316345215f;
    ((Band*)&DAT_004de8d0)[1].level = 7;
    ((Band*)&DAT_004de8d0)[2].lo = 2.6179938316345215f;
    ((Band*)&DAT_004de8d0)[2].hi = 3.665191650390625f;
    ((Band*)&DAT_004de8d0)[2].level = 6;
    ((Band*)&DAT_004de8d0)[3].lo = 3.665191650390625f;
    ((Band*)&DAT_004de8d0)[3].hi = 4.188790321350098f;
    ((Band*)&DAT_004de8d0)[3].level = 5;
    ((Band*)&DAT_004de8d0)[4].lo = 4.188790321350098f;
    ((Band*)&DAT_004de8d0)[4].hi = 5.235987663269043f;
    ((Band*)&DAT_004de8d0)[4].level = 4;
    ((Band*)&DAT_004de8d0)[5].lo = 5.235987663269043f;
    ((Band*)&DAT_004de8d0)[5].hi = 5.759586811065674f;
    ((Band*)&DAT_004de8d0)[5].level = 3;
    ((Band*)&DAT_004de8d0)[6].lo = 5.759586811065674f;
    ((Band*)&DAT_004de8d0)[6].hi = 6.28493070602417f;
    ((Band*)&DAT_004de8d0)[6].level = 2;
    ((Band*)&DAT_004de8d0)[7].lo = 0.0f;
    ((Band*)&DAT_004de8d0)[7].hi = 0.5235987901687622f;
    ((Band*)&DAT_004de8d0)[7].level = 2;
    ((Band*)&DAT_004de8d0)[8].lo = 0.5235987901687622f;
    ((Band*)&DAT_004de8d0)[8].hi = 1.0471975803375244f;
    ((Band*)&DAT_004de8d0)[8].level = 1;
}
