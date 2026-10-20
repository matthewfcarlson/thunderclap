// STATUS: equivalent (tools/equiv.py level 3: 3056 inputs, branch coverage 45/46, incomplete)
// FUN_001ecda0 @ 0x001ecda0
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" int strcmp(const char *a, const char *b);
extern "C" double sqrt(double);

struct Vec3_1ecda0 {
    float x, y, z;
};

struct Id_1ecda0 {
    unsigned lo, hi;               // a 64-bit key, kept as two words so it is only 4-aligned
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

// Compares a 64-bit key (edx:eax) word by word against a two-word Id.
static __forceinline bool SameKey_1ecda0(unsigned __int64 k, unsigned lo, unsigned hi)
{
    union { unsigned __int64 q; unsigned w[2]; } u;
    u.q = k;
    return u.w[0] == lo && u.w[1] == hi;
}

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

// The original's frame, in slot order from id1 (esp+0x10) up; 8-aligned like the original's.
// The query's tail word must stay: the real callees write past the declared objects.
struct __declspec(align(8)) Frame_1ecda0 {
    Id_1ecda0 id1;                 // 0x10
    union {
        Id_1ecda0 temp;
        Actor_1ecda0 *best;
    } tb;                          // 0x18
    Id_1ecda0 id2;                 // 0x20
    int pad28;
    Vec3_1ecda0 p1;                // 0x2c
    int i;                         // 0x38
    Handler_1ecda0 *self;          // 0x3c
    float bestDist;                // 0x40
    Vec3_1ecda0 p0;                // 0x44
    Query_1ecda0 q;                // 0x50
    int pad94;
};

void Handler_1ecda0::FUN_001ecda0(const char *a1, int a2, const char *a3, const char *a4)
{
    Frame_1ecda0 f;
    bool online;
    f.id1.FUN_0027af00();
    f.id1.FUN_0027af60(0);
    f.id2.FUN_0027af00();
    f.self = this;

    do {
        if (strcmp(a4, "spawn") == 0) {
            if (f.self->env->logic->FUN_00027fc0("hulk", "//hulk/opening/holding/stealth_truck"))
                break;
        }
        if (a1 != 0 && a1[0] != 0) {
            f.id1.FUN_0027af70(f.tb.temp.FUN_0027b0e0(a1));
            f.tb.temp.FUN_0027af50();
        }
        online = DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2);

        // A named target other than hulk/joefixit skips the lookup; the nearest actor's
        // name is looked up even when it is null.
        const char *name;
        bool lookup = true;
        if (a3 != 0 && a3[0] != 0) {
            f.id2.FUN_0027b040(a3);
            if (strcmp(a3, "hulk") != 0 && strcmp(a3, "joefixit") != 0)
                lookup = false;
            else {
                if (!online)
                    break;
                name = "joefixit";
            }
        } else {
            f.tb.best = 0;
            f.bestDist = 9999.0f;
            f.self->env->logic->self->node->FUN_00059a50(&f.p0);
            f.i = 0;
            if (f.self->env->logic->count <= 0)
                break;
            do {
                Actor_1ecda0 *actor = f.self->env->logic->FUN_00024190(f.i);
                if (actor != f.self->env->logic->self && actor->weight > 0.0f) {
                    unsigned lo = f.id1.lo, hi = f.id1.hi;
                    if ((lo | hi) == 0 || SameKey_1ecda0(actor->info->FUN_000443c0(), lo, hi)) {
                        actor->node->FUN_00059a50(&f.p1);
                        f.p1.x = f.p1.x - f.p0.x;
                        f.p1.y = f.p1.y - f.p0.y;
                        f.p1.z = f.p1.z - f.p0.z;
                        double dist = sqrt(f.p1.z * f.p1.z + f.p1.y * f.p1.y + f.p1.x * f.p1.x);
                        if (dist < f.bestDist) {
                            f.bestDist = (float)dist;
                            f.tb.best = actor;
                        }
                    }
                }
                f.i++;
            } while (f.i < f.self->env->logic->count);
            if (f.tb.best == 0)
                break;
            f.id2.FUN_0027af70(&f.tb.best->id);
            name = f.tb.best->info->FUN_000443b0();
        }
        if (lookup) {
            f.id1.FUN_0027af70(f.tb.temp.FUN_0027b0e0(name));
            f.tb.temp.FUN_0027af50();
        }

        if ((f.id1.lo | f.id1.hi) == 0)
            break;
        if (a4 == 0 || a4[0] == 0)
            break;
        f.q.FUN_001ef320();
        f.q.FUN_001ef370("Objects");
        f.q.FUN_001ef370("Dialogue");
        f.q.FUN_001ef3c0(f.id1);
        void *target = f.self->lookup->FUN_00086310();
        if (target != 0)
            FUN_001eb440(target, &f.q);
        if ((*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->enabled)
            (*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->spawner->FUN_001efe20(&f.q, &f.id2, a4, 100.0f);
        f.q.FUN_001ef350();
    } while (0);
    f.id2.FUN_0027af50();
    f.id1.FUN_0027af50();
}
