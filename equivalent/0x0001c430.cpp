// STATUS: equivalent (tools/equiv.py level 3: 2769 inputs, branch coverage 32/32)
// FUN_0001c430 @ 0x0001c430
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Sensor {
    char pad[4];
};

struct Entity {
    char pad0[0x11c];
    int f11c;
    char pad120[0xc];
    int f12c;
    char pad130[0x3a4 - 0x130];
    Sensor* sensor;
    char pad3a8[0x20b0 - 0x3a8];
    int blocked;
    char FUN_000360f0();
    int FUN_000390e0(Vec3* c, Vec3* aux, float radius, Vec3* hit);
};

struct EntityList {
    char pad0[0xc];
    int count;
    Entity* FUN_00024190(int index);
};

struct Globals {
    char pad0[0x20];
    EntityList* entities;
};

struct Config {
    char pad0[0x18];
    float scale;
};

struct Xform {
    void FUN_0022c2b0(Vec3* in, Vec3* out);
};

struct Source {
    char pad0[0x30];
    Vec3 pos;
    void FUN_0022c3b0(Vec3* in, Vec3* out);
    void FUN_0022c2b0(Vec3* in, Vec3* out);
};

extern Globals* DAT_004dd700;

struct Anchor { char pad[4]; };
Anchor* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(Anchor* a);
char __cdecl FUN_00096ce0(Sensor* s, Vec3* hit, float* out);

union SelfOrDist {
    Entity* self;
    float dist;
};

class Tracker {
public:
    char pad0[0x1c];
    void* owner;
    Config* cfg;
    char pad24[0x34 - 0x24];
    Xform xf;
    void FUN_0001b510(int a, Vec3* pos, Vec3* dir, int kind);
    void FUN_0001c430(Source* src);
};

void Tracker::FUN_0001c430(Source* src)
{
    SelfOrDist slot;
    slot.self = FUN_00059a30(FUN_000592a0(owner));
    Vec3 c = src->pos;
    Vec3 t;
    Vec3 aux;
    Vec3 p;
    Vec3 q;
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    src->FUN_0022c3b0(&t, &aux);
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    src->FUN_0022c2b0(&t, &p);
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    xf.FUN_0022c2b0(&t, &q);
    Vec3 d;
    d.x = p.x - q.x;
    d.y = p.y - q.y;
    d.z = p.z - q.z;
    d.FUN_0022d110();

    float radius = cfg->scale * 0.25f;
    EntityList* list = DAT_004dd700->entities;
    int count = list->count;
    Vec3 hit;
    for (int i = 0; i < count; i++) {
        Entity* e = list->FUN_00024190(i);
        if (e != slot.self && e != 0 && e->blocked == 0 && !e->FUN_000360f0() && e->f11c != 0) {
            int r = e->FUN_000390e0(&c, &aux, radius, &hit);
            if (r != 0)
                FUN_0001b510(e->f12c, &hit, &d, r);
        }
    }

    Sensor* sensor = slot.self->sensor;
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
    float dx = c.x - hit.x;
    float dy = c.y - hit.y;
    float dz = c.z - hit.z;
    float sum1 = dz * dz + dy * dy + dx * dx;
    bool nearC = sum1 <= s2;
    float ex = p.x - hit.x;
    float ey = p.y - hit.y;
    float ez = p.z - hit.z;
    float sum2 = ez * ez + ey * ey + ex * ex;
    bool nearP = sum2 <= s2;
    if (!nearC && !nearP)
        return;
    Vec3* other = nearP ? &p : &c;
    Vec3 mid;
    mid.x = (hit.x + other->x) * 0.5f;
    mid.y = (hit.y + other->y) * 0.5f;
    mid.z = (hit.z + other->z) * 0.5f;
    FUN_0001b510((int)sensor, &mid, &d, 2);
}
