#include "compat/ptr.h"
// FUN_00226960 @ 0x00226960
float __cdecl FUN_0004af40(float lo, float hi, float v);

struct Sample_226960 {
    float value;
    float pad;
};

class Table_226960 {
public:
    char pad00[0x28];
    unsigned int count;
    char pad2c[0x1280 - 0x2c];
    Sample_226960 samples[1];
    hulk_freg FUN_00226960(unsigned int row, float v);
};

// Wraps v into [0, 2*pi), then linearly interpolates between the two neighbouring samples of the row.
hulk_freg Table_226960::FUN_00226960(unsigned int row, float v)
{
    hulk_freg angle = FUN_0004af40(0.0f, 6.2831855f, v);
    hulk_freg step = 6.2831855f / (hulk_freg)count;
    hulk_freg inv = 1.0f / step;
    int j = (unsigned int)(int)(inv * angle) % count;
    unsigned int base = row * count;
    hulk_freg frac = inv * (angle - (hulk_freg)j * step);
    unsigned int next = (j + 1) % count;
    return (1.0f - frac) * samples[base + j].value + frac * samples[base + next].value;
}
