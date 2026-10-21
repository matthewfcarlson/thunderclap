// STATUS: equivalent (tools/equiv.py level 3: 18597 inputs, branch coverage 32/32)
// FUN_0001c430 @ 0x0001c430
#include "compat/ptr.h"
#include "decls/address.h"
struct Vec3_1c430 {
    float x, y, z;
    float FUN_0022d110();
};

struct Sensor_1c430 {
    char pad[4];
};

struct Entity {
    char pad0[0x11c];
    int f11c;
    char pad120[0xc];
    int f12c;
    char pad130[0x3a4 - 0x130];
    Sensor_1c430* sensor;
    char pad3a8[0x20b0 - 0x3a8];
    int blocked;
    char FUN_000360f0();
    int FUN_000390e0(Vec3_1c430* c, Vec3_1c430* aux, float radius, Vec3_1c430* hit);
};

struct EntityList_1c430 {
    char pad0[0xc];
    int count;
    Entity* FUN_00024190(int index);
};

struct World {
    char pad0[0x20];
    EntityList_1c430* entities;
};

struct Config_1c430 {
    char pad0[0x18];
    float scale;
};

struct Xform_1c430 {
    void FUN_0022c2b0(Vec3_1c430* in, Vec3_1c430* out);
};

struct Source_1c430 {
    char pad0[0x30];
    Vec3_1c430 pos;
    void FUN_0022c3b0(Vec3_1c430* in, Vec3_1c430* out);
    void FUN_0022c2b0(Vec3_1c430* in, Vec3_1c430* out);
};


struct Anchor_1c430 { char pad[4]; };
Anchor_1c430* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(Anchor_1c430* a);
char __cdecl FUN_00096ce0(Sensor_1c430* s, Vec3_1c430* hit, float* out);

union SelfOrDist {
    Entity* self;
    float dist;
};

class Tracker_1c430 {
public:
    char pad0[0x1c];
    void* owner;
    Config_1c430* cfg;
    char pad24[0x34 - 0x24];
    Xform_1c430 xf;
    void FUN_0001b510(hulk_intptr a, Vec3_1c430* pos, Vec3_1c430* dir, int kind);
    void FUN_0001c430(Source_1c430* src);
};

void Tracker_1c430::FUN_0001c430(Source_1c430* src)
{
    SelfOrDist slot;
    slot.self = FUN_00059a30(FUN_000592a0(owner));
    Vec3_1c430 c = src->pos;
    Vec3_1c430 t;
    Vec3_1c430 aux;
    Vec3_1c430 p;
    Vec3_1c430 q;
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    src->FUN_0022c3b0(&t, &aux);
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    src->FUN_0022c2b0(&t, &p);
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    xf.FUN_0022c2b0(&t, &q);
    Vec3_1c430 d;
    d.x = p.x - q.x;
    d.y = p.y - q.y;
    d.z = p.z - q.z;
    d.FUN_0022d110();

    hulk_freg radius = cfg->scale * 0.25f;
    EntityList_1c430* list = DAT_004dd700->entities;
    int count = list->count;
    Vec3_1c430 hit;
    for (int i = 0; i < count; i++) {
        Entity* e = list->FUN_00024190(i);
        if (e != slot.self && e != 0 && e->blocked == 0 && !e->FUN_000360f0() && e->f11c != 0) {
            int r = e->FUN_000390e0(&c, &aux, radius, &hit);
            if (r != 0)
                FUN_0001b510(e->f12c, &hit, &d, r);
        }
    }

    Sensor_1c430* sensor = slot.self->sensor;
    if (sensor == 0)
        return;
    if (!FUN_00096ce0(sensor, &hit, &slot.dist))
        return;
    slot.dist = slot.dist * 0.75f;
    if (!(slot.dist < 1.5f))
        slot.dist = 1.5f;
    // The original keeps s and s*s on the x87 stack unrounded (floats near FLT_MAX overflow if s*s is stored as float).
    double s = slot.dist + radius;
    double s2 = s * s;
    hulk_freg dx = c.x - hit.x;
    hulk_freg dy = c.y - hit.y;
    hulk_freg dz = c.z - hit.z;
    hulk_freg sum1 = dz * dz + dy * dy + dx * dx;
    bool nearC = sum1 <= s2;
    hulk_freg ex = p.x - hit.x;
    hulk_freg ey = p.y - hit.y;
    hulk_freg ez = p.z - hit.z;
    hulk_freg sum2 = ez * ez + ey * ey + ex * ex;
    bool nearP = sum2 <= s2;
    if (!nearC && !nearP)
        return;
    Vec3_1c430* other = nearP ? &p : &c;
    Vec3_1c430 mid;
    mid.x = (hit.x + other->x) * 0.5f;
    mid.y = (hit.y + other->y) * 0.5f;
    mid.z = (hit.z + other->z) * 0.5f;
    FUN_0001b510((hulk_intptr)sensor, &mid, &d, 2);
}
