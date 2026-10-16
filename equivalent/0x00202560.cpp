// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// FUN_00202560 @ 0x00202560
#include "decls/address.h"
struct Vec3_202560 {
    float x, y, z;
};

struct Quad_202560;

struct Hit_202560 {
    float dist;
    Quad_202560 *quad;
    int tri;
};

struct Quad_202560 {
    char pad0[0x18];
    int material;
};

struct Probe_202560 {
    int f0;
    int f4;
    Hit_202560 *hit;
};

struct Trace {
    char pad0[8];
    Probe_202560 probe;
    char FUN_00201f20(Vec3_202560 *from, int a, Vec3_202560 *out, Vec3_202560 *normal, int *c, int zero);
};

struct Collider_202560 {
    char FUN_002ee140(Probe_202560 *probe, Vec3_202560 *from, Vec3_202560 *to, int zero);
};

struct Bridge {
    char pad0[8];
    Collider_202560 *collider;
};

struct Hud_202560 {
    void FUN_00025370(int a);
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad0[0x10];
    Bridge *bridge;
    char pad14[0xc];
    Hud_202560 *hud;
    Trace *trace;
};

extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern float DAT_00554c18;

char FUN_002020a0(int material);
void FUN_002f1ce0(Vec3_202560 *from, int tri, Vec3_202560 *normal, float *out);

char FUN_00202560(Vec3_202560 *start, float depth, int a3, Vec3_202560 *result, Vec3_202560 *normalOut,
                  Vec3_202560 *fallback, int *materialOut, int *c)
{
    World *g = DAT_004dd700;
    Trace *trace = g->trace;
    if (materialOut != 0)
        *materialOut = 0;

    result->x = start->x;
    result->y = start->y;
    result->z = start->z;
    result->y = -3.4028235e+38f;

    char ok = trace->FUN_00201f20(start, a3, result, normalOut, c, 0);
    if (fallback != 0) {
        if (ok) {
            fallback->x = result->x;
            fallback->y = result->y;
            fallback->z = result->z;
        } else {
            fallback->x = start->x;
            fallback->y = start->y;
            fallback->z = start->z;
            fallback->y = -3.4028235e+38f;
        }
    }

    trace->probe.f0 = 0;
    DAT_004d2a3c = 2;
    DAT_004d2a40 = 0;
    DAT_00554c1c = 1;
    DAT_00554c18 = 0.2f;
    g->hud->FUN_00025370(0);

    float zero = depth * 0.0f;
    Vec3_202560 to;
    to.y = -depth;
    to.z = zero;
    to.x = zero + start->x;
    to.y = to.y + start->y;
    to.z = to.z + start->z;

    if (g->bridge->collider->FUN_002ee140(&trace->probe, start, &to, 0)) {
        Hit_202560 *hit = trace->probe.hit;
        float dist = hit->dist;
        Quad_202560 *quad = hit->quad;
        int tri = hit->tri;
        if (dist > 0.0f && FUN_002020a0(quad->material)) {
            Vec3_202560 n;
            float out = 0.0f;
            FUN_002f1ce0(start, tri, &n, &out);
            if ((n.z * 0.0f + n.x * 0.0f) + n.y > 0.5f) {
                float w = out * 0.0f;
                float px = w + start->x;
                float py = -out + start->y;
                float pz = w + start->z;
                if (py > result->y) {
                    result->x = px;
                    result->y = py;
                    result->z = pz;
                    normalOut->x = n.x;
                    normalOut->y = n.y;
                    normalOut->z = n.z;
                    if (materialOut != 0)
                        *materialOut = quad->material;
                    if (c != 0)
                        *c = 0;
                    ok = 1;
                }
            }
        }
    }
    g->hud->FUN_00025260(1, 0, 0);
    return ok;
}
