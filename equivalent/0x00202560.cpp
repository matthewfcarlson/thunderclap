// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// FUN_00202560 @ 0x00202560
struct Vec3 {
    float x, y, z;
};

struct Quad;

struct Hit {
    float dist;
    Quad *quad;
    int tri;
};

struct Quad {
    char pad0[0x18];
    int material;
};

struct Probe {
    int f0;
    int f4;
    Hit *hit;
};

struct Trace {
    char pad0[8];
    Probe probe;
    char FUN_00201f20(Vec3 *from, int a, Vec3 *out, Vec3 *normal, int *c, int zero);
};

struct Collider {
    char FUN_002ee140(Probe *probe, Vec3 *from, Vec3 *to, int zero);
};

struct Bridge {
    char pad0[8];
    Collider *collider;
};

struct Hud {
    void FUN_00025370(int a);
    void FUN_00025260(int a, int b, int c);
};

struct Globals {
    char pad0[0x10];
    Bridge *bridge;
    char pad14[0xc];
    Hud *hud;
    Trace *trace;
};

extern Globals *DAT_004dd700;
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern float DAT_00554c18;

char FUN_002020a0(int material);
void FUN_002f1ce0(Vec3 *from, int tri, Vec3 *normal, float *out);

char FUN_00202560(Vec3 *start, float depth, int a3, Vec3 *result, Vec3 *normalOut,
                  Vec3 *fallback, int *materialOut, int *c)
{
    Globals *g = DAT_004dd700;
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
    Vec3 to;
    to.y = -depth;
    to.z = zero;
    to.x = zero + start->x;
    to.y = to.y + start->y;
    to.z = to.z + start->z;

    if (g->bridge->collider->FUN_002ee140(&trace->probe, start, &to, 0)) {
        Hit *hit = trace->probe.hit;
        float dist = hit->dist;
        Quad *quad = hit->quad;
        int tri = hit->tri;
        if (dist > 0.0f && FUN_002020a0(quad->material)) {
            Vec3 n;
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
