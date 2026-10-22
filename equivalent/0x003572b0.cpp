// STATUS: equivalent (tools/equiv.py level 3: 19873 inputs, branch coverage 21/22, incomplete)
// FUN_003572b0 @ 0x003572b0
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"

extern "C" double __cdecl sqrt(double);

// Gradient noise tables (Perlin's classic init): permutation p, 1-D gradients g1, 2-D gradients g2, 3-D gradients g3.
struct NoiseTables {
    float g1[0x202];
    int p[0x202];
    float g3[0x202][3];
    float g2[0x202][2];
};

struct RandState {
    unsigned int s0;
    unsigned int s1;
};

static unsigned int Next()
{
    RandState *r = (*(RandState**)&DAT_004e5acc);
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    return (r->s0 << 16) + (r->s1 & 0xffff);
}

// Perlin's normalize2/normalize3: the components are read back from the table (rounded), and the divisions by
// the length are one reciprocal 1/s (unrounded) and multiplies, as the original computes them.
static void normalize2(float v[2])
{
    double r = 1.0f / sqrt(v[0] * v[0] + v[1] * v[1]);
    v[0] = (float)(v[0] * r);
    v[1] = (float)(v[1] * r);
}

static void normalize3(float v[3])
{
    double r = 1.0f / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] = (float)(v[0] * r);
    v[1] = (float)(v[1] * r);
    v[2] = (float)(v[2] * r);
}

struct NoiseInit {
    char start;
    void FUN_003572b0();
};

void NoiseInit::FUN_003572b0()
{
    if (start == 0)
        return;
    NoiseTables &t = (*(NoiseTables*)&DAT_0056b7c0);
    int i = 0;
    do {
        t.p[i] = i;
        t.g1[i] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g2[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g2[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        normalize2(t.g2[i]);
        t.g3[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][2] = (float)(Next() % 512 - 256) * 0.00390625f;
        normalize3(t.g3[i]);
        i++;
    } while (i < 0x100);

    while (--i) {
        int k = t.p[i];
        int j = Next() % 256;
        t.p[i] = t.p[j];
        t.p[j] = k;
    }

    // forward word copies (the original's rep movsd): the last two words read entries this copy just wrote
    // (0x100 and 0x101), which a memcpy of overlapping ranges does not promise
    for (i = 0; i < 0x102; i++)
        t.g1[0x100 + i] = t.g1[i];
    for (i = 0; i < 0x102; i++)
        t.p[0x100 + i] = t.p[i];
    for (i = 0; i < 0x102; i++) {
        t.g2[0x100 + i][0] = t.g2[i][0];
        t.g2[0x100 + i][1] = t.g2[i][1];
        t.g3[0x100 + i][0] = t.g3[i][0];
        t.g3[0x100 + i][1] = t.g3[i][1];
        t.g3[0x100 + i][2] = t.g3[i][2];
    }
    start = 0;
}
