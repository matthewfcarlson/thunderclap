// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 42/42)
// FUN_002a5fd0 @ 0x002a5fd0
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"

struct V2_2a5fd0 {
    float x, y;
};

struct V3_2a5fd0 {
    float x, y, z;
};

struct Noise {
    float FUN_00356fa0(const V3_2a5fd0 *v);
    float FUN_00356e50(const V2_2a5fd0 *v);
};

Noise *FUN_003576d0();

struct SrcMesh {
    char pad0[0xc];
    int n;
    char pad10[0x18 - 0x10];
    V3_2a5fd0 *pos;
    char pad1c[0x38 - 0x1c];
    V2_2a5fd0 *uv[4];
    unsigned int *col;
};

struct DstMesh {
    char pad0[0x18];
    V3_2a5fd0 *pos;
    char pad1c[0x38 - 0x1c];
    V2_2a5fd0 *uv[4];
    unsigned int *col;
};

struct Params {
    float tscale;
    float posScale;
    float colScale;
    float alphaScale;
    float uvScale;
};

static float Clamp01(float v)
{
    if (v >= 0.0f && v <= 1.0f)
        return v;
    if (v > 1.0f)
        return 1.0f;
    return 0.0f;
}

struct Frame_2a5fd0 {
    char pad0[0x10];
    int tmp10;                  // 10
    float tp;                   // 14
    Noise *noise;               // 18
    float v2;                   // 1c
    unsigned char *qptr;        // 20
    float g4;                   // 24 (also &uv.v)
    V3_2a5fd0 *dstcur;                 // 28
    unsigned int *Q;            // 2c
    float v1;                   // 30
    float v0;                   // 34
    float f1;                   // 38
    float f2;                   // 3c
    char pad40[4];
    float g3;                   // 44
    int diff;                   // 48
    int flags40;                // 4c
    unsigned int *R;            // 50
    int flags10;                // 54
    float uva;                  // 58
    char pad5c[4];
    float g2;                   // 60
    float g1;                   // 64
    V2_2a5fd0 uvq;                     // 68
    V2_2a5fd0 uvp;                     // 70
    V2_2a5fd0 *bs[4];                  // 78
    V2_2a5fd0 w88;                     // 88
    V3_2a5fd0 w90;                     // 90
    V3_2a5fd0 w9c;                     // 9c
    V3_2a5fd0 wa8;                     // a8
    V3_2a5fd0 wb4;                     // b4
    V3_2a5fd0 wc0;                     // c0
    V3_2a5fd0 wcc;                     // cc
    V2_2a5fd0 *as_[4];                 // d8
};

void FUN_002a5fd0(float t, SrcMesh *a, DstMesh *b, unsigned int flags, Params *c)
{
    Frame_2a5fd0 f;
    f.tp = t * c->tscale;
    f.dstcur = 0;
    V3_2a5fd0 *dst0 = b->pos;
    f.Q = a->col;
    f.R = b->col;
    f.as_[0] = a->uv[0];
    f.bs[0] = b->uv[0];
    f.as_[1] = a->uv[1];
    f.bs[1] = b->uv[1];
    f.as_[2] = a->uv[2];
    f.bs[2] = b->uv[2];
    f.as_[3] = a->uv[3];
    f.bs[3] = b->uv[3];
    int n = a->n;
    V3_2a5fd0 *src0 = a->pos;
    f.noise = FUN_003576d0();
    if (n == 0)
        return;
    f.flags40 = flags & 0x40;
    f.flags10 = flags & 0x10;
    f.dstcur = dst0 + n;
    f.qptr = (unsigned char *)f.Q + n * 4 + 1;
    V3_2a5fd0 *s = src0 + n;
    int i = n;
    hulk_freg s2 = 0.0f;
    do {
        i--;
        f.dstcur = f.dstcur - 1;
        f.qptr = f.qptr - 4;
        s = s - 1;
        if (f.flags10) {
            f.wcc.x = f.tp;
            f.wcc.y = s->y;
            f.wcc.z = s->z;
            f.f1 = f.noise->FUN_00356fa0(&f.wcc);
            f.wc0.x = s->x;
            f.wc0.y = f.tp;
            f.wc0.z = s->z;
            f.f2 = f.noise->FUN_00356fa0(&f.wc0);
            f.w90.x = s->x;
            f.w90.y = s->y;
            f.w90.z = f.tp;
            hulk_freg f3 = f.noise->FUN_00356fa0(&f.w90);
            s2 = c->posScale;
            volatile float m1 = f.f1 * s2;
            volatile float m2 = f.f2 * s2;
            hulk_freg m3 = f3 * s2;
            f.dstcur->x = m1 + s->x;
            f.dstcur->y = m2 + s->y;
            f.dstcur->z = m3 + s->z;
        }
        if (f.flags40 != 0 && f.Q != 0) {
            unsigned char *q = f.qptr;
            unsigned int ch2 = q[1];
            unsigned int ch1 = q[0];
            unsigned int ch0 = q[-1] & 0xff;
            unsigned int ch3 = q[2];
            const hulk_freg k = 0.003921569f;
            f.v2 = (float)(int)ch2 * k;
            f.v1 = (float)(int)ch1 * k;
            f.v0 = (float)(int)ch0 * k;
            hulk_freg v3 = (float)(int)ch3 * k;
            f.wb4.x = f.tp;
            f.wb4.y = f.v1;
            f.wb4.z = f.v0;
            hulk_freg Fa = f.noise->FUN_00356fa0(&f.wb4);
            volatile float G1 = Fa * c->colScale;
            f.w9c.x = f.v2;
            f.w9c.y = f.tp;
            f.w9c.z = f.v0;
            hulk_freg Fb = f.noise->FUN_00356fa0(&f.w9c);
            volatile float G2 = Fb * c->colScale;
            f.wa8.x = f.v2;
            f.wa8.y = f.v1;
            f.wa8.z = f.tp;
            hulk_freg Fc = f.noise->FUN_00356fa0(&f.wa8);
            volatile float G3 = Fc * c->colScale;
            f.w88.x = v3;
            f.w88.y = f.tp;
            hulk_freg Fd = f.noise->FUN_00356e50(&f.w88);
            volatile float G4 = Fd * c->alphaScale;
            hulk_freg T1 = Clamp01(G1 + f.v2);
            hulk_freg T2 = Clamp01(G2 + f.v1);
            hulk_freg T3 = Clamp01(G3 + f.v0);
            hulk_freg T4 = Clamp01(G4 + v3);
            unsigned int col = (int)(T4 * 255.0f);
            col <<= 8;
            col |= (int)(T1 * 255.0f);
            col <<= 8;
            col |= (int)(T2 * 255.0f);
            col <<= 8;
            col |= (int)(T3 * 255.0f);
            f.R[i] = col;
        }
        for (int k = 0; k < 4; k++) {
            if ((((unsigned int*)&DAT_0042d9c0)[k] & flags) != 0 && f.as_[k] != 0 && f.bs[k] != 0) {
                f.uvp.x = f.as_[k][i].x;
                f.uvp.y = f.tp;
                volatile float Fu = f.noise->FUN_00356e50(&f.uvp);
                f.uvq.x = f.as_[k][i].y;
                f.uvq.y = f.tp;
                hulk_freg Fv = f.noise->FUN_00356e50(&f.uvq);
                hulk_freg s3 = c->uvScale;
                volatile float mu = Fu * s3;
                hulk_freg mv = Fv * s3;
                f.bs[k][i].x = f.as_[k][i].x + mu;
                f.bs[k][i].y = f.as_[k][i].y + mv;
            }
        }
    } while (i != 0);
}
