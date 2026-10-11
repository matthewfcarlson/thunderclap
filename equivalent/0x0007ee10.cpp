// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 26/26)
// FUN_0007ee10 @ 0x0007ee10
extern "C" double floor(double);
extern int DAT_004dd044;
extern float DAT_0049b8ec;
extern float DAT_0049b8b8;

struct Vec3 {
    float x, y, z;
};

union FloatBits {
    float f;
    int i;
};

struct Pos {
    float x, y, z;
};

struct Locator {
    char FUN_00059a50(Vec3 *out);
};

struct Link124 {
    char pad00[0x10];
    Locator *loc;
};

struct Scene {
    char pad00[0xc];
    int count;
    char pad10[0x124 - 0x10];
    Link124 *f124;
};

struct Objs {
    char pad00[0x59c];
    int index;
};

struct Slots {
    Objs *FUN_000862a0();
};

struct Mgr {
    void FUN_001e5bc0(int id);
};

struct Ctx {
    char pad00[0xc];
    Mgr *mgr;
    char pad10[0x20 - 0x10];
    Scene *scene;
    char pad24[0x54 - 0x24];
    Slots *slots;
};

class Item {
public:
    char pad00[0x10];
    int id;
    int f14;
    Pos *FUN_00082cf0();
    void FUN_00082cd0(Vec3 *v);
    void FUN_000835a0(int arg);
};

struct Flag8 {
    char pad[3];
    char on;
    char pad4[4];
};

class World {
public:
    char pad00[8];
    Flag8 flags[(0x3800 - 8) / 8];
    Item *items[10];
    int count;
    Ctx *ctx;
    void FUN_0007e740();
    void FUN_0007ccf0(int index);
    void FUN_0007ee10(int arg);
};

void World::FUN_0007ee10(int arg)
{
    Ctx *c = ctx;
    Scene *scene = c->scene;
    int idx = c->slots->FUN_000862a0()->index;
    if (flags[idx].on) {
        int n = scene->count;
        int limit = DAT_004dd044;
        if ((float)n >= 3.0f)
            limit = limit - (int)floor((float)(DAT_004dd044 * n) * 0.125f);
        if (count < limit)
            FUN_0007e740();
    }
    Vec3 pos;
    scene->f124->loc->FUN_00059a50(&pos);
    int i = 0;
    Item **p = &items[0];
    while (i < count) {
        Item *item = *p;
        Pos *q = item->FUN_00082cf0();
        float dz = pos.z - q->z;
        FloatBits dy;
        dy.f = pos.y - q->y;
        Vec3 d;
        d.x = pos.x - q->x;
        d.y = 0.0f;
        d.z = dz;
        float dist2 = d.x * d.x + dz * dz;
        if (dist2 > DAT_0049b8ec || q->y < -100.0f) {
            item = *p;
            ctx->mgr->FUN_001e5bc0(item->id);
            if (*p && *p == item)
                FUN_0007ccf0(i);
            i--;
            p--;
        } else {
            if (dist2 < DAT_0049b8b8) {
                dy.i &= 0x7fffffff;
                if (dy.f < 3.0f) {
                    if (item->f14 == 0 || item->f14 == 2)
                        item->FUN_00082cd0(&d);
                }
            }
            item->FUN_000835a0(arg);
        }
        i++;
        p++;
    }
}
