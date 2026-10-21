#include "compat/ptr.h"
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_001c52f0 @ 0x001c52f0
#include "decls/address.h"
struct Clock_1c52f0 {
    float FUN_00085f80();
};

struct World {
    char pad0[0x58];
    Clock_1c52f0 *clock;
};


class Blender_1c52f0 {
public:
    char pad0[0x80];
    float value;
    float limit;
    float accel;
    char fresh;
    char pad8d[3];
    float current;
    float target;
    float rate;
    char pad9c[4];
    float timer;
    void FUN_001c52f0(float unused);
};

void Blender_1c52f0::FUN_001c52f0(float unused)
{
    hulk_freg dt = DAT_004dd700->clock->FUN_00085f80();
    if (!(dt < 0.1f))
        dt = 0.1f;

    if (accel != 0.0f) {
        hulk_freg v = dt * accel + value;
        value = v;
        if ((accel > 0.0f && v >= limit) || (accel < 0.0f && v <= limit)) {
            value = limit;
            accel = 0.0f;
        }
    }

    if (!fresh)
        target = 0.0f;
    fresh = 0;

    if (current != target) {
        hulk_freg s = dt * rate;
        if (!(s < 1.0f))
            s = 1.0f;
        hulk_freg c = s * (target - current) + current;
        current = c;
        union { float f; unsigned int u; } d;
        d.f = c - target;
        d.u &= 0x7fffffff;
        if (d.f < 0.00392156886f)
            current = target;
    }

    if (timer > 0.0f)
        timer = timer - dt;
}
