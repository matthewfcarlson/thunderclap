// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001802c0 @ 0x001802c0
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

unsigned char owners::Angles_1802c0::FUN_001802c0(const float *v) {
    x = v[0] * DAT_003f32b8;
    y = v[1] * DAT_003f32b8;
    z = v[2] * DAT_003f32b8;
    return 1;
}