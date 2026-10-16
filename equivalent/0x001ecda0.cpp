// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 45/46, incomplete)
// FUN_001ecda0 @ 0x001ecda0
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" int strcmp(const char *a, const char *b);
extern "C" double sqrt(double);

struct Vec3_1ecda0 {
    float x, y, z;
};

struct Id_1ecda0 {
    unsigned __int64 key;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af60(unsigned __int64 value);
    void FUN_0027af70(const Id_1ecda0 *src);
    void FUN_0027b040(const char *name);
    Id_1ecda0 *FUN_0027b0e0(const char *name);
};

struct IdCopy_1ecda0 {
    unsigned __int64 key;
    void FUN_0027af30(const Id_1ecda0 *src);
    IdCopy_1ecda0(const Id_1ecda0 &o) { FUN_0027af30(&o); }
};

struct Node {
    char FUN_00059a50(Vec3_1ecda0 *out);
};

struct Info_1ecda0 {
    const char *FUN_000443b0();
    unsigned __int64 FUN_000443c0();
};

struct Actor_1ecda0 {
    char pad0[8];
    Id_1ecda0 id;                  // 0x08
    Node *node;             // 0x10
    char pad14[0x11c - 0x14];
    Info_1ecda0 *info;             // 0x11c
    char pad120[0x1b0c - 0x120];
    float weight;           // 0x1b0c
};

struct Query_1ecda0 {
    char data[0x44];
    Query_1ecda0 *FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *name);
    void FUN_001ef3c0(IdCopy_1ecda0 id);
};

struct Logic_1ecda0 {
    char pad0[0xc];
    int count;              // 0xc
    char pad10[0x124 - 0x10];
    Actor_1ecda0 *self;            // 0x124
    bool FUN_00027fc0(const char *a, const char *b);
    Actor_1ecda0 *FUN_00024190(int index);
};

struct Env_1ecda0 {
    char pad[0x20];
    Logic_1ecda0 *logic;           // 0x20
};

struct Flags_1ecda0 {
    bool FUN_00092de0(int v);
};

struct Singleton_4dd6ec {
    Flags_1ecda0 *FUN_00086340();
};

struct Lookup_1ecda0 {
    void *FUN_00086310();
};

struct Spawner_1ecda0 {
    void FUN_001efe20(Query_1ecda0 *q, Id_1ecda0 *id, const char *name, float radius);
};

struct SpawnGlobals_1ecda0 {
    Spawner_1ecda0 *spawner;       // 0x0
    char pad[4];
    char enabled;           // 0x8
};

void FUN_001eb440(void *target, Query_1ecda0 *q);


class Handler_1ecda0 {
public:
    Env_1ecda0 *env;               // 0x0
    Lookup_1ecda0 *lookup;         // 0x4
    void FUN_001ecda0(const char *a1, int a2, const char *a3, const char *a4);
};

void Handler_1ecda0::FUN_001ecda0(const char *a1, int a2, const char *a3, const char *a4)
{
    Query_1ecda0 q;
    Vec3_1ecda0 p0;
    float bestDist;
    Handler_1ecda0 *self;
    int i;
    Vec3_1ecda0 p1;
    Id_1ecda0 id2;
    union {
        Id_1ecda0 temp;
        Actor_1ecda0 *best;
    } tb;
    Id_1ecda0 id1;
    bool online;
    id1.FUN_0027af00();
    id1.FUN_0027af60(0);
    id2.FUN_0027af00();
    self = this;

    do {
        if (strcmp(a4, "spawn") == 0) {
            if (env->logic->FUN_00027fc0("hulk", "//hulk/opening/holding/stealth_truck"))
                break;
        }
        if (a1 != 0 && a1[0] != 0) {
            id1.FUN_0027af70(tb.temp.FUN_0027b0e0(a1));
            tb.temp.FUN_0027af50();
        }
        online = DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2);

        const char *name;
        if (a3 != 0 && a3[0] != 0) {
            id2.FUN_0027b040(a3);
            if (strcmp(a3, "hulk") != 0 && strcmp(a3, "joefixit") != 0)
                name = 0;
            else {
                if (!online)
                    break;
                name = "joefixit";
            }
        } else {
            env->logic->self->node->FUN_00059a50(&p0);
            tb.best = 0;
            bestDist = 9999.0f;
            i = 0;
            if (env->logic->count <= 0)
                break;
            do {
                Actor_1ecda0 *actor = env->logic->FUN_00024190(i);
                if (actor != self->env->logic->self && actor->weight > 0.0f) {
                    if (id1.key == 0 || id1.key == actor->info->FUN_000443c0()) {
                        actor->node->FUN_00059a50(&p1);
                        p1.x = p1.x - p0.x;
                        p1.y = p1.y - p0.y;
                        p1.z = p1.z - p0.z;
                        double dist = sqrt(p1.z * p1.z + p1.y * p1.y + p1.x * p1.x);
                        if (dist < bestDist) {
                            bestDist = (float)dist;
                            tb.best = actor;
                        }
                    }
                }
                i++;
            } while (i < self->env->logic->count);
            if (tb.best == 0)
                break;
            id2.FUN_0027af70(&tb.best->id);
            name = tb.best->info->FUN_000443b0();
        }
        if (name != 0) {
            id1.FUN_0027af70(tb.temp.FUN_0027b0e0(name));
            tb.temp.FUN_0027af50();
        }

        if (id1.key == 0)
            break;
        if (a4 == 0 || a4[0] == 0)
            break;
        q.FUN_001ef320();
        q.FUN_001ef370("Objects");
        q.FUN_001ef370("Dialogue");
        q.FUN_001ef3c0(id1);
        void *target = lookup->FUN_00086310();
        if (target != 0)
            FUN_001eb440(target, &q);
        if ((*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->enabled)
            (*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->spawner->FUN_001efe20(&q, &id2, a4, 100.0f);
        q.FUN_001ef350();
    } while (0);
    id2.FUN_0027af50();
    id1.FUN_0027af50();
}
