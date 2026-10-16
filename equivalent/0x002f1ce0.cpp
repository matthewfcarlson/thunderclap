// STATUS: equivalent (tools/equiv.py level 3: 2099 inputs, branch coverage 54/60, incomplete)
// FUN_002f1ce0 @ 0x002f1ce0
#include "decls/data/engine/physics.h"

extern "C" double sqrt(double);

struct V3_2f1ce0 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    void FUN_0022d260(const struct Mat4_2f1ce0 *m);
    void FUN_0022d210(const struct Mat4_2f1ce0 *m);
};

struct Mat4_2f1ce0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_2f1ce0 *axis, float angle);
    void FUN_0022c120();
    void FUN_0022cdb0();
};

union Bits_2f1ce0 {
    int i;
    float f;
};

struct Vec_2f1ce0 {
    class Shape_2f1ce0 **begin;
    class Shape_2f1ce0 **end;
};

class Shape_2f1ce0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_2f1ce0 *v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x14 - 0x4];
    Vec_2f1ce0 *f14;
    char pad18[0x34 - 0x18];
    float f34;
    Bits_2f1ce0 f38;
    Bits_2f1ce0 f3c;
    Bits_2f1ce0 f40;
    union {
        V3_2f1ce0 v;
        struct {
            Bits_2f1ce0 f44;
            Bits_2f1ce0 f48;
            Bits_2f1ce0 f4c;
        } b;
    } u44;
    Bits_2f1ce0 f50;
    Bits_2f1ce0 f54;
    Bits_2f1ce0 f58;
    Bits_2f1ce0 f5c;
    Bits_2f1ce0 f60;
    Bits_2f1ce0 f64;
    Bits_2f1ce0 f68;
    Bits_2f1ce0 f6c;
    Bits_2f1ce0 f70;
    Bits_2f1ce0 f74;
};

void __cdecl FUN_00305f00(const V3_2f1ce0 *a, const V3_2f1ce0 *b, V3_2f1ce0 *axis, float *angle);
void __cdecl FUN_002f0120(float q, float ext, float *w, char *flag);
float __cdecl FUN_00083d90(float *p);

struct Frame_2f1ce0 {
    V3_2f1ce0 q;                            // S+0x10
    Bits_2f1ce0 x1c;                        // 0x1c
    union {
        float f20;
        struct {
            char p20[2];
            char flagC;
            char flagB;
        } b;
    } u20;                           // 0x20
    Bits_2f1ce0 f24;                        // 0x24
    V3_2f1ce0 w;                            // 0x28
    union {
        float f34;
        struct {
            char p34[3];
            char flagA;
        } b;
    } u34;                           // 0x34
    Bits_2f1ce0 f38;                        // 0x38
    Bits_2f1ce0 f3c;                        // 0x3c
    Shape_2f1ce0 *ret;                      // 0x40
    Bits_2f1ce0 f44;                        // 0x44
    Mat4_2f1ce0 M;                          // 0x48
    Mat4_2f1ce0 M2;                         // 0x88
};

