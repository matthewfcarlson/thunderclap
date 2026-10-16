// STATUS: equivalent (tools/equiv.py level 3: 351 inputs, branch coverage 46/50, incomplete)
// FUN_000c9810 @ 0x000c9810
#include "decls/address.h"
#include "decls/data/game/global.h"
struct V3_c9810 {
    float x, y, z;
};

struct V2_c9810 {
    float x, y;
};

struct Mat4_c9810 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const V3_c9810 *pos);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022bab0(float angle);
};

struct Planar {
    float x, y, z;
    void FUN_0022d260(const Mat4_c9810 *m);
};

struct Body_c9810 {
    char pad0[0x10];
    void *f10;
    char FUN_00035550_dummy;
};

struct Probe_c9810 {
    void FUN_00035550(V3_c9810 *out);
    float FUN_00035690();
};

struct WorldSub {
    Probe_c9810 *FUN_00024280(int a, int b);
};

struct Slots_c9810 {
    void FUN_001e5bc0(int handle);
    void FUN_001dd470(int handle, Mat4_c9810 *m, int z);
};

struct World {
    char pad0[0xc];
    Slots_c9810 *f0c;
    char pad10[0x20 - 0x10];
    WorldSub *f20;
};

struct Shot_c9810 {
    int id;                // 0
    V3_c9810 pos;                // 4
    V2_c9810 v10;                // 0x10
    Planar w;              // 0x18
    char pad24[0x28 - 0x24];
    int a28;
    int b2c;
    char pad30[0x3c - 0x30];
    char flag3c;
    char pad3d[3];
};

struct Fx_c9810 {
    int active;            // 0
    char pad4[0x18 - 4];
    float f18, f1c, f20;
    V3_c9810 euler;              // 0x24
    int handle;            // 0x30
    char pad34[4];
};

class Tracker_c9810 {
public:
    char pad0[0x10];
    void *f10;
    char pad14[0x20 - 0x14];
    char f20;
    char pad21[0x21c - 0x21];
    float f21c;
    float f220;
    char b224;
    char pad225[0x258 - 0x225];
    Shot_c9810 shots[0x80];
    Fx_c9810 fx[0x20];
    char b2958;
    char b2959;

    char FUN_000c8550(int idx, V3_c9810 *out);
    char FUN_000c8630(int idx, V3_c9810 *out);
    void FUN_000c9720(V3_c9810 v);
    V2_c9810 *FUN_000c9460(V2_c9810 *out, V3_c9810 v);
    void FUN_000c9100(int idx);
    void FUN_000c8f50(float v);
    void FUN_000c9810(float dt);
};

struct Frame_c9810 {
    union {
        V3_c9810 out;
        V2_c9810 ret;
        V3_c9810 euler;
    } u;                   // 0x10
    V3_c9810 tmp;                // 0x1c
    V3_c9810 p;                  // 0x28
    Mat4_c9810 mat;              // 0x34
};

void Tracker_c9810::FUN_000c9810(float dt)
{
    if (f10 == 0)
        return;
    Frame_c9810 f;
    int i;
    if (f20 == 1) {
        int idx = 0;
        for (i = 0; i < 0x80; i++) {
            if (shots[i].flag3c == 1) {
                idx = i;
                break;
            }
        }
        if (FUN_000c8550(idx, &f.u.out) == 1)
            FUN_000c9720(f.u.out);
    }

    f220 = dt + f220;
    for (i = 0; i < 0x80; i++) {
        Shot_c9810 *s = &shots[i];
        if (s->id == -1)
            continue;
        if (!FUN_000c8550(i, &f.tmp)) {
            FUN_000c9100(i);
            continue;
        }
        s->pos = f.tmp;
        V2_c9810 *r = FUN_000c9460(&f.u.ret, f.tmp);
        s->v10.x = r->x;
        s->v10.y = r->y;
        if (s->id != 0)
            continue;
        Probe_c9810 *probe = DAT_004dd700->f20->FUN_00024280(s->a28, s->b2c);
        probe->FUN_00035550(&f.p);
        f.mat.FUN_0022b980();
        f.mat.FUN_0022bab0(4.712389f);
        s->w.x = f.p.x;
        s->w.y = f.p.z;
        s->w.z = 0.0f;
        s->w.FUN_0022d260(&f.mat);
        if (!b2958)
            continue;
        float t = probe->FUN_00035690();
        if ((t > DAT_0049fbcc && f21c < DAT_0049fbd0) || (t < DAT_0049fbd0 && f21c > DAT_0049fbcc)) {
            f21c = t;
            f220 = 0.0f;
            b224 = 0;
            b2959 = 0;
        }
        if (b2959) {
            f220 = DAT_0049fbd4;
            b224 = 0;
        }
        if (!b224 && f220 >= DAT_0049fbd4) {
            if (t > DAT_0049fbcc)
                FUN_000c8f50(DAT_0049fbbc);
            else
                FUN_000c8f50(DAT_0049fbb8);
        }
    }

    for (i = 0; i < 0x20; i++) {
        Fx_c9810 *e = &fx[i];
        if (e->active == 0)
            continue;
        if (!FUN_000c8630(i, &f.tmp)) {
            if (i < 0 || i >= 0x20)
                continue;
            if (e->active == 0)
                continue;
            DAT_004dd700->f0c->FUN_001e5bc0(e->handle);
            e->handle = -1;
            e->active = 0;
            continue;
        }
        f.p.x = f.tmp.x + e->f18;
        f.u.euler = e->euler;
        f.p.y = f.tmp.y + e->f1c;
        f.p.z = f.tmp.z + e->f20;
        f.mat.FUN_0022b980();
        f.mat.FUN_0022be40(&f.p);
        f.mat.FUN_0022bc20(f.u.euler.x * 0.017453292f, f.u.euler.y * 0.017453292f, f.u.euler.z * 0.017453292f);
        DAT_004dd700->f0c->FUN_001dd470(e->handle, &f.mat, 0);
    }
}
