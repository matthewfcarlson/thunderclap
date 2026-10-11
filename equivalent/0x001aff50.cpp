// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 24/24)
// FUN_001aff50 @ 0x001aff50
struct V3 { float x, y, z; };

struct Actor;

struct Holder {
    char pad[8];
    Actor* actor;
};

struct Actor {
    char FUN_000373d0();
    void FUN_00038e80(int id, Holder* other, int mode, int arg, V3* dir, int flags);
    char pad0[0x128];
    int f128;
    char pad1[0x334 - 0x12c];
    Actor* a334;
    Actor* a338;
    char pad2[0x1b88 - 0x33c];
    float f1b88;
    char pad3[0x20b0 - 0x1b8c];
    int f20b0;
};

struct Clock {
    float FUN_00086080();
};

struct World {
    char pad[0x58];
    Clock* clock;
};

extern World* DAT_004dd700;

int __stdcall FUN_001aff50(int a1, Holder* h2, int a3, Holder* h4, int a5, int a6, V3* dir, int a8)
{
    Actor* a = h2->actor;
    Actor* b = h4->actor;

    if (DAT_004dd700 != 0)
        a->f1b88 = DAT_004dd700->clock->FUN_00086080();

    if (!a->FUN_000373d0())
        return 1;
    if (!b->FUN_000373d0())
        return 1;
    if (a == b)
        return 1;
    if (a->f20b0 != 0)
        return 1;
    if (b->f20b0 != 0)
        return 1;
    if (a->a338 == b)
        return 1;
    if (a->a334 == b)
        return 1;

    if (a->f128 != 0 || b->f128 == 0) {
        a->FUN_00038e80(a1, h4, -1, a6, dir, a8);
        if (b->f128 == 0 && a->f128 != 0)
            return 1;
    }
    V3 neg;
    neg.x = dir->x * -1.0f;
    neg.y = dir->y * -1.0f;
    neg.z = dir->z * -1.0f;
    b->FUN_00038e80(a3, h2, -1, a5, &neg, a8);
    return 1;
}
