extern "C" double __cdecl sqrt(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

// Gradient noise tables (Perlin's classic init): permutation p, 1-D gradients g1, 2-D gradients g2, 3-D gradients g3.
struct NoiseTables {
    float g1[0x202];
    int p[0x202];
    float g3[0x202][3];
    float g2[0x202][2];
};
extern NoiseTables DAT_0056b7c0;

struct RandState {
    unsigned int s0;
    unsigned int s1;
};
extern RandState *DAT_004e5acc;

static unsigned int Next()
{
    RandState *r = DAT_004e5acc;
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    return (r->s0 << 16) + (r->s1 & 0xffff);
}

struct NoiseInit {
    char start;
    void FUN_003572b0();
};

void NoiseInit::FUN_003572b0()
{
    if (start == 0)
        return;
    NoiseTables &t = DAT_0056b7c0;
    int i = 0;
    do {
        t.p[i] = i;
        t.g1[i] = (float)(Next() % 512 - 255) * 0.00390625f;
        t.g2[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g2[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        {
            float inv = 1.0f / sqrt(t.g2[i][0] * t.g2[i][0] + t.g2[i][1] * t.g2[i][1]);
            t.g2[i][0] = t.g2[i][0] * inv;
            t.g2[i][1] = t.g2[i][1] * inv;
        }
        t.g3[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][2] = (float)(Next() % 512 - 256) * 0.00390625f;
        {
            float inv = 1.0f / sqrt(t.g3[i][0] * t.g3[i][0] + t.g3[i][1] * t.g3[i][1] + t.g3[i][2] * t.g3[i][2]);
            t.g3[i][0] = t.g3[i][0] * inv;
            t.g3[i][1] = t.g3[i][1] * inv;
            t.g3[i][2] = t.g3[i][2] * inv;
        }
        i++;
    } while (i < 0x100);

    while (--i) {
        int k = t.p[i];
        int j = Next() % 256;
        t.p[i] = t.p[j];
        t.p[j] = k;
    }

    memcpy(&t.g1[0x100], &t.g1[0], 0x102 * 4);
    memcpy(&t.p[0x100], &t.p[0], 0x102 * 4);
    for (i = 0; i < 0x102; i++) {
        t.g2[0x100 + i][0] = t.g2[i][0];
        t.g2[0x100 + i][1] = t.g2[i][1];
        t.g3[0x100 + i][0] = t.g3[i][0];
        t.g3[0x100 + i][1] = t.g3[i][1];
        t.g3[0x100 + i][2] = t.g3[i][2];
    }
    start = 0;
}
