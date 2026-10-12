// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 64/66, incomplete)
// FUN_000437a0 @ 0x000437a0
extern "C" int atexit(void (*)());
extern "C" int __cdecl FUN_00266da0(int mode);
void* __cdecl FUN_0008d690(unsigned int size);
void FUN_00363b90();

struct Vec3 {
    float x, y, z;
};

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* name);
};

extern unsigned DAT_004dc318;
extern Key DAT_004dc310;
extern unsigned DAT_004dc080;
extern unsigned DAT_004dc084;

class Event {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0xb0 - 4];
    Event* FUN_000598e0(int first, void* params);
};

struct Target2 {
    char pad00[0x1d20];
    float f1d20;
};

struct Target {
    char pad00[8];
    Target2* f08;
    int f0c;
};

struct Params {
    char pad00[0x24];
    char b24;
    char pad25[3];
    Vec3 vec28;
    char pad34[0x44 - 0x34];
    char b44;
    char pad45[3];
    int f48;
    Target* f4c;
    char pad50[4];
    int f54;
    char pad58[0x80 - 0x58];
    int f80;
    char pad84[0x90 - 0x84];
    char b90;
    unsigned char b91;
};

struct Actor {
    void FUN_00231ad0(Vec3* where, Event* ev, int t);
    char FUN_00231a40(Vec3* where, Event* ev);
    char FUN_001d6ec0(int a, Target* t, int c);
};

class Holder110 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Actor* v8(Event* ev, int z);
};

struct Obj11c {
    char pad00[0x110];
    Holder110* f110;
    char pad114[0x1a4 - 0x114];
    int f1a4;
    unsigned __int64 FUN_000443c0();
};

struct Sub2 {
    float FUN_002220d0();
};

struct Anchor2 {
    char pad00[0x10];
    Sub2 sub;
};

struct Owner {
    int first;
    Anchor2* FUN_00059a40();
};

struct Sub {
    void FUN_00232240();
};

struct Entry {
    Actor* a;
    char pad[76];
};

extern "C" float __cdecl FUN_00224f10(Vec3* v);
extern "C" float __cdecl FUN_00224fc0(float a, float b);

class Unit {
public:
    char pad00[0x10];
    Owner* f10;
    char pad14[0xb4 - 0x14];
    Sub subB4;
    char padB5[0xdc - 0xb5];
    Vec3 fdc;
    char pade8[0x11c - 0xe8];
    Obj11c* f11c;
    char pad120[0x318 - 0x120];
    int f318;
    int f31c;
    float f320;
    char pad324[0x3a8 - 0x324];
    Entry entries[8];
    float f628;
    char pad62c[0x1d28 - 0x62c];
    char b1d28;
    int FUN_00035fe0();
    char FUN_00043350(float dt, Target* t, int a, int b, int c, int d);
    Actor* FUN_000392e0(Event* ev);
    void FUN_00035930(int v);
    int FUN_00036e40(Key* k);
    void FUN_00037000();
    char FUN_000437a0(float dt, Params* p, Vec3* where, Actor* actor, char flag5);
};

union FloatBits {
    float f;
    unsigned int u;
};

char Unit::FUN_000437a0(float dt, Params* p, Vec3* where, Actor* actor, char flag5)
{
    if (f11c == 0)
        return 0;
    int saved = FUN_00266da0(0xd);
    int limit = p->f54;
    char counted = p->b24;
    int extra = 0;
    if (f11c != 0)
        extra = f11c->f1a4;
    if (f31c + f318 + extra > limit)
        counted = 0;
    char behind = 0;
    int idx = FUN_00035fe0();
    if (idx >= 0) {
        float yawBase = FUN_00224f10(&p->vec28) + 3.1415927f;
        Anchor2* anchor = f10->FUN_00059a40();
        float ang;
        if (anchor == 0)
            ang = 0.0f;
        else
            ang = anchor->sub.FUN_002220d0();
        FloatBits r;
        r.f = FUN_00224fc0(yawBase, ang);
        r.u &= 0x7fffffff;
        if (f628 * 0.5f > r.f)
            behind = 1;
    }
    if (b1d28 && !p->b90)
        dt = 0.0f;
    if (f11c != 0) {
        if (f11c->FUN_000443c0() == ((unsigned __int64)DAT_004dc084 << 32 | DAT_004dc080) && p->b90)
            dt = 0.0f;
    }
    char ok;
    if (behind) {
        Actor* target = 0;
        if (idx >= 0 && idx < 8)
            target = entries[idx].a;
        ok = target->FUN_001d6ec0((int)dt, p->f4c, 0);
    } else {
        ok = FUN_00043350(dt, p->f4c, p->f48, p->f80, 0, p->b91);
    }
    p->b44 = !ok;
    if (!counted) {
        float factor = 1.0f;
        Target* t = p->f4c;
        if (t != 0 && t->f0c == 1 && t->f08 != 0)
            factor = t->f08->f1d20;
        f320 = factor * dt + f320;
    }
    Event* ev = (Event*)FUN_0008d690(0xb0);
    if (ev != 0)
        ev = ev->FUN_000598e0(f10->first, p);
    else
        ev = 0;
    ev->v0();
    if (!flag5) {
        Actor* act = actor;
        if (act == 0)
            act = FUN_000392e0(ev);
        if (act != 0) {
            Vec3* w = where;
            if (w == 0)
                w = &fdc;
            act->FUN_00231ad0(w, ev, -(int)dt);
            if (act->FUN_00231a40(w, ev) && ok) {
                FUN_00035930(6);
                if ((DAT_004dc318 & 1) == 0) {
                    DAT_004dc318 |= 1;
                    DAT_004dc310.FUN_0027af00();
                    atexit(FUN_00363b90);
                }
                DAT_004dc310.FUN_0027b040("no_ai_reset");
                int r = FUN_00036e40(&DAT_004dc310);
                Sub* sub = &subB4;
                if (sub != 0 && r == 0) {
                    FUN_00037000();
                    sub->FUN_00232240();
                }
            }
        }
    } else {
        Holder110* h = f11c->f110;
        if (h != 0) {
            Actor* act = h->v8(ev, 0);
            if (act != 0) {
                Vec3* w = where;
                if (w == 0)
                    w = &fdc;
                act->FUN_00231ad0(w, ev, -(int)dt);
            }
        }
    }
    ev->v1();
    FUN_00266da0(saved);
    return ok;
}
