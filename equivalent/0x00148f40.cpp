// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 18/18)
// hulkfight::motion::CivilianThrowAction::vfunc_3 @ 0x00148f40
// hulkfight::motion::CivilianThrowAction::vfunc_3 @ 0x00148f40
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Name {
    int lo;
    int hi;
    Name(const Name &o) throw();
    ~Name() throw();
};

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const Vec3 *other, float eps);
};

struct Ref {
    virtual void AddRef();
    virtual void Release();
};

struct Event {
    char data[0x20];
    Event *FUN_001c9e70(Name key);
};

struct Dispatcher {
    void FUN_001cbc20(Event *m);
};

struct World {
    char pad0[0x30];
    Dispatcher *dispatcher;
};

struct Hit {
    int f00, f04, f08, f0c, f10;
    int pad14;
    float dx, dy, dz;       // 0x18
    char flag24;
    char pad25[3];
    float vx, vy, vz;       // 0x28
    char flag34;
    char pad35[0x4c - 0x35];
    Ref *r4c;               // 0x4c
    char pad50[0x58 - 0x50];
    int f58, f5c;
    char pad60[0x64 - 0x60];
    float f64;
    float f68;
    char pad6c[0x78 - 0x6c];
    float f78;
    float f7c;
    int f80;
    Ref *r84;               // 0x84
    float f88;
    float f8c;
    Hit *FUN_00059820();
    void FUN_00059300();
};

struct Shape {
    char pad0[0x10];
    Vec3 v10;               // 0x10
    float a1c, a20, a24, a28, a2c, a30;
    int a34;
    float a38, a3c;
};

struct Sub {
    Sub *FUN_00221c40();
    void FUN_0022c3b0(const Vec3 *a, Vec3 *b);
};

struct Anchor {
    char pad0[0x10];
    Sub sub;                // 0x10
};

struct Body {
    Anchor *FUN_00059a40();
    void FUN_00059a50(Vec3 *out);
};

struct Target {
    char pad0[8];
    Name name;              // 8
    char pad10[0x64 - 0x10];
    Vec3 pos;               // 0x64
    char pad70[0x100 - 0x70];
    Ref *f100;
    void FUN_00080cb0(int v);
    void FUN_00081420(Hit *h);
};

struct Fighter {
    char pad0[0x10];
    Body *body;             // 0x10
    char pad14[0x12c - 0x14];
    Ref *f12c;
    char pad130[0x328 - 0x130];
    Ref *f328;
    Target *FUN_00036020();
    void FUN_0003b160(Target *t);
    float FUN_0003ec00(int v);
};

struct Holder {
    Fighter *FUN_00059a30();
};

struct Params_148f40 {
    Holder *FUN_000592a0();
};

extern int FUN_00097a30(float a1, float a2, float a3, Ref *a4, int a5, Vec3 *a6, int a7, Vec3 *a8,
                        int a9, int a10, int a11, int a12);

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::CivilianThrowAction::vfunc_3(int a, int b) {
    Fighter *fighter = (*(Params_148f40 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;
    Target *target = fighter->FUN_00036020();
    if (target == 0)
        return false;

    Event ev;
    ev.FUN_001c9e70(target->name);
    DAT_004dd700->dispatcher->FUN_001cbc20(&ev);

    Vec3 pos;
    pos.x = 0; pos.y = 0; pos.z = 0;
    pos = target->pos;
    Vec3 zero;
    zero.x = 0; zero.y = 0; zero.z = 0;
    Vec3 cur = (*(Shape * *)&this->f_1c)->v10;
    Vec3 dir;
    if (!cur.FUN_0022d2b0(&zero, 1.0e-5f)) {
        Anchor *an = fighter->body->FUN_00059a40();
        if (an != 0) {
            cur = (*(Shape * *)&this->f_1c)->v10;
            an->sub.FUN_00221c40()->FUN_0022c3b0(&cur, &dir);
        }
    } else {
        zero.x = 0; zero.y = 0; zero.z = 0;
        fighter->body->FUN_00059a50(&zero);
        dir.x = pos.x - zero.x;
        dir.y = pos.y - zero.y;
        dir.z = pos.z - zero.z;
    }
    dir.FUN_0022d110();

    Ref *held = fighter->f328;
    if (held == target->f100)
        held = 0;
    fighter->FUN_0003b160(0);

    Hit h;
    h.FUN_00059820();
    h.dx = dir.x;
    h.dy = dir.y;
    h.f08 = 0; h.f0c = 0; h.f10 = 0;
    h.dz = dir.z;
    h.f00 = 0; h.f04 = 0;
    h.flag24 = 1;
    h.f58 = 0; h.f5c = 0;
    h.f68 = 0;
    h.f64 = 30.0f;   // 0x41f00000
    h.f78 = 1.0f;
    float t = fighter->FUN_0003ec00(2);

    Ref *grip = fighter->f12c;
    if (grip) grip->AddRef();
    if (h.r4c) h.r4c->Release();
    h.r4c = grip;
    h.flag34 = 1;
    h.f7c = t;
    h.f80 = 0;
    if (held) held->AddRef();
    if (h.r84) h.r84->Release();
    h.r84 = held;

    Shape *sh = (*(Shape * *)&this->f_1c);
    h.f88 = (sh->a20 - sh->a1c) * t + sh->a1c;
    float y = (sh->a28 - sh->a24) * t + sh->a24;
    h.f8c = (sh->a30 - sh->a2c) * t + sh->a2c;
    h.f68 = (sh->a3c - sh->a38) * t + sh->a38;
    FUN_00097a30(y, h.f8c, -1.0f, held, 0, &pos, sh->a34, &dir, 0, 0, 0, 1);
    h.vx = dir.x * y;
    h.vy = dir.y * y;
    h.vz = dir.z * y;
    target->FUN_00080cb0(7);
    target->FUN_00081420(&h);
    h.FUN_00059300();
    return true;
}
