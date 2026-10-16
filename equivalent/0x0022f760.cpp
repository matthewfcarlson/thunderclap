// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0022f760 @ 0x0022f760
#include "decls/data/engine/unknown.h"

extern "C" double sqrt(double);

struct Vec3_22f760 {
    float x, y, z;
};

struct Sampler_22f760 {
    void FUN_0022e890(Vec3_22f760* out, float t);
};


// equiv-conv: FUN_0022f760 edi stack
float FUN_0022f760(Sampler_22f760* s, float t)
{
    float half = t * 0.5f;
    float acc = 0.0f;
    for (int i = 0; i < 5; i++) {
        Vec3_22f760 v;
        s->FUN_0022e890(&v, half * ((float*)&DAT_00427620)[i] + half);
        acc = (float)(sqrt(v.x * v.x + v.z * v.z + v.y * v.y) * ((float*)&DAT_0042760c)[i] + acc);
    }
    return acc * half;
}
