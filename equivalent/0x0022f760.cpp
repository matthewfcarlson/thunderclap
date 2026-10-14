// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0022f760 @ 0x0022f760
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

struct Sampler {
    void FUN_0022e890(Vec3* out, float t);
};

extern float DAT_0042760c[5];
extern float DAT_00427620[5];

// equiv-conv: FUN_0022f760 edi stack
float FUN_0022f760(Sampler* s, float t)
{
    float half = t * 0.5f;
    float acc = 0.0f;
    for (int i = 0; i < 5; i++) {
        Vec3 v;
        s->FUN_0022e890(&v, half * DAT_00427620[i] + half);
        acc = (float)(sqrt(v.x * v.x + v.z * v.z + v.y * v.y) * DAT_0042760c[i] + acc);
    }
    return acc * half;
}
