// STATUS: equivalent (tools/equiv.py level 3: 6470 inputs, branch coverage 42/42)
// FUN_00080900 @ 0x00080900
#include "decls/data/game/global.h"

struct Vec3_80900 {
    float x, y, z;
};

union FloatBits_80900 {
    float f;
    unsigned int u;
};

struct Transform_80900 {
    void FUN_00059a50(Vec3_80900 *out);
};

struct Holder_80900 {
    char pad0[0x10];
    Transform_80900 *transform;
};

struct Table_80900 {
    char pad0[0xc];
    int count;
    char pad10[0x124 - 0x10];
    Holder_80900 *player;
};

struct World {
    char pad0[0x20];
    Table_80900 *table;
};

struct Emitter_80900 {
    char pad0[0x80];
    float scale;
};

struct Prop_80900 {
    char pad0[0x10];
    int state;
    char pad14[0x28 - 0x14];
    unsigned int flags;
    char pad2c[0x64 - 0x2c];
    Vec3_80900 pos;
    char pad70[0xec - 0x70];
    Emitter_80900 *emitter;

    Vec3_80900 *FUN_00080c10(Vec3_80900 *out);
    void FUN_00080cd0(Vec3_80900 *dir, bool keep);
    void FUN_00081b20(int arg);
};


class PropList_80900 {
public:
    void FUN_00080900(int arg);

    char pad0[0x3548];
    int pending;
    Prop_80900 *props[20];
    int count;
    char pad_35a0[0x364c - 0x35a0];
    char frozen;
    char pad_364d[0x382c - 0x364d];
    World *world;

    void FUN_00080820();
    void FUN_0007b3e0(int index);
    void FUN_0007bf80(int index);
};

void PropList_80900::FUN_00080900(int arg)
{
    int limit = DAT_004dd040;
    Table_80900 *table = world->table;
    int n = table->count;
    if (n >= 3)
        limit = limit - (int)((double)n / DAT_0049b894 * DAT_004dd040);
    if (count < limit && pending > 0)
        FUN_00080820();

    float best;
    int bestIdx;
    Vec3_80900 player;
    Vec3_80900 dir;
    Vec3_80900 axis;
    float dy;

    best = 0.0f;
    bestIdx = -1;
    table->player->transform->FUN_00059a50(&player);
    for (int i = 0; i < count; i++) {
        Prop_80900 *p = props[i];
        float dz = player.z - p->pos.z;
        dy = player.y - p->pos.y;
        dir.y = 0.0f;
        dir.x = player.x - p->pos.x;
        dir.z = dz;
        unsigned int flags = p->flags;
        float d2 = dir.x * dir.x + dz * dz;

        if (!((flags >> 8) & 1) && (d2 > DAT_0049b8e8 || p->pos.y < -100.0f)) {
            FUN_0007b3e0(i);
            i--;
            continue;
        }
        if (!frozen && (p->state == 1 || p->state == 0)) {
            FloatBits_80900 b;
            b.f = dy;
            b.u &= 0x7fffffff;
            if (b.f < 3.0f) {
                bool push = false;
                if (d2 < DAT_0049b8a4) {
                    push = true;
                } else if (d2 < DAT_0049b8a8) {
                    Vec3_80900 *r = p->FUN_00080c10(&axis);
                    if (dir.z * r->z + dir.y * r->y + dir.x * r->x > 0.0f)
                        push = true;
                }
                if (push)
                    p->FUN_00080cd0(&dir, true);
            }
        }
        p->FUN_00081b20(arg);
        FUN_0007bf80(i);
        flags = p->flags;
        if (((flags >> 7) & 1) && p->emitter->scale == 1.0f) {
            FUN_0007b3e0(i);
            i--;
            continue;
        }
        if (d2 > best && !((flags >> 8) & 1)) {
            best = d2;
            bestIdx = i;
        }
    }
    if (count > limit && bestIdx > 0)
        FUN_0007b3e0(bestIdx);
}
