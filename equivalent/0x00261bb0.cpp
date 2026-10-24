// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2; Wine build 603 inputs, 2/2)
// FUN_00261bb0 @ 0x00261bb0
#include "decls/data/engine/audio.h"
#include "compat/ptr.h"

extern "C" double fmod(double x, double y);
// x87: the original returns fmod's st0 unrounded (`call fmod; ret`, and `fsubr [len]` on the unrounded result)
static inline hulk_freg fmodf_261bb0(float x, float y) { return fmod(x, y); }

double FUN_00261bb0(float a1, const int* length, int a3, int a4, float a5) {
    double beats = (double)a3 + (double)DAT_004cd470 * a4 * 0.001f;
    double rate = (double)a4 * 60.0f / a1;
    float len = (float)*length;
    float pos = (float)(beats / rate + a5);
    if (beats < 0.0)
        return len - fmodf_261bb0(-pos, len);
    return fmodf_261bb0(pos, len);
}
