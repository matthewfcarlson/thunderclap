// STATUS: equivalent (tools/equiv.py level 3: 18624 inputs, branch coverage 10/10)
// FUN_000f8280 @ 0x000f8280
#include "compat/ptr.h"
struct ColorSlot {
    unsigned int color;
    char pad[12];
};

extern float (*DAT_004de948)();

struct Gradient {
    char pad0[0x14];
    ColorSlot slots[7];
    char pad84[4];
    int current;
    void FUN_000f8280(unsigned int colorA, unsigned int colorB, unsigned int ticks);
};

void Gradient::FUN_000f8280(unsigned int colorA, unsigned int colorB, unsigned int ticks)
{
    int a[3];
    int b[3];
    int res[3];

    a[0] = (colorA >> 16) & 0xff;
    a[1] = (colorA >> 8) & 0xff;
    a[2] = colorA & 0xff;
    b[0] = (colorB >> 16) & 0xff;
    b[1] = (colorB >> 8) & 0xff;
    b[2] = colorB & 0xff;

    hulk_freg rate = DAT_004de948();
    if (rate > 1.0f)
        rate = 1.0f;
    else if (rate == 0.0f)
        rate = 0.001f;

    hulk_freg scale = 1.0f / rate;
    hulk_freg half = 0.5f * scale;
    unsigned int period = (unsigned int)(__int64)(int)(__int64)scale;
    unsigned int rem = ticks % period;
    hulk_freg phase = (half - (double)rem) / scale;
    hulk_freg t;
    if (phase > 0.0f)
        t = phase + phase;
    else
        t = phase * -2.0f;

    for (int i = 0; i < 3; i++)
        res[i] = (int)(__int64)((double)a[i] - (double)(a[i] - b[i]) * t);

    slots[current].color = (((0xffffff00u | res[0]) << 8 | res[1]) << 8) | res[2];
}
