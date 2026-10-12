// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 12/12)
// CJumpAttackAction::vfunc_6 @ 0x00017050
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField {
    void FUN_0027b040(const char *s);
};

struct TrackerSub;

struct Sub18 {
    void FUN_00221be0(TrackerSub *sub);
    void FUN_00221d20(float a);
};

class Obj70 {
public:
    virtual void v0();
    char pad4[4];
    NameField name;
    char pad1[0x18 - 0x9];
    Sub18 s18;
    char pad2[0x70 - 0x19];
    Obj70 *FUN_002248f0(int a);
};

struct Aimed {
    void FUN_0022c3b0(V3 *from, V3 *to);
};

struct TrackerSub {
    Aimed *FUN_00221c40();
};

struct Tracker {
    char pad0[0x10];
    TrackerSub sub;
    void FUN_00222890(Obj70 *o, float a, float b, float c, float d, float e, float f);
};

struct Target {
};

struct Player {
    char pad0[0x328];
    Target *target;
    void FUN_000350c0(V3 *out);
    void FUN_0003a520(V3 *out, V3 *dir, int a, int b);
    void FUN_000400e0(V3 *out, V3 *dir, int a, int b, unsigned flags);
};

struct Mgr {
    Player *FUN_00059a30();
    Tracker *FUN_00059a40();
};

struct Holder {
    Mgr *FUN_000592a0();
};

struct Cfg {
    char pad0[0x14];
    V3 f14;
    int f20;
    int f24;
    char pad28[4];
    float f2c;
    float f30;
    float f34;
};

void *FUN_00263ea0(unsigned int);

void __cdecl FUN_00096a90(Target *t, V3 *v);
float __cdecl FUN_00224ea0(float a, float b);

class CJumpAttackAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    char pad[0x1c - 4];
    Holder *f1c;
    Cfg *f20;
    Obj70 *f24;
    V3 dir;
};

bool CJumpAttackAction::vfunc_6(int arg)
{
    struct Frame {
        float c[3];
        V3 w;
        V3 l;
    } fr;
    Mgr *mgr = f1c->FUN_000592a0();
    Player *pl = mgr->FUN_00059a30();
    Tracker *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg *c0 = f20;
    fr.c[2] = c0->f2c;
    fr.c[1] = c0->f30;
    fr.c[0] = c0->f34;
    void *mem = FUN_00263ea0(0x70);
    Obj70 *o = 0;
    if (mem)
        o = ((Obj70 *)mem)->FUN_002248f0(0);
    f24 = o;
    o->name.FUN_0027b040("jumpAttack");
    f24->v0();
    TrackerSub *sub = &tr->sub;
    f24->s18.FUN_00221be0(sub);
    tr->FUN_00222890(f24, -1.0f, fr.c[2], 1.0f, fr.c[1], fr.c[0], -1.0f);

    fr.l = f20->f14;
    sub->FUN_00221c40()->FUN_0022c3b0(&fr.l, &dir);
    dir.FUN_0022d110();

    fr.w.x = 0.0f;
    fr.w.y = 0.0f;
    fr.w.z = 0.0f;
    pl->FUN_000350c0(&fr.w);
    if (pl->target != 0)
        pl->FUN_0003a520(&fr.w, &dir, f20->f20, f20->f24);
    else
        pl->FUN_000400e0(&fr.w, &dir, f20->f20, f20->f24, 0x80000000);

    Target *t = pl->target;
    if (t != 0) {
        FUN_00096a90(t, &dir);
        dir.x = dir.x - fr.w.x;
        dir.y = dir.y - fr.w.y;
        dir.z = dir.z - fr.w.z;
        dir.FUN_0022d110();
    }

    if (dir.y >= -0.1f) {
        fr.l = f20->f14;
        sub->FUN_00221c40()->FUN_0022c3b0(&fr.l, &dir);
        dir.FUN_0022d110();
        if (dir.y >= -0.1f) {
            dir.y = -0.1f;
            dir.FUN_0022d110();
        }
    }

    float ang = FUN_00224ea0(dir.x, dir.z);
    f24->s18.FUN_00221d20(ang);
    return true;
}
