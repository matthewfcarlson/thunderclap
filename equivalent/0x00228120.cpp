// STATUS: equivalent (tools/equiv.py level 3: 385 inputs, branch coverage 30/30)
// FUN_00228120 @ 0x00228120
#include "compat/ptr.h"
struct Obj_228120 {
    char pad00[0x10];
    float a10;
    float b14;
};

struct Slot_228120 {
    Obj_228120* obj;
    char pad04[0x204];
};

struct Cell_228120 {
    int id;
    float val;
};

struct Entry_228120 {
    int id;
    float weight;
    float value;
};

float FUN_00224fc0(float a, float b);
float FUN_0004af40(float lo, float hi, float x);
float FUN_0015cf40(float x);
void FUN_00227f90(Entry_228120* first, Entry_228120* last, hulk_intptr count);

class Sampler_228120 {
public:
    char pad00[0x20];
    float f20;
    float f24;
    unsigned int width;
    unsigned int height;
    char pad30[4];
    Slot_228120 slots[9];
    Cell_228120 cells[12];
    char pad_dc[4];
    float f12e0;
    float f12e4;
    float threshold;
    unsigned int count;
    Entry_228120 entries[16];

    void FUN_002262d0(int id, float weight, float value);
    void FUN_00228120(float arg);
};

void Sampler_228120::FUN_00228120(float arg)
{
    unsigned int n = width * height;
    count = 0;
    float a = FUN_00224fc0(f12e4, f12e0);
    float ang = FUN_0004af40(0.0f, 6.28318548f, a);

    double step = 6.28318548f / (double)width;
    double inv = 1.0f / step;
    unsigned int idx = (unsigned int)(int)(inv * ang) % width;
    unsigned int next = (idx + 1) % width;
    volatile float tt = FUN_0015cf40((float)((ang - (double)idx * step) * inv));
    volatile float u1 = 1.0f - tt;

    unsigned int row = height - 1;
    unsigned int ca = next + width * row;
    unsigned int cb = idx + width * row;
    volatile float v;
    for (;;) {
        v = tt * cells[ca].val + u1 * cells[cb].val;
        if (threshold >= v)
            break;
        if (row == 0)
            break;
        row--;
        ca -= width;
        cb -= width;
    }

    unsigned int above = cb + width;
    if (above >= n) {
        FUN_002262d0(cells[cb].id, u1, v);
        FUN_002262d0(cells[ca].id, tt, v);
    } else {
        unsigned int aboveNext = ca + width;
        volatile float v2 = u1 * cells[above].val + tt * cells[aboveNext].val;
        volatile float f = (threshold - v) / (v2 - v);
        volatile float g = 1.0f - f;
        FUN_002262d0(cells[cb].id, g * u1, v);
        FUN_002262d0(cells[ca].id, g * tt, v);
        FUN_002262d0(cells[above].id, u1 * f, v2);
        FUN_002262d0(cells[aboveNext].id, f * tt, v2);
    }

    Entry_228120* first = &entries[0];
    Entry_228120* last = &entries[count];
    FUN_00227f90(first, last, last - first);

    double acc = 0;
    for (unsigned int k = 0; k < count; k++) {
        if (entries[k].weight < 0.01f) {
            count = k;
            break;
        }
        acc += entries[k].weight;
    }

    f20 = 0;
    volatile float s2f = 0;
    if (count != 0) {
        double rinv = 1.0f / acc;
        double s2 = s2f;
        for (unsigned int k = 0; k < count; k++) {
            volatile float nw = rinv * entries[k].weight;
            entries[k].weight = nw;
            s2 = s2 + nw * entries[k].value;
            Obj_228120* o = slots[entries[k].id].obj;
            if (o) {
                double num = o->a10 - 1.0f;
                float den = o->b14;
                if (den < 0)
                    den = 1.0f;
                f20 = num / den * nw + f20;
            }
        }
        s2f = (float)s2;
    }

    if (f20 > 0.0f) {
        double val;
        if (s2f > 0.0f && threshold > 0.0f)
            val = threshold / s2f * arg;
        else
            val = arg;
        volatile float r = val / f20 + f24;
        f24 = r;
        f24 = FUN_0015cf40(r);
    }
}
