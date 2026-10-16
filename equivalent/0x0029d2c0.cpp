// STATUS: equivalent (tools/equiv.py level 3: 2728 inputs, branch coverage 29/30, incomplete)
// FUN_0029d2c0 @ 0x0029d2c0
#include "decls/data/engine/unknown.h"

struct Vec3_29d2c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Source_29d2c0 {
    char pad0[0x11];
    unsigned char active;
    char pad12[2];
    unsigned int color;
    Vec3_29d2c0 pos;
    float FUN_002a0d00(const Vec3_29d2c0 *p);
    void FUN_002c3f20(float *a, float *b, float *c);
};

struct SourceList {
    char pad0[0x10];
    int size;
    int count;
    Source_29d2c0 **items;
};

struct Particle_29d2c0 {
    float life;
    unsigned int color;
    float radius2;
    Vec3_29d2c0 dir;
    unsigned int mask;
    unsigned int pad1c;
};

struct Pool_29d2c0 {
    SourceList *list;
    Particle_29d2c0 *particles;
};


int __cdecl FUN_0009fa70(const int *value, const int *lo, const int *hi);

class Emitter_29d2c0 {
public:
    char pad0[0x18];
    int active;
    char pad1c[0x34 - 0x1c];
    Pool_29d2c0 *pool;
    float FUN_0029d2c0(const Vec3_29d2c0 *pos, unsigned int mask);
};

float Emitter_29d2c0::FUN_0029d2c0(const Vec3_29d2c0 *pos, unsigned int mask)
{
    float total = 0.0f;
    // Stack slots the original shares: the clamp arguments sit between v2 and d, and the callee's
    // extent over the value slots reaches the neighbouring word.
    struct Locals {
        int hi2;
        float o2, o3;
        int lo1;
        int i;
        float o1;
        int hi1;
        int v2, lo2, v1, hi3, lo3, v0;
        Vec3_29d2c0 d;
    } fr;

    for (fr.i = pool->list->count - 1; fr.i >= 0; fr.i--) {
        int i = fr.i;
        Pool_29d2c0 *p = pool;
        SourceList *l = p->list;
        if (i >= l->size) {
            p->particles[i].life = 0.0f;
            continue;
        }
        Source_29d2c0 *src = l->items[i];
        if (src == 0 || src->active == 0) {
            p->particles[i].life = 0.0f;
            continue;
        }
        if ((p->particles[i].mask & mask) != mask) {
            p->particles[i].life = 0.0f;
            continue;
        }
        Vec3_29d2c0 &d = fr.d;
        d.x = pos->x - src->pos.x;
        d.y = pos->y - src->pos.y;
        d.z = pos->z - src->pos.z;
        Particle_29d2c0 *e = &p->particles[i];
        float dist2 = d.z * d.z + d.y * d.y + d.x * d.x;
        if (dist2 >= e->radius2) {      // NaN falls through, as in the original (test ah,1 / je)
            e->life = 0.0f;
            continue;
        }
        if (dist2 < 1e-8f) {
            e->life = 0.0f;
            continue;
        }
        float w = src->FUN_002a0d00(pos);
        if (w == 0.0f) {
            pool->particles[i].life = 0.0f;
            continue;
        }
        src->FUN_002c3f20(&fr.o1, &fr.o2, &fr.o3);
        float o1 = fr.o1, o2 = fr.o2, o3 = fr.o3;
        float len = d.FUN_0022d110();
        double s;
        if (o2 > 0.0f)
            s = len * o2;
        else if (o3 > 0.0f)
            s = len * len * o3;
        else
            s = o1;

        unsigned int color = (*(unsigned int*)&DAT_004cf730);
        float life = 0.0f;
        if (s > 0.0) {
            unsigned int col = src->color;
            double ratio = w / s;
            int c0 = col & 0xff;
            int c1 = (col >> 8) & 0xff;
            int c2 = (col >> 16) & 0xff;
            int m = c1 >= c0 ? c1 : c0;
            if (!(c2 < m))
                m = c2;
            life = (float)(m * ratio);
            fr.v0 = (int)(c0 * ratio);
            fr.v1 = (int)(c1 * ratio);
            fr.v2 = (int)(c2 * ratio);
            fr.lo1 = 0;
            fr.hi1 = 255;
            fr.hi2 = 255;
            fr.lo2 = 0;
            fr.hi3 = 255;
            fr.lo3 = 0;
            unsigned int r1 = FUN_0009fa70(&fr.v2, &fr.lo1, &fr.hi1);
            color = (r1 | 0xffffff00) << 8;
            color |= FUN_0009fa70(&fr.v1, &fr.lo2, &fr.hi2);
            color <<= 8;
            color |= FUN_0009fa70(&fr.v0, &fr.lo3, &fr.hi3);
        }
        pool->particles[i].color = color;
        pool->particles[i].life = life;
        Particle_29d2c0 *e2 = &pool->particles[i];
        e2->dir.x = d.x;
        e2->dir.y = d.y;
        e2->dir.z = d.z;
        if (life > 0.0f)
            active++;
        total = life + total;
    }
    return total;
}
