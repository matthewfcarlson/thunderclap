// STATUS: equivalent (tools/equiv.py level 3: 12028 inputs, branch coverage 34/34; run with --inputs 12000)
// hulkfight::ai::AcquireTargetCondition::vfunc_6 @ 0x001245b0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3 {
    float x, y, z;
};

struct Unit {
    char pad0[0x1b0];
    int id;                  // 0x1b0
};

struct Weapon {
    char pad0[0x1b0c];
    float charge;            // 0x1b0c
};

struct Target {
    char pad0[8];
    Weapon *weapon;          // 0x08
    int kind;                // 0x0c
};

struct Actor;

struct Player {
    char pad0[0x11c];
    Unit *unit;              // 0x11c
    char pad120[0x12c - 0x120];
    Actor *other;            // 0x12c
};

struct Actor {
    char pad0[0x11c];
    Unit *unit;              // 0x11c
    char pad120[0x328 - 0x120];
    Target *target;          // 0x328
    char pad32c[0x1b48 - 0x32c];
    char active;             // 0x1b48
    char pad1b49[0x20a8 - 0x1b49];
    int state;               // 0x20a8
    void FUN_0003ffa0(void *a, void *b);
    void FUN_00035dc0(Vec3 *out);
    char FUN_000350c0(Vec3 *out);
    void FUN_000400e0(Vec3 *a, Vec3 *b, int c, int d, unsigned int flags);
    void FUN_0003a520(Vec3 *a, Vec3 *b, int c, int d);
};

struct Chain {
    Actor *FUN_00059a30();
};

struct Owner {
    Chain *FUN_000592a0();
};

struct Globals {
    char pad0[0x20];
    Actor *player;           // 0x20 (struct with +0x124 pointer actually)
};

struct Holder {
    char pad0[0x124];
    Actor *actor;            // 0x124
};

struct Root {
    char pad0[0x20];
    Holder *holder;          // 0x20
};
extern Root *DAT_004dd700;

class AcquireTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner *owner, int unused3);
    char pad4[8];
    int argA;                // 0x0c
    int argB;                // 0x10
    char flag;               // 0x14
};

char AcquireTargetCondition::vfunc_6(int unused1, Owner *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor *self = owner->FUN_000592a0()->FUN_00059a30();
    Target *target = self->target;
    Actor *other = DAT_004dd700->holder->actor;

    if (!target && self->state < 0 && self->unit && other) {
        Actor *otherTarget = *(Actor **)((char *)other + 0x12c);
        Unit *otherUnit = other->unit;
        if (otherTarget && otherUnit && self->unit->id != otherUnit->id) {
            self->FUN_0003ffa0(otherTarget, 0);
            return 1;
        }
    }

    Vec3 v1;
    v1.x = 0; v1.y = 0; v1.z = 0;
    self->FUN_00035dc0(&v1);
    Vec3 v2;
    v2.x = 0; v2.y = 0; v2.z = 0;
    if (!self->FUN_000350c0(&v2))
        return 0;

    if (!target) {
        self->FUN_000400e0(&v2, &v1, argA, argB, 0x80000000);
    } else {
        if (self->active && self != other && target->weapon && target->kind == 1
            && target->weapon->charge <= 0.0f) {
            self->active = 0;
            self->FUN_0003ffa0(0, 0);
            return 0;
        }
        if (flag)
            self->FUN_0003a520(&v2, &v1, argA, argB);
    }
    return self->target != 0;
}
