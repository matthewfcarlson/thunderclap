// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 12/12)
// hulkfight::motion::WorldConeDamageAction::vfunc_5 @ 0x00143df0
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "decls/address.h"

struct V3_143df0 {
    float x, y, z;
};

struct Mat4_143df0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bec0(const V3_143df0 *a, const V3_143df0 *b);
    void FUN_0022be40(const V3_143df0 *pos);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(const Mat4_143df0 *a, const Mat4_143df0 *b);
    void FUN_0022c2b0(V3_143df0 *in, V3_143df0 *out);
    void FUN_0022c3b0(V3_143df0 *in, V3_143df0 *out);
};

struct SkelXf {
    Mat4_143df0 *FUN_00221c40();
};

struct Skel_143df0 {
    char pad0[0x10];
    SkelXf xf;
};

struct Clock_143df0 {
    Skel_143df0 *FUN_00059a40();
};

struct Target_143df0 {
    Clock_143df0 *FUN_000592a0();
};

struct Rng_143df0 {
    int FUN_00011380(int lo, int hi);
    float FUN_000787e0(float lo, float hi);
    float FUN_00143100();
};
Rng_143df0 *FUN_000964d0();

struct Cone {
    char pad0[0x10];
    V3_143df0 c10;
    V3_143df0 c1c;
    V3_143df0 c28;
    float f34;
    float f38;
    float f3c;
    float f40;
    int i44;
    int i48;
    float f4c;
    float f50;
    int n54;
};

struct HitObj;

struct RayCaster {
    char FUN_00202460(V3_143df0 *pos, V3_143df0 *dir, float range, int one, V3_143df0 *out1, V3_143df0 *out2, HitObj **obj, int *id);
};

struct DamageSys {
    void FUN_001f6cd0(HitObj *obj, int id, V3_143df0 *p1, V3_143df0 *p2, V3_143df0 *dir, int n, float r1, float r2, float *z, int zero);
};

struct World {
    char pad0[0x24];
    RayCaster *f24;
    char pad28[0x38 - 0x28];
    DamageSys *f38;
};

struct Frame_143df0 {
    int i;                 // 0x10
    V3_143df0 tmp;                // 0x14
    float elev;            // 0x20
    int hitId;             // 0x24
    HitObj *hitObj;        // 0x28
    char pad2c[0x38 - 0x2c];
    float range;           // 0x38
    float r;               // 0x3c
    float a;               // 0x40
    int n;                 // 0x44
    float f4cCopy;         // 0x48
    float a0;              // 0x4c
    float step;            // 0x50
    float f50Copy;         // 0x54
    V3_143df0 dir;                // 0x58
    V3_143df0 up;                 // 0x64
    V3_143df0 w4;                 // 0x70
    V3_143df0 out2;               // 0x7c
    V3_143df0 out1;               // 0x88
    V3_143df0 w1;                 // 0x94
    V3_143df0 w3;                 // 0xa0
    V3_143df0 w2;                 // 0xac
    Mat4_143df0 a4;               // 0xb8
    Mat4_143df0 t;                // 0xf8
    Mat4_143df0 rot;              // 0x138
    Mat4_143df0 m0;               // 0x178
};

bool hulkfight::motion::WorldConeDamageAction::vfunc_5(hulk_intptr mode, int unused) {
    if (mode != 1)
        return true;
    Frame_143df0 f;
    f.n = (*(Cone * *)&this->f_1c)->n54;
    if (f.n <= 0)
        return false;
    Mat4_143df0 *src = (*(Target_143df0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a40()->xf.FUN_00221c40();
    f.m0 = *src;
    f.hitId = 0;
    f.hitObj = 0;
    f.a4.FUN_0022b980();
    f.up = (*(Cone * *)&this->f_1c)->c28;
    f.tmp.x = -(*(Cone * *)&this->f_1c)->c1c.x;
    f.tmp.y = -(*(Cone * *)&this->f_1c)->c1c.y;
    f.tmp.z = -(*(Cone * *)&this->f_1c)->c1c.z;
    f.a4.FUN_0022bec0(&f.tmp, &f.up);
    f.tmp = (*(Cone * *)&this->f_1c)->c10;
    f.a4.FUN_0022be40(&f.tmp);
    Rng_143df0 *rng = FUN_000964d0();
    int count = rng->FUN_00011380((*(Cone * *)&this->f_1c)->i44, (*(Cone * *)&this->f_1c)->i48);
    f.i = count;
    f.step = 0.017453292f / count * 360.0f;
    f.dir.x = 0.0f;
    f.dir.y = 0.0f;
    f.dir.z = -(*(Cone * *)&this->f_1c)->f3c;
    f.a0 = rng->FUN_000787e0(0.0f, 6.2831855f);
    f.i = 0;
    for (f.i = 0; f.i < count; f.i++) {
        f.elev = rng->FUN_000787e0((*(Cone * *)&this->f_1c)->f34 * 57.295776f, (*(Cone * *)&this->f_1c)->f38 * 57.295776f);
        f.a = f.a0 + (rng->FUN_00143100() * 0.2f + f.i * f.step);
        f.f50Copy = (*(Cone * *)&this->f_1c)->f50;
        f.f4cCopy = (*(Cone * *)&this->f_1c)->f4c;
        f.r = rng->FUN_000787e0((*(Cone * *)&this->f_1c)->f4c, (*(Cone * *)&this->f_1c)->f50);
        f.rot.FUN_0022b980();
        f.rot.FUN_0022bc20(f.elev * 0.017453292f, 0.0f, f.a);
        f.t.FUN_0022ca90(&f.rot, &f.a4);
        f.t.FUN_0022c2b0(&f.dir, &f.w1);
        f.tmp.x = 0.0f;
        f.tmp.y = 0.0f;
        f.tmp.z = -1.0f;
        f.t.FUN_0022c3b0(&f.tmp, &f.w2);
        f.m0.FUN_0022c2b0(&f.w1, &f.w3);
        f.m0.FUN_0022c3b0(&f.w2, &f.w4);
        f.range = (*(Cone * *)&this->f_1c)->f40;
        if (DAT_004dd700->f24->FUN_00202460(&f.w3, &f.w4, f.range, 1, &f.out1, &f.out2, &f.hitObj, &f.hitId)) {
            if (f.hitObj != 0) {
                HitObj *obj = f.hitObj;
                int id = f.hitId;
                f.elev = 0.0f;
                DAT_004dd700->f38->FUN_001f6cd0(obj, id, &f.out1, &f.out2, &f.w4, f.n - 1, f.r, f.r, &f.elev, 0);
            }
        }
    }
    return true;
}
