// STATUS: equivalent (tools/equiv.py level 3: 3070 inputs, branch coverage 60/60)
// FUN_001d8350 @ 0x001d8350
// equiv-map: ??0Id64@@QAE@ABU0@@Z = 0x0027af30
#include "decls/address.h"
struct V3_1d8350 {
    float x, y, z;
    float FUN_000259c0();
    float FUN_0022d180();
};

struct Id64 {
    unsigned int lo, hi;
    Id64(const Id64 &src);
};

struct Event_1d8350 {
    char data[0x28];
    void FUN_001ca540(Id64 self, Id64 other, int id);
};

struct Voice_1d8350 {
    void FUN_00092540(int kind, Id64 id, int z);
    char FUN_00092dc0(int v);
    char FUN_00092940(int v);
};

struct Sound_1d8350 {
    void FUN_00090720(const char *name, int flag);
};

struct Singleton_4dd6ec {
    char pad0[0x3c];
    Voice_1d8350 *f3c;
    char pad40[8];
    Sound_1d8350 *f48;
    Voice_1d8350 *FUN_00086340();
    Sound_1d8350 *FUN_00086370();
};

struct Sender {
    void FUN_001cbc20(Event_1d8350 *e);
};

struct World {
    char pad0[0x30];
    Sender *f30;
    char pad34[0x54 - 0x34];
    Singleton_4dd6ec *f54;
};
extern char DAT_004e2518;

struct Fighter_1d8350 {
    char pad0[0x10];
    int *f10;
    char pad14[0x1b0c - 0x14];
    float f1b0c;
    char FUN_000373a0(int state);
    void FUN_000352b0(V3_1d8350 *out);
};

struct Owner_1d8350 {
    char pad0[8];
    Id64 id8;
};

V3_1d8350 *__cdecl FUN_00083e00(V3_1d8350 *out, V3_1d8350 *a, float s);

class Collector_1d8350 {
public:
    char pad0[8];
    Id64 id8;              // 8
    char pad10[0xec - 0x10];
    Owner_1d8350 *owner;          // 0xec
    float f0;              // 0xf0
    float f4;              // 0xf4
    char bf8;
    char padf9[3];
    int fc;                // 0xfc
    char pad100[0x144 - 0x100];
    char b144;
    char pad145[0x150 - 0x145];
    int state;             // 0x150
    float f154;

    V3_1d8350 *FUN_001d6b40();
    void FUN_001d7810(V3_1d8350 v);
    void FUN_0027d4f0(int v);
    void FUN_001d8350(Fighter_1d8350 *a);
};

struct Frame_1d8350 {
    V3_1d8350 pc;                 // 0xc
    V3_1d8350 d;                  // 0x18
    V3_1d8350 tmp;                // 0x24
    V3_1d8350 v1;                 // 0x30
    V3_1d8350 out;                // 0x3c
    Event_1d8350 ev;              // 0x48
};

void Collector_1d8350::FUN_001d8350(Fighter_1d8350 *a)
{
    Frame_1d8350 f;
    if (a == 0)
        return;
    if (a->f1b0c <= 0.0f)
        return;
    if (b144) {
        if (f154 < 0.5f)
            return;
    }
    if (fc == 2 || fc == 3)
        return;
    if (bf8)
        return;
    if (!a->FUN_000373a0(state))
        return;
    a->FUN_000352b0(&f.v1);
    V3_1d8350 *p = FUN_001d6b40();
    f.pc.x = p->x;
    f.pc.y = p->y;
    f.pc.z = p->z;
    f.d.x = f.v1.x - f.pc.x;
    f.d.y = f.v1.y - f.pc.y;
    f.d.z = f.v1.z - f.pc.z;
    float len = f.d.FUN_000259c0();
    int st = state;
    if (st == 1 || st == 2 || st == 3 || st == 4 || st == 0xb || st == 0xc || st == 0xd) {
        if (len > 1.0f) {
            if (f0 < 1.0f)
                f0 = 0.05f;
            double t = f4 + 0.2f;
            f4 = t;
            f0 = t + f0;
            if (f0 > len)
                f0 = len;
            f.d.FUN_0022d180();
            V3_1d8350 *res = FUN_00083e00(&f.out, &f.d, f0);
            V3_1d8350 r;
            r.x = f.pc.x + res->x;
            r.y = f.pc.y + res->y;
            r.z = f.pc.z + res->z;
            FUN_001d7810(r);
            return;
        }
    }
    if ((unsigned int)st > 0xd)
        return;
    int kind = 1;
    if (st == 0)
        kind = 0;
    else if (st == 7)
        kind = 2;
    else if (st == 0xc || st == 0xd)
        kind = 3;
    if (kind == 0) {
        f4 = 0;
        f0 = 0;
        return;
    }
    if (kind == 3) {
        DAT_004dd6ec->FUN_00086340()->FUN_00092540(5, id8, 0);
        DAT_004dd6ec->FUN_00086370()->FUN_00090720("smashcollect", 1);
    } else if (kind == 2) {
        DAT_004dd6ec->FUN_00086340()->FUN_00092540(4, id8, 0);
        DAT_004e2518 = 1;
    }
    FUN_0027d4f0(10);
    int s = state;
    bf8 = 1;
    if (s != 10 && s != 7)
        DAT_004dd6ec->FUN_00086370()->FUN_00090720("prop_collectables", 1);

    Sender *snd = DAT_004dd700->f30;
    if (snd == 0)
        return;
    int fid = *a->f10;
    f.ev.FUN_001ca540(id8, owner->id8, fid);
    int s2 = state;
    if (s2 == 1 || s2 == 2 || s2 == 3 || s2 == 4) {
        Voice_1d8350 *v = DAT_004dd700->f54->FUN_00086340();
        if (!v->FUN_00092dc0(0x15)) {
            v = DAT_004dd700->f54->FUN_00086340();
            if (v->FUN_00092940(0x15))
                snd->FUN_001cbc20(&f.ev);
        }
    }
    snd->FUN_001cbc20(&f.ev);
}
