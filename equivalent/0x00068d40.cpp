// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00068d40 @ 0x00068d40
#include "decls/data/game/unknown.h"

struct Angles { char pad[0x34]; float x, y, z; void FUN_00068d40(float *out); };
void Angles::FUN_00068d40(float *out) {
    out[0] = x * (*(float*)&DAT_003f3ef4);
    out[1] = y * (*(float*)&DAT_003f3ef4);
    out[2] = z * (*(float*)&DAT_003f3ef4);
}
