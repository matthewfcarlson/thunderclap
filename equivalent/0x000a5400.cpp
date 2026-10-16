// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_000a5400 @ 0x000a5400
#include "decls/data/game/global.h"

struct V3_a5400 {
    float x, y, z;
};


V3_a5400 *__cdecl FUN_0009f8c0(V3_a5400 *out, float a, float b, float c);
void __cdecl FUN_000a04c0(V3_a5400 *dir, float *p1, float *p0, float *scratch);

struct Sampler_a5400 {
    bool FUN_000a2370(int a, float *dx, float *dy, char *flag);
};

class Mover_a5400 {
public:
    char pad0[0x194];
    float f194;
    float f198;
    float f19c;
    char pad1a0[0x1c4 - 0x1a0];
    float f1c4;
    float f1c8;
    float f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8;
    float f1ec;
    float f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    char pad214[0x32c - 0x214];
    Sampler_a5400 sampler;
    char pad32d[0x444 - 0x32d];
    float f444;
    unsigned f448;
    char pad44c[0x478 - 0x44c];
    float f478;
    float f47c;
    float f480;
    unsigned f484;
    float f488;

    void FUN_000a0dc0(int zero, float t, int arg);
    void FUN_000a0940(float t);
    void FUN_000a5400(int arg, int flagWord);
};

void Mover_a5400::FUN_000a5400(int arg, int flagWord)
{
    struct {
        float dx;
        float dy;
        V3_a5400 out;
    } fr;
    float t;

    FUN_000a0dc0(0, DAT_0049ec7c, flagWord);
    if (sampler.FUN_000a2370(flagWord, &fr.dx, &fr.dy, (char *)&flagWord)) {
        f478 = fr.dx + f478;
        f47c = fr.dy + f47c;
        float v = f47c;
        if (!(v >= -40.0f))
            v = -40.0f;
        else if (!(v <= 60.0f))
            v = 60.0f;
        f47c = v;
        if (*(char *)&flagWord)
            f488 = (*(float*)&DAT_0049ec98);
    }
    t = f444;
    f480 = t;
    f484 = f448;
    V3_a5400 *p = FUN_0009f8c0(&fr.out, f478, f47c, t);
    f19c = f1cc + p->z;
    f194 = f1c4 + p->x;
    f198 = f1c8 + p->y;
    FUN_000a0940((*(float*)&DAT_0049ec80));
    fr.out.x = f1e8 - f194;
    fr.out.y = f1ec - f198;
    fr.out.z = f1f0 - f19c;
    FUN_000a04c0(&fr.out, &f210, &f20c, &t);
}
