// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// CHeliDeathSpiralAction::vfunc_6 @ 0x00017e00
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField {
    void FUN_0027b040(const char *s);
};

struct Sub18 {
    void FUN_00221d20(float a);
    void FUN_0022be40(const V3 *v);
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

struct Tracker {
    void FUN_00222890(Obj70 *o, float a, float b, float c, float d, float e, float f);
};

struct Mgr;

struct Player {
    char pad0[0x10];
    Mgr *mgr10;
    char pad14[0x8c - 0x14];
    float f8c;
    char pad90[0x334 - 0x90];
    Player *other;
    float FUN_000354c0();
    bool FUN_00035660(V3 *out);
    bool FUN_00035550(V3 *out);
};

struct Mgr {
    Player *FUN_00059a30();
    Tracker *FUN_00059a40();
    bool FUN_00059a50(V3 *out);
};

struct Holder {
    Mgr *FUN_000592a0();
};

struct Cfg {
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
    Holder *f1c;
    Cfg *f20;
    Obj70 *f24;
    V3 v28;
    V3 v34;
    float f40;
    float f44;
};

bool CHeliDeathSpiralAction::vfunc_6(int arg)
{
    Mgr *mgr = f1c->FUN_000592a0();
    Player *pl = mgr->FUN_00059a30();
    Tracker *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg *c0 = f20;
    float cf2c = c0->f2c;
    float cf30 = c0->f30;
    float cf34 = c0->f34;
    void *mem = thunk_FUN_0008d690(0x70);
    Obj70 *o = 0;
    if (mem)
        o = ((Obj70 *)mem)->FUN_002248f0(0);
    f24 = o;
    o->name.FUN_0027b040("heliDeathSpiral");
    f24->v0();
    tr->FUN_00222890(f24, -1.0f, cf2c, 1.0f, cf30, cf34, -1.0f);

    V3 pos0;
    pos0.x = 0.0f;
    pos0.y = 0.0f;
    pos0.z = 0.0f;
    mgr->FUN_00059a50(&pos0);
    f24->s18.FUN_0022be40(&pos0);
    float ang = pl->FUN_000354c0();
    f24->s18.FUN_00221d20(ang);
    pl->FUN_00035660(&v34);

    Player *other = pl->other;
    V3 a;
    V3 b;
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
    V3 t = b;
    volatile V3 *w = (volatile V3 *)&v34;
    w->x = k * w->x;
    w->y = k * w->y;
    w->z = k * w->z;
    float om = 1.0f - k;
    t.x = t.x * om;
    t.y = t.y * om;
    t.z = t.z * om;
    w->x = t.x + w->x;
    w->y = t.y + w->y;
    w->z = t.z + w->z;

    f40 = pl->f8c;
    V3 c;
    pl->FUN_00035550(&c);
    c.y = 0.0f;
    c.FUN_0022d110();

    V3 d;
    d.x = t.x;
    d.y = 0.0f;
    d.z = t.z;
    float dlen = d.FUN_0022d110();
    float sign = -1.0f;
    if (!(d.z * c.z + d.x * c.x + d.y * c.y < 0.0f))
        sign = 1.0f;

    V3 e;
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
