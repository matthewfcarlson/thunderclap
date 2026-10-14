// STATUS: equivalent (tools/equiv.py level 3: 2393 inputs, branch coverage 2/2)
// FUN_00226960 @ 0x00226960
float __cdecl FUN_0004af40(float lo, float hi, float v);

struct Sample {
    float value;
    float pad;
};

class Table {
public:
    char pad00[0x28];
    unsigned int count;
    char pad2c[0x1280 - 0x2c];
    Sample samples[1];
    float FUN_00226960(unsigned int row, float v);
};

// Wraps v into [0, 2*pi), then linearly interpolates between the two neighbouring samples of the row.
float Table::FUN_00226960(unsigned int row, float v)
{
    float angle = FUN_0004af40(0.0f, 6.2831855f, v);
    float step = 6.2831855f / (float)count;
    float inv = 1.0f / step;
    int j = (unsigned int)(int)(inv * angle) % count;
    unsigned int base = row * count;
    float frac = inv * (angle - (float)j * step);
    unsigned int next = (j + 1) % count;
    return (1.0f - frac) * samples[base + j].value + frac * samples[base + next].value;
}
