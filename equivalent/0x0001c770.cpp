// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 24/24)
// FUN_0001c770 @ 0x0001c770
#include "compat/ptr.h"
#include "decls/address.h"
struct Vec3_1c770 {
    float x, y, z;
    float FUN_0022d110();
};

struct Sensor_1c770 {
    char pad[4];
};

struct Entity {
    char pad0[0x11c];
    int f11c;
    char pad120[0xc];
    int f12c;
    char pad130[0x3a4 - 0x130];
    Sensor_1c770* sensor;
    char pad3a8[0x20b0 - 0x3a8];
    int blocked;
    char FUN_000360f0();
    int FUN_00038f90(Vec3_1c770* origin, float radius, Vec3_1c770* out);
};

struct EntityList_1c770 {
    char pad0[0xc];
    int count;
    Entity* FUN_00024190(int index);
};

struct World {
    char pad0[0x20];
    EntityList_1c770* entities;
};

struct Config_1c770 {
    char pad0[0x18];
    float scale;
};

struct Source_1c770 {
    char pad0[0x30];
    Vec3_1c770 pos;
};


struct Anchor_1c770 { char pad[4]; };
Anchor_1c770* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(Anchor_1c770* a);
char __cdecl FUN_00096ce0(Sensor_1c770* s, Vec3_1c770* hit, float* out);

union CountOrDist {
    int count;
    float dist;
};

class Tracker_1c770 {
public:
    char pad0[0x1c];
    void* owner;
    Config_1c770* cfg;
    char pad24[0x64 - 0x24];
    Vec3_1c770 target;
    void FUN_0001b510(hulk_intptr a, Vec3_1c770* pos, Vec3_1c770* dir, int kind);
    void FUN_0001c770(Source_1c770* src, float radius);
};

void Tracker_1c770::FUN_0001c770(Source_1c770* src, float radius)
{
    Entity* self = FUN_00059a30(FUN_000592a0(owner));

    radius = radius * cfg->scale;
    Vec3_1c770 c = src->pos;
    Vec3_1c770 d;
    d.x = c.x - target.x;
    d.y = c.y - target.y;
    d.z = c.z - target.z;
    d.FUN_0022d110();

    Vec3_1c770 hit;
    EntityList_1c770* list = DAT_004dd700->entities;
    // the original reuses the (dead) first argument slot for the count and the float out value
    CountOrDist* slot = (CountOrDist*)&src;
    slot->count = list->count;
    for (int i = 0; i < slot->count; i++) {
        Entity* e = list->FUN_00024190(i);
        if (e != self && e != 0 && e->blocked == 0 && !e->FUN_000360f0() && e->f11c != 0) {
            int r = e->FUN_00038f90(&c, radius, &hit);
            if (r != 0)
                FUN_0001b510(e->f12c, &hit, &d, r);
        }
    }

    Sensor_1c770* sensor = self->sensor;
    if (sensor == 0)
        return;
    if (!FUN_00096ce0(sensor, &hit, &slot->dist))
        return;
    slot->dist = slot->dist * 0.75f;
    if (!(slot->dist < 1.5f))
        slot->dist = 1.5f;
    float s = slot->dist + radius;
    float dx = c.x - hit.x;
    float dy = c.y - hit.y;
    float dz = c.z - hit.z;
    float sum = dz * dz + dy * dy + dx * dx;
    if (!(sum <= s * s))
        return;
    Vec3_1c770 mid;
    mid.x = (hit.x + c.x) * 0.5f;
    mid.y = (hit.y + c.y) * 0.5f;
    mid.z = (hit.z + c.z) * 0.5f;
    FUN_0001b510((hulk_intptr)sensor, &mid, &d, 2);
}
