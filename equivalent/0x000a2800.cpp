// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 38/40, incomplete)
// FUN_000a2800 @ 0x000a2800
// FUN_000a2800 @ 0x000a2800: search sample directions around a target for the best visible point
#include "decls/data/game/global.h"

extern "C" double sqrt(double);

extern float __cdecl FUN_000a0330(float);
extern float __cdecl FUN_000a02a0(float);
extern int __cdecl FUN_000a0010(float range, float step, int max, float *out);
extern void __cdecl FUN_000a04c0(float *v, float *yaw, float *pitch, float *len);
extern void __cdecl FUN_0009f910(int n, float *keys, int *vals);
extern float *__cdecl FUN_0009f8c0(float *out, float a, float b, float radius);

struct Caster {
    bool FUN_00038e30(int a, float *p, float t, int one, float *o1, float *o2);
};

struct Frame {
    float dist;        // 0x0c
    float best;        // 0x10
    float q[3];        // 0x14
    float b[3];        // 0x20
    union {
        float tmp2c;   // 0x2c
        unsigned tmp2cbits;
    };
    float arr30[4];    // 0x30
    union {
        float len;     // 0x40
        int r;
    };
    int total;         // 0x44
    float pitch;       // 0x48
    float cspill;      // 0x4c
    float yaw;         // 0x50
    float o2[3];       // 0x54
    float o1[3];       // 0x60
    float arr6c[8];    // 0x6c
    float sp[3];       // 0x8c
    int idx[32];       // 0x98
    float cost[32];    // 0x118
};

class Target {
public:
    char pad0[0x194];
    float t0, t1, t2;      // 0x194
    char pad1a0[0x1c4 - 0x1a0];
    float c0, c1, c2;      // 0x1c4
    char pad1d0[0x350 - 0x1d0];
    Caster *caster;        // 0x350
    char pad354[0x468 - 0x354];
    float scale;           // 0x468
    bool FUN_000a2800(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int a7, float *a8, float *a9);
};

bool Target::FUN_000a2800(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int a7, float *a8, float *a9)
{
    Frame f;
    int i, k;
    f.dist = FUN_000a0330(a1 - a0);
    if ((f.dist == 0.0f && a0 != a1) || f.dist > 315.0f)
        f.dist = 315.0f;
    int n = FUN_000a0010(f.dist, 30.0f, 8, f.arr6c);
    for (i = 0; i < n; i++)
        f.arr6c[i] = FUN_000a02a0(a0 + f.arr6c[i]);
    int m = FUN_000a0010(a4 - a3, 20.0f, 4, f.arr30);
    for (i = 0; i < m - 3; i += 4) {
        f.arr30[i] = a3 + f.arr30[i];
        f.arr30[i + 1] = a3 + f.arr30[i + 1];
        f.arr30[i + 2] = a3 + f.arr30[i + 2];
        f.arr30[i + 3] = a3 + f.arr30[i + 3];
    }
    for (; i < m; i++)
        f.arr30[i] = a3 + f.arr30[i];
    if (n <= 0)
        return false;
    if (m <= 0)
        return false;
    f.b[0] = t0 - c0;
    f.b[1] = t1 - c1;
    f.b[2] = t2 - c2;
    FUN_000a04c0(f.b, &f.yaw, &f.pitch, &f.len);
    f.total = m * n;
    for (k = 0; k < f.total; k++) {
        int q = k / m;
        f.r = k % m;
        f.cspill = FUN_000a02a0(f.arr6c[q] - f.yaw);
        f.tmp2cbits = *(unsigned *)&f.cspill & 0x7fffffff;
        f.best = f.arr30[f.r] - f.pitch;
        *(unsigned *)&f.best &= 0x7fffffff;
        f.tmp2c = f.best * 1.5f + f.tmp2c;
        if (a2 >= -180.0f) {
            f.dist = FUN_000a02a0(f.arr6c[q] - a2);
            *(unsigned *)&f.dist &= 0x7fffffff;
            f.cost[k] = f.dist + f.dist + f.tmp2c;
        } else {
            f.cost[k] = f.tmp2c;
        }
        f.idx[k] = k;
    }
    FUN_0009f910(f.total, f.cost, f.idx);
    f.best = 0.0f;
    f.b[0] = 0.0f;
    f.b[1] = 0.0f;
    f.b[2] = 0.0f;
    for (k = 0; k < f.total; k++) {
        f.dist = a6;
        int q = f.idx[k] / m;
        int r = f.idx[k] % m;
        float *p = FUN_0009f8c0(f.sp, f.arr6c[q], f.arr30[r], a6);
        f.q[0] = c0 + p[0];
        f.q[1] = p[1] + c1;
        f.q[2] = p[2] + c2;
        if (caster->FUN_00038e30(a7, f.q, (*(float*)&DAT_0049ecb0), 1, f.o1, f.o2)) {
            float sc = scale;
            f.q[0] = f.o2[0] * sc + f.o1[0];
            f.q[1] = f.o2[1] * sc + f.o1[1];
            f.q[2] = f.o2[2] * sc + f.o1[2];
            f.dist = (float)sqrt((double)((f.q[2] - c2) * (f.q[2] - c2) + (f.q[1] - c1) * (f.q[1] - c1) + (f.q[0] - c0) * (f.q[0] - c0)));
        }
        if (f.dist > f.best) {
            f.best = f.dist;
            f.b[0] = f.q[0];
            f.b[1] = f.q[1];
            f.b[2] = f.q[2];
            if (!(f.dist < a6))
                break;
        }
    }
    if (f.best < a5)
        return false;
    a8[0] = f.b[0];
    a8[1] = f.b[1];
    a8[2] = f.b[2];
    *a9 = f.best;
    return true;
}
