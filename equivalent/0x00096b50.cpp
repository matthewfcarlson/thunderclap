// STATUS: equivalent (tools/equiv.py level 3: 189 inputs, branch coverage 48/48)
// FUN_00096b50 @ 0x00096b50
struct Vec3 { float x, y, z; };
struct Part { char pad[0x1b0]; int f1b0; };
struct Prop {
    char pad0[0x10];
    int kind;
    char pad1[0x28 - 0x14];
    unsigned int flags;
    char pad2[0x64 - 0x2c];
    Vec3 pos;
};
struct Actor {
    char pad0[0xfc];
    int mode;
    char pad1[0x11c - 0x100];
    Part *part;
    char pad2[0x148 - 0x120];
    Actor *parent;
    char pad3[0x1b0c - 0x14c];
    float f1b0c;
    char pad4[0x20b0 - 0x1b10];
    int busy;
    bool FUN_001d7450();
    bool FUN_001d6980();
    int FUN_001d73f0();
    void FUN_001d69f0(Vec3 *out);
    int FUN_00035cf0();
    void FUN_000350c0(Vec3 *out);
};
struct Checker {
    char pad[0x20];
    bool FUN_00024540(Actor *a);
};
struct Globals {
    char pad[0x20];
    Checker *checker;
};
struct Event {
    char pad0[8];
    union {
        Prop *prop;
        Actor *actor;
    } target;
    int type;
};
extern Globals *DAT_004dd700;

bool FUN_00096b50(Event *ev, Vec3 *out, int *result)
{
    *result = -10;
    if (ev == 0) return false;
    if (ev->type == 1) {
        Actor *a = ev->target.actor;
        if (a == 0) return false;
        if (a->busy != 0) return false;
        if (a->part == 0) return false;
        if (a->part->f1b0 == 0) return false;
        Checker *c = DAT_004dd700->checker;
        if (c->FUN_00024540(a)) return false;
        a->FUN_000350c0(out);
        *result = a->FUN_00035cf0();
        return true;
    }
    if (ev->type == 5) {
        Actor *a = ev->target.actor;
        if (a == 0) return false;
        if (a->mode == 2 || a->mode == 3 || a->mode == 1) return false;
        if (!a->FUN_001d7450()) return false;
        if (a->FUN_001d6980()) return false;
        Actor *p = a->parent;
        if (p != 0) {
            if (p->busy != 0) return false;
            if (p->f1b0c <= 0.0f) return false;
            if (p->part == 0) return false;
            if (p->part->f1b0 == 0) return false;
            *result = p->FUN_00035cf0();
            a->FUN_001d69f0(out);
            return true;
        }
        *result = a->FUN_001d73f0();
        a->FUN_001d69f0(out);
        return true;
    }
    if (ev->type == 7) {
        Prop *p = ev->target.prop;
        if (p == 0) return false;
        if ((p->flags >> 7) & 1) return false;
        if (p->kind == 5 || p->kind == 6) return false;
        *out = p->pos;
        *result = -9;
        return true;
    }
    return false;
}