Shape_2f1ce0 *__cdecl FUN_002f1ce0(const V3_2f1ce0 *p, Shape_2f1ce0 *shape, V3_2f1ce0 *out, float *dist)
{
    Frame_2f1ce0 f;
    f.ret = shape;
    int kind = shape->v6() - 1;
    if (kind > 7)
        return shape;

    if (kind == 6) {
        const V3_2f1ce0 *c = shape->v4();
        out->x = p->x - c->x;
        out->y = p->y - c->y;
        out->z = p->z - c->z;
        float len = out->FUN_0022d110();
        *dist = len;
        if (len <= 0.000001f || len != len) {
            *dist = 0.0f;
            out->y = 0.0f;
            out->z = 0.0f;
            out->x = 1.0f;
            return shape;
        }
        *dist = len - shape->f34;
        return shape;
    }

    if (kind == 7) {
        const V3_2f1ce0 *c = shape->v4();
        out->x = p->x - c->x;
        out->y = p->y - c->y;
        out->z = p->z - c->z;
        *dist = shape->f3c.f * out->y + shape->f40.f * out->z + shape->f38.f * out->x;
        out->x = shape->f38.f;
        out->y = shape->f3c.f;
        out->z = shape->f40.f;
        return shape;
    }

    if (kind == 0) {
        float best = 1.0e9f;
        bool first = true;
        unsigned int i;
        for (i = 0; i < (unsigned int)(shape->f14->end - shape->f14->begin); i++) {
            V3_2f1ce0 tmp;
            Shape_2f1ce0 *r = FUN_002f1ce0(p, shape->f14->begin[i], &tmp, &best);
            if (first) {
                first = false;
                *dist = best + 1.0f;
            }
            if (best < *dist) {
                *dist = best;
                *out = tmp;
                f.ret = r;
            }
        }
        return f.ret;
    }

    if (kind == 1) {
        shape->v4();
        f.q = *p;
        f.M.FUN_0022b980();
        if (shape->f60.i == 0) {
            if (!(DAT_00554c2c & 1)) {
                DAT_00554c2c = DAT_00554c2c | 1;
                (*(V3_2f1ce0*)&DAT_00554c20).x = 0.0f;
                (*(V3_2f1ce0*)&DAT_00554c20).y = 1.0f;
                (*(V3_2f1ce0*)&DAT_00554c20).z = 0.0f;
            }
            float ang;
            FUN_00305f00(&shape->u44.v, ((V3_2f1ce0*)&DAT_00554c20), &f.w, &ang);
            f.M.FUN_0022baf0(&f.w, -ang);
            const V3_2f1ce0 *c = shape->v4();
            f.M.m[12] = c->x;
            f.M.m[13] = c->y;
            f.M.m[14] = c->z;
            f.M2 = f.M;
            f.M2.FUN_0022c120();
            f.q.FUN_0022d210(&f.M2);
        } else {
            const V3_2f1ce0 *c;
            if (shape->f60.i == 3) {
                c = shape->v4();
            } else if (shape->f60.i == 2) {
                float t = f.q.x;
                f.q.x = f.q.y;
                f.q.y = t;
                c = shape->v4();
            } else {
                float t = f.q.z;
                f.q.z = f.q.y;
                f.q.y = t;
                c = shape->v4();
            }
            f.q.x = f.q.x - c->x;
            f.q.y = f.q.y - c->y;
            f.q.z = f.q.z - c->z;
        }
        f.x1c.f = shape->f54.f;
        double r = sqrt(f.q.z * f.q.z + f.q.x * f.q.x);
        if (r < f.x1c.f) {
            f.w.x = f.q.x;
            f.w.z = f.q.z;
        } else {
            double inv = 1.0 / r;
            f.w.x = (float)((f.x1c.f * inv) * f.q.x);
            f.w.z = (float)((inv * f.x1c.f) * f.q.z);
        }
        f.f24.f = -shape->f50.f;
        float cy;
        if (f.q.y < f.f24.f)
            cy = f.f24.f;
        else if (f.q.y < 0.0f)
            cy = f.q.y;
        else if (f.q.y < shape->f50.f)
            cy = f.q.y;
        else
            cy = shape->f50.f;
        out->x = f.q.x - f.w.x;
        out->y = f.q.y - cy;
        out->z = f.q.z - f.w.z;
        *dist = out->FUN_00018990();
        int sel = shape->f60.i;
        if (sel == 0) {
            out->FUN_0022d260(&f.M);
        } else if (sel == 2) {
            float t = out->x;
            out->x = out->y;
            out->y = t;
        } else if (sel == 4) {
            float t = out->z;
            out->z = out->y;
            out->y = t;
        }
        out->FUN_0022d110();
        return shape;
    }

    if (kind == 4) {
        f.q = *p;
        if (shape->f38.i == 0) {
            f.M.FUN_0022b980();
            f.M.m[0] = shape->f54.f;
            f.M.m[1] = shape->f58.f;
            f.M.m[2] = shape->f5c.f;
            f.M.m[4] = shape->f60.f;
            f.M.m[5] = shape->f64.f;
            f.M.m[6] = shape->f68.f;
            f.M.m[8] = shape->f6c.f;
            f.M.m[9] = shape->f70.f;
            f.M.m[10] = shape->f74.f;
            const V3_2f1ce0 *c = shape->v4();
            f.M.m[12] = c->x;
            f.M.m[13] = c->y;
            f.M.m[14] = c->z;
            f.M2 = f.M;
            f.M2.FUN_0022cdb0();
            f.q.FUN_0022d210(&f.M2);
        } else {
            const V3_2f1ce0 *c = shape->v4();
            f.q.x = f.q.x - c->x;
            f.q.y = f.q.y - c->y;
            f.q.z = f.q.z - c->z;
        }
        f.x1c.f = shape->u44.b.f48.f;
        f.f44.f = shape->u44.b.f4c.f;
        f.f38.f = shape->f50.f;
        FUN_002f0120(f.q.x, f.x1c.f, &f.w.x, &f.u34.b.flagA);
        FUN_002f0120(f.q.y, f.f44.f, &f.w.y, &f.u20.b.flagB);
        FUN_002f0120(f.q.z, f.f38.f, &f.w.z, &f.u20.b.flagC);
        char bl = f.u34.b.flagA;
        if (bl && f.u20.b.flagB && f.u20.b.flagC) {
            float *selp = &f.w.x;
            f.f24.f = f.w.x - f.q.x;
            f.f24.i &= 0x7fffffff;
            float val = FUN_00083d90(&f.w.x) * f.x1c.f;
            f.f3c.f = f.w.y - f.q.y;
            f.x1c.f = f.f3c.f;
            f.x1c.i &= 0x7fffffff;
            if (f.x1c.f < f.f24.f) {
                f.f24.f = f.f3c.f;
                f.f24.i &= 0x7fffffff;
                selp = &f.w.y;
                val = FUN_00083d90(&f.w.y) * f.f44.f;
            }
            f.x1c.f = f.w.z - f.q.z;
            f.x1c.i &= 0x7fffffff;
            if (f.x1c.f < f.f24.f) {
                selp = &f.w.z;
                val = FUN_00083d90(&f.w.z) * f.f38.f;
            }
            *selp = val;
        }
        out->x = f.q.x - f.w.x;
        out->y = f.q.y - f.w.y;
        out->z = f.q.z - f.w.z;
        *dist = (float)sqrt(out->z * out->z + out->y * out->y + out->x * out->x);
        if (shape->f38.i == 0)
            out->FUN_0022d260(&f.M);
        out->FUN_0022d110();
        if (bl && f.u20.b.flagB && f.u20.b.flagC)
            *dist = -*dist;
        return shape;
    }
    return shape;
}
