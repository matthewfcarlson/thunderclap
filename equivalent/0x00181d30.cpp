// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 34/34)
// FUN_00181d30 @ 0x00181d30
struct Vec3_181d30 {
    float x, y, z;
};

struct Entity;
struct Actor_181d30;

struct Obj70_181d30 {
    void FUN_002f5a20(Vec3_181d30 *v);
};

struct Node70 {
    char pad00[0x70];
    Obj70_181d30 *f70;
};

struct Holder_181d30 {
    char pad00[8];
    Entity *target;
    int kind;
};

struct Obj284 {
    void FUN_002845a0();
};

struct Obj5e80 {
    int FUN_001d5e80(int v);
};

struct Ptr11c {
    char pad00[0x18];
    Obj284 *f18;
};

struct Entity {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0x40 - 4];
    int f40;
    char pad44[0xec - 0x44];
    Obj5e80 *fec;
    char padf0[0x11c - 0xf0];
    Ptr11c *f11c;
    char pad120[0x148 - 0x120];
    Actor_181d30 *f148;
    int FUN_001d6c70();
    void FUN_001d6cc0(float v);
    Node70 *FUN_001d72e0();
    void FUN_001d7510();
    void FUN_001d7e70();
};

struct Actor_181d30 {
    char pad00[0x128];
    Entity *f128;
    void *f12c;
    char pad130[0x3a4 - 0x130];
    Holder_181d30 *f3a4;
    char pad3a8[0x22e8 - 0x3a8];
    char b22e8;
    void FUN_0003a570();
    char FUN_00035660(Vec3_181d30 *out);
    Entity *FUN_00035ef0(int idx);
    void FUN_00037420(int v);
    void FUN_000385a0(void *a, int v);
};

struct Param1c {
    char pad00[0x10];
    int idx;
    char b14;
};

struct Res_181d30 {
    char pad00[0x10];
    Actor_181d30 *actor;
    Actor_181d30 *FUN_00059a30();
};

struct T20 {
    Res_181d30 *FUN_000592a0();
};

struct Target_181d30 {
    char pad00[0x328];
    void *f328;
    void FUN_0003ffa0(Node70 *n, int v);
};

struct Mgr0c {
    void FUN_001dcd30(int v);
    void FUN_001dc170(Entity *e, int v);
};

struct Ctx20_181d30 {
    char pad00[0x124];
    Target_181d30 *f124;
};

struct Game_181d30 {
    char pad00[0xc];
    Mgr0c *f0c;
    char pad10[0x20 - 0x10];
    Ctx20_181d30 *f20;
};

extern Game_181d30 *DAT_004dd700;

class Thing_181d30 {
public:
    char pad00[0x1c];
    Param1c *f1c;
    T20 *f20;
    char FUN_00181d30();
};

char Thing_181d30::FUN_00181d30()
{
    Actor_181d30 *ebp = f20->FUN_000592a0()->FUN_00059a30();
    int idx = f1c->idx;
    Entity *e = 0;

    if (ebp) {
        if (idx < 0)
            e = ebp->f128;
        else if (idx < 8)
            e = ebp->FUN_00035ef0(idx);
    }
    if (!e) {
        Holder_181d30 *h = ebp->f3a4;
        if (!h || h->kind != 5)
            return 0;
        e = h->target;
        if (!e)
            return 0;
    }
    if (!e->f148)
        return 0;

    e->vfunc_0();
    Actor_181d30 *a = e->f148;
    a->FUN_0003a570();
    int f40 = e->f40;
    e->f148 = 0;
    if (e->fec->FUN_001d5e80(f40) == 4 && a)
        a->b22e8 = 1;
    e->f11c->f18->FUN_002845a0();
    if (f1c->b14) {
        Vec3_181d30 v;
        e->FUN_001d7e70();
        e->FUN_001d7510();
        a->FUN_00035660(&v);
        e->FUN_001d72e0()->f70->FUN_002f5a20(&v);
        e->FUN_001d6cc0(3.0f);
    }
    Mgr0c *m = DAT_004dd700->f0c;
    m->FUN_001dcd30(e->FUN_001d6c70());
    DAT_004dd700->f0c->FUN_001dc170(e, 0);
    Target_181d30 *t = DAT_004dd700->f20->f124;
    if (t && t->f328 && t->f328 == a->f12c)
        t->FUN_0003ffa0(e->FUN_001d72e0(), 0);
    if (a) {
        if (a != ebp && ebp->f12c)
            a->FUN_000385a0(ebp->f12c, 0);
        a->FUN_00037420(1);
    }
    e->vfunc_1();
    return 1;
}
