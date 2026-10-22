// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 24/24)
// CHeliDeathSpiralAction::vfunc_6 @ 0x00017e00
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct V3_17e00 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField_17e00 {
    void FUN_0027b040(const char *s);
};

struct Sub18_17e00 {
    void FUN_00221d20(float a);
    void FUN_0022be40(const V3_17e00 *v);
};

class JointDriver_17e00 {
public:
    virtual void v0();
    char pad4[4];
    NameField_17e00 name;
    char pad1[0x18 - 0x9];
    Sub18_17e00 s18;
    char pad2[0x70 - 0x19];
    JointDriver_17e00 *FUN_002248f0(int a);
};

struct Tracker_17e00 {
    void FUN_00222890(JointDriver_17e00 *o, float a, float b, float c, float d, float e, float f);
};

struct Mgr_17e00;

struct Player_17e00 {
    char pad0[0x10];
    Mgr_17e00 *mgr10;
    char pad14[0x8c - 0x14];
    float f8c;
    char pad90[0x334 - 0x90];
    Player_17e00 *other;
    float FUN_000354c0();
    bool FUN_00035660(V3_17e00 *out);
    bool FUN_00035550(V3_17e00 *out);
};

struct Mgr_17e00 {
    Player_17e00 *FUN_00059a30();
    Tracker_17e00 *FUN_00059a40();
    bool FUN_00059a50(V3_17e00 *out);
};

struct Holder_17e00 {
    Mgr_17e00 *FUN_000592a0();
};

struct Cfg_17e00 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    char pad20[0x2c - 0x20];
    float f2c;
    float f30;
    float f34;
};

void *thunk_FUN_0008d690(unsigned int size);

class CHeliDeathSpiralAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    Holder_17e00 *f1c;
    Cfg_17e00 *f20;
    JointDriver_17e00 *f24;
    V3_17e00 v28;
    V3_17e00 v34;
    float f40;
    float f44;
};

bool CHeliDeathSpiralAction::vfunc_6(int arg)
{
    Mgr_17e00 *mgr = f1c->FUN_000592a0();
    Player_17e00 *pl = mgr->FUN_00059a30();
    Tracker_17e00 *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg_17e00 *c0 = f20;
    float cf2c = c0->f2c;
    float cf30 = c0->f30;
    float cf34 = c0->f34;
    void *mem = thunk_FUN_0008d690(0x70);
    JointDriver_17e00 *o = 0;
    if (mem)
        o = ((JointDriver_17e00 *)mem)->FUN_002248f0(0);
    f24 = o;
    o->name.FUN_0027b040("heliDeathSpiral");
    f24->v0();
    tr->FUN_00222890(f24, -1.0f, cf2c, 1.0f, cf30, cf34, -1.0f);

    V3_17e00 pos0;
    pos0.x = 0.0f;
    pos0.y = 0.0f;
    pos0.z = 0.0f;
    mgr->FUN_00059a50(&pos0);
    f24->s18.FUN_0022be40(&pos0);
    float ang = pl->FUN_000354c0();
    f24->s18.FUN_00221d20(ang);
    pl->FUN_00035660(&v34);

    Player_17e00 *other = pl->other;
    V3_17e00 a;
    V3_17e00 b;
    a.z = 0.0f;
    a.y = 0.0f;
    a.x = 0.0f;
    b.z = 0.0f;
    b.y = 0.0f;
    b.x = 0.0f;
    if (other) {
        other->mgr10->FUN_00059a50(&a);
        other->FUN_00035660(&b);
    }

    float k = f20->f14;
    V3_17e00 t = b;
    volatile V3_17e00 *w = (volatile V3_17e00 *)&v34;
    w->x = k * w->x;
    w->y = k * w->y;
    w->z = k * w->z;
    t.x = t.x * (1.0f - k);
    t.y = t.y * (1.0f - k);
    t.z = t.z * (1.0f - k);
    volatile V3_17e00 *tv = (volatile V3_17e00 *)&t;
    w->x = tv->x + w->x;
    w->y = tv->y + w->y;
    w->z = tv->z + w->z;

    f40 = pl->f8c;
    V3_17e00 c;
    pl->FUN_00035550(&c);
    c.y = 0.0f;
    c.FUN_0022d110();

    V3_17e00 d;
    d.x = t.x;
    d.y = 0.0f;
    d.z = t.z;
    float dlen = d.FUN_0022d110();
    float sign = -1.0f;
    if (!(d.z * c.z + d.x * c.x + d.y * c.y < 0.0f))
        sign = 1.0f;

    V3_17e00 e;
    e.x = pos0.x - a.x;
    e.y = 0.0f;
    e.z = pos0.z - a.z;
    float elen = e.FUN_0022d110();
    if (elen > 0.0f)
        f40 = sign / elen * dlen + f40;

    float lo = f20->f18;
    float hi = f20->f1c;
    if (f40 > 0.0f) {
        if (lo > f40)
            f40 = lo;
        if (hi > lo && f40 > hi)
            f40 = hi;
    } else {
        if (-lo < f40)
            f40 = -lo;
        if (hi > lo && -hi > f40)
            f40 = -hi;
    }
    v28.x = v34.x;
    v28.y = v34.y;
    v28.z = v34.z;
    f44 = pl->FUN_000354c0();
    return true;
}
