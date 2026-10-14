// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 77/78, incomplete)
// FUN_000b30c0 @ 0x000b30c0
extern float DAT_00406094[];

class Item {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9(int mode);
};

union Cell {
    Item *item;
    int mode;
};

union FS {
    float f;
    unsigned int u;
};

class Blender {
public:
    char pad000[0x54];
    int mode;                        // 0x54
    char pad58[0x490 - 0x58];
    float lo;                        // 0x490
    float hi;                        // 0x494
    float lo2;                       // 0x498
    float hi2;                       // 0x49c

    void FUN_000b30c0(int groups, int pairs, int *counts, Item ***items, Cell *cells, Item *single,
                       float *out1, float *out2, float *out3);
};

// The original keeps the normalised value unrounded on the FPU stack, so these are inlined helpers.
static __forceinline float Normalise(const Blender *b, float v)
{
    if (v < b->lo)
        return 0.0f;
    if (v > b->hi)
        return 1.0f;
    return (v - b->lo) / (b->hi - b->lo);
}

static __forceinline float Ratio(const Blender *b, float a, float range)
{
    if (a < b->lo2)
        return 0.0f;
    if (!(a < b->hi2))
        return 1.0f / a;
    return ((a - b->lo2) / range) / a;
}

// Shrink factor for an (x, y) pair: derived from its larger magnitude.
static __forceinline float PickRatio(const Blender *b, float ax, float ay, float range)
{
    float m = 0.0f;
    float r1 = 0.0f;
    if (ax > 0.0f) {
        m = ax;
        r1 = Ratio(b, ax, range);
    }
    if (ay > m)
        return Ratio(b, ay, range);
    return r1;
}

void Blender::FUN_000b30c0(int groups, int pairs, int *counts, Item ***items, Cell *cells, Item *single,
                            float *out1, float *out2, float *out3)
{
    int i;
    for (i = 0; i < groups; i++) {
        float t = 0.0f;
        int n = counts[i * 2];
        for (int j = 0; j < n; j++) {
            Item *it = items[i][j];
            if (it == 0) {
                t = 0.0f;
            } else {
                float v = it->v9(0);
                t = Normalise(this, v);
            }
            FS ad;
            ad.f = t;
            ad.u &= 0x7fffffff;
            if (!(ad.f <= 1e-5f))
                break;
        }
        out1[i] = t;
    }

    float t6;
    if (single == 0) {
        t6 = 0.0f;
    } else {
        float v = single->v9(0);
        t6 = Normalise(this, v);
    }
    float scale = 1.0f;
    FS a6;
    a6.f = t6;
    a6.u &= 0x7fffffff;
    if (!(a6.f <= 1e-5f))
        scale = 0.5f;

    if (mode == 2 && out3 != 0) {
        for (int p = 0; p < pairs; p++) {
            for (int e = 0; e < 2; e++) {
                float acc = 0.0f;
                for (int k = 0; k < 3; k++) {
                    Item *it = cells[p * 12 + e * 3 + k].item;
                    if (it != 0)
                        acc = it->v9(0) + acc;
                }
                if (p == 0) {
                    if (e == 0)
                        out3[0] = acc;
                    else if (e == 1)
                        out3[1] = acc;
                }
            }
        }
        return;
    }

    {
        float *dst = out2;
        for (int p = 0; p < pairs; p++) {
            for (int e = 0; e < 2; e++) {
                float sum = 0.0f;
                for (int k = 0; k < 3; k++) {
                    Item *it = cells[p * 12 + e * 3 + k].item;
                    if (it != 0) {
                        float w = it->v9(0);
                        int m = cells[p * 12 + 6 + e * 3 + k].mode;
                        if (m == 0)
                            sum = w * DAT_00406094[k] + sum;
                        else if (m == 1)
                            sum = Normalise(this, w) * DAT_00406094[k] + sum;
                    }
                }
                *dst = sum;
                dst++;
            }
        }
    }

    float range = hi2 - lo2;
    for (int p = 0; p < pairs; p++) {
        float *xy = out2 + p * 2;
        FS ax;
        ax.f = xy[0];
        ax.u &= 0x7fffffff;
        FS ay;
        ay.f = xy[1];
        ay.u &= 0x7fffffff;
        xy[0] = scale * PickRatio(this, ax.f, ay.f, range) * xy[0];
        xy[1] = PickRatio(this, ax.f, ay.f, range) * xy[1] * scale;
    }
}
