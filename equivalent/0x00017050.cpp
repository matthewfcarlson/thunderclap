// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// CJumpAttackAction::vfunc_6 @ 0x00017050
struct V3_17050 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField_17050 {
    void FUN_0027b040(const char *s);
};

struct TrackerSub_17050;

struct Sub18_17050 {
    void FUN_00221be0(TrackerSub_17050 *sub);
    void FUN_00221d20(float a);
};

class JointDriver_17050 {
public:
    virtual void v0();
    char pad4[4];
    NameField_17050 name;
    char pad1[0x18 - 0x9];
    Sub18_17050 s18;
    char pad2[0x70 - 0x19];
    JointDriver_17050 *FUN_002248f0(int a);
};

struct Aimed_17050 {
    void FUN_0022c3b0(V3_17050 *from, V3_17050 *to);
};

struct TrackerSub_17050 {
    Aimed_17050 *FUN_00221c40();
};

struct Tracker_17050 {
    char pad0[0x10];
    TrackerSub_17050 sub;
    void FUN_00222890(JointDriver_17050 *o, float a, float b, float c, float d, float e, float f);
};

struct Target_17050 {
};

struct Player_17050 {
    char pad0[0x328];
    Target_17050 *target;
    void FUN_000350c0(V3_17050 *out);
    void FUN_0003a520(V3_17050 *out, V3_17050 *dir, int a, int b);
    void FUN_000400e0(V3_17050 *out, V3_17050 *dir, int a, int b, unsigned flags);
};

struct Mgr_17050 {
    Player_17050 *FUN_00059a30();
    Tracker_17050 *FUN_00059a40();
};

struct Holder_17050 {
    Mgr_17050 *FUN_000592a0();
};

struct Cfg_17050 {
    char pad0[0x14];
    V3_17050 f14;
    int f20;
    int f24;
    char pad28[4];
    float f2c;
    float f30;
    float f34;
};

void *FUN_00263ea0(unsigned int);

void __cdecl FUN_00096a90(Target_17050 *t, V3_17050 *v);
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
    Holder_17050 *f1c;
    Cfg_17050 *f20;
    JointDriver_17050 *f24;
    V3_17050 dir;
};

bool CJumpAttackAction::vfunc_6(int arg)
{
    struct Frame {
        float c[3];
        V3_17050 w;
        V3_17050 l;
    } fr;
    Mgr_17050 *mgr = f1c->FUN_000592a0();
    Player_17050 *pl = mgr->FUN_00059a30();
    Tracker_17050 *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg_17050 *c0 = f20;
    fr.c[2] = c0->f2c;
    fr.c[1] = c0->f30;
    fr.c[0] = c0->f34;
    void *mem = FUN_00263ea0(0x70);
    JointDriver_17050 *o = 0;
    if (mem)
        o = ((JointDriver_17050 *)mem)->FUN_002248f0(0);
    f24 = o;
    o->name.FUN_0027b040("jumpAttack");
    f24->v0();
    TrackerSub_17050 *sub = &tr->sub;
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

    Target_17050 *t = pl->target;
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
