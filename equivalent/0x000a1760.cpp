// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000a1760 @ 0x000a1760
#include "decls/data/game/global.h"

struct Vec3_a1760 { float x, y, z; };

float FUN_000a02a0(float v);
Vec3_a1760* FUN_0009f8c0(Vec3_a1760* out, float x, float y, float z);
void FUN_000a04c0(Vec3_a1760* d, float* a, float* b, float* c);

class Mover_a1760 {
public:
    char pad000[0x194];
    float f194, f198, f19c;
    char pad1a0[0x24];
    float f1c4, f1c8, f1cc;
    char pad1d0[0x18];
    float f1e8, f1ec, f1f0;
    char pad1f4[0x18];
    float f20c, f210;
    char pad214[0x10c];
    int f320;
    char pad324[4];
    int f328;
    char pad32c[0x68];
    float f394, f398, f39c, f3a0, f3a4, f3a8, f3ac, f3b0;
    char pad3b4[0x94];
    int f448;
    char pad44c[0x2c];
    float f478, f47c;
    int f480, f484;

    void FUN_000a0dc0(float, float, float);
    void FUN_000a0940(float);
    void Update(float a1, float a2);
};

void Mover_a1760::Update(float a1, float a2) {
    float px, py, pz;
    if (f394 <= 0.0f) {
        px = f3a0;
        py = f3a8;
        *(int*)&pz = *(int*)&f3b0;
        f478 = f3a0;
        f47c = f3a8;
        f480 = *(int*)&f3b0;
        f484 = f448;
        f394 = 0.0f;
        f320 = f328;
    } else {
        float w = (1.0f - f394 / f398);
        w = (2.0f - w) * w;
        px = FUN_000a02a0(f3a0 - f39c) * w + f39c;
        py = (f3a8 - f3a4) * w + f3a4;
        pz = (f3b0 - f3ac) * w + f3ac;
        f394 = f394 - a2;
    }
    Vec3_a1760 t;
    Vec3_a1760* r = FUN_0009f8c0(&t, px, py, pz);
    f194 = r->x + f1c4;
    f198 = r->y + f1c8;
    f19c = r->z + f1cc;
    FUN_000a0dc0((*(float*)&DAT_0049ec78), DAT_0049ec7c, a2);
    FUN_000a0940((*(float*)&DAT_0049ec80));
    Vec3_a1760 d;
    d.x = f1e8 - f194;
    d.y = f1ec - f198;
    d.z = f1f0 - f19c;
    FUN_000a04c0(&d, &f210, &f20c, &a2);
}
