// STATUS: equivalent (tools/equiv.py level 3: 3442 inputs, branch coverage 407/432, incomplete)
// hulkfight::motion::ProjectileMissile::vfunc_4 @ 0x0019e910
// Per-frame update of a homing missile: steering/speed, collision sweep, hit dispatch
// (actors, characters, props), trail effect, and the area-damage explosion.
// The locals live in one Frame struct at the original's stack offsets (sub esp 0x2d8):
// several out-parameters and event records share slots, as in the original.
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct RefObj_19e910 {
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct Vec3_19e910 {
    float x, y, z;
    float FUN_0022d110() throw();                                   // normalise, returns old length
    float FUN_000111f0() throw();                                   // squared length
    void FUN_00011160(float s, Vec3_19e910 *v) throw();             // this += v * s
    void FUN_00011110(Vec3_19e910 *a, Vec3_19e910 *b) throw();      // this = a - b
    void FUN_000111b0(Vec3_19e910 *a, Vec3_19e910 *b) throw();      // this = a x b
    bool FUN_0022d2b0(Vec3_19e910 *v, float eps) throw();           // equal within eps
};
typedef Vec3_19e910 Vec3;

struct Mat4_19e910 {
    float m[12];
    Vec3 trans;
    float w;
    void FUN_0022b980() throw();                                    // identity
    void FUN_0022baf0(Vec3 *axis, float angle) throw();
    void FUN_0022c3b0(Vec3 *in, Vec3 *out) throw();
};

struct Name_19e910 {
    unsigned int lo, hi;
    void FUN_0027af60(unsigned int lo, unsigned int hi) throw();
    void FUN_001cae40(const char *s) throw();
};

struct Coll_19e910;
struct Node_19e910;
struct Actor_19e910;

struct CFightParamsCollision_19e910 {
    virtual void AddRef() throw();
    virtual void Release() throw();
    CFightParamsCollision_19e910 *FUN_000598e0(int id, struct Request_19e910 *req) throw();
};

struct Slots_19e910 {
    bool FUN_00231e80(struct Sink_19e910 *s) throw();
};

struct Sink_19e910 {
    void FUN_00231ad0(Slots_19e910 *slots, CFightParamsCollision_19e910 *job, int prio) throw();
};

struct Queue_19e910 {
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual Sink_19e910 *v8(CFightParamsCollision_19e910 *job, int z) throw();
};

struct Request_19e910 {
    char pad0[8];
    Vec3 pos;           // 0x08
    unsigned char b14;  // 0x14
    char pad15[3];
    Vec3 normal;        // 0x18
    char pad24[4];
    Vec3 vel;           // 0x28
    char pad34[4];
    Vec3 force;         // 0x38
    char pad44[4];
    int f48;            // 0x48
    void *f4c;          // 0x4c
    void *f50;          // 0x50
    char pad54[0x78 - 0x54];
    float f78;          // 0x78
    char pad7c[4];
    float f80;          // 0x80
    char pad84[0x90 - 0x84];
    unsigned char b90;  // 0x90
    char pad91[0x98 - 0x91];
    void FUN_00059820() throw();
    void FUN_00059300() throw();
};

struct Hit_19e910 {
    float t;
    struct CollItem_19e910 *obj;
    void *shape;
};

struct CollItem_19e910 {
    char pad0[0x18];
    Coll_19e910 *f18;
    char pad1c[4];
    void *f20;
};

struct PtrList_19e910 {
    CollItem_19e910 **begin;
    CollItem_19e910 **end;
};

struct Center_19e910 {
    void FUN_0016fc60(Vec3 *out) throw();
};

struct Coll_19e910 {
    char pad0[8];
    void *f8;           // Node or Actor, by type
    int type;           // 0x0c
    char pad10[0x40 - 0x10];
    Vec3 v40;
    char pad4c[0x70 - 0x4c];
    Center_19e910 *f70;
};

struct Holder_19e910 {
    char pad0[8];
    Actor_19e910 *f8;
    int fc;
};

struct Ctl_19e910 {
    int FUN_001d5e80(int id) throw();
};

struct KeySrc_19e910 {
    char pad0[0x24];
    unsigned int *key;
};
struct KeyOwner_19e910 {
    char pad0[8];
    KeySrc_19e910 *f8;
};

struct Node_19e910 {
    char pad0[0x10];
    int f10;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[0x64 - 0x44];
    Vec3 v64;
    char pad70[0xec - 0x70];
    Ctl_19e910 *fec;
    char padf0[0xfc - 0xf0];
    int ffc;
    Coll_19e910 *f100;
    char pad104[0x114 - 0x104];
    Holder_19e910 *f114;
    char pad118[0x148 - 0x118];
    Actor_19e910 *f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    void FUN_001d6e10(void *who) throw();
    void FUN_001d8c70(RefObj_19e910 *t) throw();
    Vec3 *FUN_001d6b40() throw();
    KeyOwner_19e910 *FUN_001d68d0() throw();
    Coll_19e910 *FUN_001d72e0() throw();
    bool FUN_001d6980() throw();
    void FUN_001d6ec0(int amount, void *who, int z) throw();
    bool FUN_001d7300() throw();
    void FUN_001d82d0() throw();
    void FUN_001d86d0(Vec3 *impulse, Vec3 *at) throw();
    void FUN_00081420(Request_19e910 *req) throw();
    bool FUN_000134e0() throw();
};

struct Team_19e910 {
    char pad0[0x14];
    int f14;
    char pad18[0x34 - 0x18];
    float f34;
    char pad38[0x1b0 - 0x38];
    int f1b0;
    char pad1b4[0x384 - 0x1b4];
    char b384;
};

struct IdBox_19e910 {
    int id;
};

struct Rider_19e910 {
    bool FUN_0001e870(Node_19e910 *who, Vec3 *v) throw();
};

struct Actor_19e910 {
    char pad0[0x10];
    IdBox_19e910 *f10;
    char pad14[0xdc - 0x14];
    Slots_19e910 fdc;
    char padd[0x11c - 0xdd];
    Team_19e910 *f11c;
    char pad120[0x128 - 0x120];
    Node_19e910 *f128;
    void *f12c;
    char pad130[0x328 - 0x130];
    RefObj_19e910 *f328;
    char pad32c[0x334 - 0x32c];
    int f334;
    char pad338[0x1b60 - 0x338];
    Queue_19e910 *f1b60;
    Rider_19e910 *f1b64;
    char pad1b68[0x1d14 - 0x1b68];
    float f1d14;
    char pad1d18[4];
    int f1d1c;
    char pad1d20[0x1d2c - 0x1d20];
    int f1d2c;
    Node_19e910 *FUN_00035ef0(int i) throw();
    void FUN_000368d0(int on) throw();
    void FUN_00035fa0(int on) throw();
    bool FUN_0003b4f0(Vec3 *dir) throw();
    void FUN_00035550(Vec3 *out) throw();
    RefObj_19e910 *FUN_00039c60(Vec3 *pos, Vec3 *v, float a, float b, int c, int d, int e) throw();
    bool FUN_000360f0() throw();
    void FUN_00043350(float dmg, void *who, int a, float s, int b, int c) throw();
    void FUN_00043ae0(void *who, Vec3 *at, float a, float b, float c, int d, int e, int f, int g) throw();
    void FUN_000350c0(Vec3 *out) throw();
    void FUN_0003aef0(int i) throw();
};

struct Rng_19e910 {
    int FUN_00011380(int lo, int hi) throw();
};

struct Fx_19e910 {
    void FUN_00059a30() throw();
};
struct Registry_19e910 {
    Actor_19e910 *FUN_00059c10(int id) throw();
    Fx_19e910 *FUN_00059ba0(int id) throw();
};

struct Spawner_19e910 {
    int FUN_00022960(unsigned int lo, unsigned int hi) throw();
};
struct Mid_19e910 {
    Spawner_19e910 *FUN_00203d70() throw();
};
struct Scene_19e910 {
    Mid_19e910 *FUN_000862a0() throw();
};

struct Factory_19e910 {
    void FUN_001dd470(int h, Mat4_19e910 *m, float dt) throw();
    void FUN_001e2ed0(int h, unsigned int lo, unsigned int hi) throw();
    float FUN_001dddf0() throw();
};

struct W24_19e910 {
    char pad0[0x18];
    float floorY;
    bool FUN_00201e00(Vec3 *from, Vec3 *to, int one, Vec3 *hitPos, Vec3 *hitNormal, void **thing, struct HitInfo_19e910 **info) throw();
};

struct HitInfo_19e910 {
    char pad0[0x38];
    int f38;
    Node_19e910 *f3c;
};

struct Pool_19e910 {
    char pad0[8];
    Hit_19e910 *f8;
};

struct CollWorld_19e910 {
    bool FUN_002ee140(Pool_19e910 *pool, Vec3 *from, Vec3 *to, int z) throw();
    PtrList_19e910 *FUN_002ed700() throw();
};
struct W10_19e910 {
    char pad0[8];
    CollWorld_19e910 *f8;
};

struct Snd_19e910 {
    void FUN_000d4620(int a, const char *name, int b, int c, float d) throw();
};
struct SndOwner_19e910 {
    char pad0[4];
    Snd_19e910 *f4;
};
struct Sounds_19e910 {
    char pad0[0x124];
    Actor_19e910 *f124;
    const char *FUN_00025890(int i) throw();
    int *FUN_00025930(int *out, int z) throw();
};

struct Achv_19e910 {
    bool FUN_001ccff0() throw();
};
struct Unlocks_19e910 {
    void FUN_001cbc20(Name_19e910 *n) throw();
};

struct Decals_19e910 {
    void FUN_001f6cd0(void *thing, HitInfo_19e910 *info, Vec3 *pos, Vec3 *normal, Vec3 *dir, int n, float a, float b, int *out, int z) throw();
};
struct Fxm_19e910 {
    void FUN_001ebd80(Node_19e910 *who, const char *name, float r, int z) throw();
    void FUN_001ebea0(int decal, Node_19e910 *who) throw();
};

struct World {
    char pad0[0xc];
    Factory_19e910 *f0c;
    W10_19e910 *f10;
    char pad14[0x20 - 0x14];
    Sounds_19e910 *f20;
    W24_19e910 *f24;
    char pad28[4];
    Achv_19e910 *f2c;
    Unlocks_19e910 *f30;
    Fxm_19e910 *f34;
    Decals_19e910 *f38;
    SndOwner_19e910 *f3c;
    char pad40[4];
    Registry_19e910 *f44;
    char pad48[0x54 - 0x48];
    Scene_19e910 *f54;
};


struct Gravity_19e910 {
    char pad0[0x10];
    Vec3 g;
};

struct Unlock_19e910 {
    char pad0[8];
    char b8;
    char pad9[0x20 - 9];
    char b20;
    bool FUN_00091f40() throw();
};
struct UnlockTable_19e910 {
    void *FUN_00092ad0(int id) throw();
};
struct Singleton_4dd6ec {
    UnlockTable_19e910 *FUN_00086340() throw();
};

struct Trails_19e910 {
    int FUN_00283d60(float a, int b, KeyOwner_19e910 *c, int d, Name_19e910 *e, Vec3 *pts, int n, Name_19e910 *f, Vec3 at, int g, int h, int i) throw();
    void FUN_002834e0(int h) throw();
    void FUN_00283a40(void *fx, Mat4_19e910 *m, float a, float b) throw();
};

struct Cfg_19e910 {
    char pad0[0x20];
    unsigned int id20Lo;
    unsigned int id20Hi;
    Vec3 v28;
    char pad34[0x68 - 0x34];
    float f68;
    float f6c;
    char pad70[0xb0 - 0x70];
    float fb0;
    char padb4[4];
    float fb8;
    Queue_19e910 *fbc;
    char padc0[0xc8 - 0xc0];
    Queue_19e910 *fc8;
    char padcc[0xd4 - 0xcc];
    float fd4;
    float fd8;
    const char *fdc;
    int fe0;
    char pade4[4];
    char fe8[8];
    Vec3 vf0;
    float ffc;
    Queue_19e910 *f100;
    char pad104[0x10c - 0x104];
    float f10c;
    float f110;
    float f114;
    char pad118[0x124 - 0x118];
    int f124;
    unsigned int id128Lo;
    unsigned int id128Hi;
    char pad130[0x13c - 0x130];
    int f13c;
    int f140;
    int f144;
    void FUN_00193660(Vec3 *out) throw();
    Vec3 *FUN_001936f0(Vec3 *out) throw();
};

extern char DAT_0049dab8;
extern char DAT_0049db1c;
extern char DAT_0049dafc;
extern char FUN_0027af00;
extern char FUN_0027af50;
extern char FUN_00011090;

int __cdecl FUN_00266da0(int tag) throw();
Rng_19e910 *__cdecl FUN_000964d0() throw();
float __cdecl FUN_000964e0() throw();
int __cdecl FUN_00098190(float dt, float speed, float accel, float minSpeed, RefObj_19e910 *target, int a,
                         Vec3 *pos, Vec3 *dir, float turn, float b, float c, int mode) throw();
void __stdcall FUN_00011520(void *arr, unsigned int size, int n, void *ctor) throw();
void __stdcall FUN_00013420(void *arr, unsigned int size, int n, void *dtor) throw();
Trails_19e910 *__cdecl FUN_0027f250() throw();
Pool_19e910 *__cdecl FUN_00202f00() throw();
void __cdecl FUN_002f1ce0(Vec3 *from, void *shape, Vec3 *outNormal, float *outDist) throw();
Unlock_19e910 *__cdecl FUN_00344e74(void *p, int off, void *src, void *dst, int isRef) throw();
void __cdecl FUN_00018810(void **slot, void *obj) throw();
void *__cdecl FUN_0008d690(unsigned int size) throw();
bool __cdecl FUN_00096b50(RefObj_19e910 *t, Vec3 *out, float *out2) throw();
void __cdecl FUN_00224db0(Mat4_19e910 *m, Vec3 *a, Vec3 *b) throw();
Vec3 *__cdecl FUN_00083e00(Vec3 *out, Vec3 *v, float s) throw();
bool __cdecl FUN_002027c0(Vec3 *from, Vec3 *to, int a, int b, Vec3 *outA, Vec3 *outB, int c, int d) throw();

namespace hulkfight {
namespace motion {

class ProjectileMissile {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(float dt);
    virtual Node_19e910 *vfunc_5();
    char pad04[8];
    float life;             // 0x0c
    char dead;              // 0x10
    char pad11[0x1c - 0x11];
    char randomSide;        // 0x1c
    char flipSide;          // 0x1d
    unsigned char setSide;  // 0x1e
    char pad1f;
    float f20;
    float f24;
    char locked;            // 0x28
    char pad29[3];
    float f2c;
    float f30;
    int f34;
    char b38;
    char pad39[3];
    Cfg_19e910 *cfg;        // 0x3c
    int h40;
    int f44;
    float f48;
    float f4c;
    RefObj_19e910 *target;  // 0x50
    Vec3 prev;              // 0x54
    Vec3 pos;               // 0x60
    Vec3 dir;               // 0x6c
    float speed;            // 0x78
    float f7c;
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    unsigned int f9c;
    int fa0;
    char ba4;
    char pada5[3];
    float fa8;
    float fac;
    float fb0;
    float fb4;
    float fb8;
    float fbc;
    int fc0;
    float fc4;
    float fc8;
    float fcc;
    float fd0;
    float fd4;
    float fd8;
    void FUN_00196640(RefObj_19e910 *t) throw();
};

}
}

using hulkfight::motion::ProjectileMissile;

void ProjectileMissile::vfunc_4(float dt)
{
    struct Frame {
        char pad0[3];
        bool hit;                                   // 0x03
        union { float f; int i; int k; float dz; Sink_19e910 *sink; } u04;
        union { int mode; float accel; int i; Actor_19e910 *actor; float amount; float rad; } u08;
        union { float amt; float f; Coll_19e910 *hitObj; } u0c;
        Actor_19e910 *ent;                          // 0x10
        Vec3 hitPos;                                // 0x14
        union { unsigned int bits; float f; World *w; int i; float t; } u20;
        union { int i; CollWorld_19e910 *cw; PtrList_19e910 *list; } u24;
        Vec3 v28;
        Vec3 v34;
        Vec3 v40;
        Node_19e910 *owner;                         // 0x4c
        union { Queue_19e910 *mgr; float f; Snd_19e910 *snd; float dx; } u50;
        union { Factory_19e910 *factory; float dy; int decal; } u54;
        Vec3 v58;
        Vec3 hitNormal;                             // 0x64
        union { Hit_19e910 h; Vec3 p; } u70;
        union { W24_19e910 *w24; float rad2; } u7c;
        HitInfo_19e910 *hitInfo;                    // 0x80
        Vec3 tp1;                                   // 0x84
        Vec3 hitP2;                                 // 0x90
        Vec3 vs;                                    // 0x9c
        Vec3 vdir;                                  // 0xa8
        Vec3 tp5;                                   // 0xb4
        Vec3 d7;                                    // 0xc0
        Vec3 vcc;                                   // 0xcc
        void *hitThing;                             // 0xd8
        int tag;                                    // 0xdc
        Request_19e910 evt;                         // 0xe0
        Vec3 v178;
        Vec3 pts[2];                                // 0x184
        Vec3 buf;                                   // 0x19c
        union { Name_19e910 names[2]; Name_19e910 un; Mat4_19e910 m2; Vec3 out; } u1a8;
        Vec3 tmp1e8;
        Mat4_19e910 m;                              // 0x1f4
        Request_19e910 evt2;                        // 0x234
        Vec3 tmp2cc;                                // 0x2cc
    } fr;

    if (dead != 0)
        return;
    fr.u20.f = dt;
    fr.u20.bits &= 0x7fffffff;
    if (fr.u20.f <= 1e-05f)
        return;

    fr.tag = FUN_00266da0(0xd);
    fr.u54.factory = DAT_004dd700->f0c;
    fr.owner = vfunc_5();
    fr.ent = DAT_004dd700->f44->FUN_00059c10(f44);
    if (fr.owner != 0) {
        if (fr.ent != 0) {
            fr.owner->FUN_001d6e10(fr.ent->f12c);
            if (f48 == 0.0f && fr.ent->f1d1c != 0) {
                f48 = fr.ent->f1d14;
                f4c = fr.ent->f1d14;
                fr.ent->f1d1c--;
            }
        }
        if (target != 0)
            fr.owner->FUN_001d8c70(target);
    }

    float age = dt + fbc;
    fbc = age;
    if (f8c < 0.0f && (fr.owner == 0 || fr.owner->f114 == 0))
        life = life - dt;
    fr.u08.mode = 1;
    if (fr.ent != 0)
        fr.u08.mode = fr.ent->f1d2c;

    if (fr.owner != 0 && fr.owner->f114 != 0) {
        // carried: follow the holder
        Vec3 *p = fr.owner->FUN_001d6b40();
        pos.x = p->x;
        pos.y = p->y;
        pos.z = p->z;
    } else {
        int moved;
        if (locked != 0 && age > fd8) {
            fr.u04.f = f80;
            f7c = fr.u04.f;
            ba4 = 0;
            if (b38 != 0)
                moved = FUN_00098190(dt, speed, fr.u04.f, -3.40282347e+38f, target, 0, &pos, &dir, 0.0f, f48, f4c, fr.u08.mode);
            else
                moved = FUN_00098190(dt, speed, fr.u04.f, -3.40282347e+38f, target, 0, &pos, &dir, 0.0f, 0.0f, 0.0f, 1);
        } else if (ba4 != 0 && target != 0) {
            fr.v28 = ((Coll_19e910 *)target)->v40;
            fr.v28.x -= pos.x;
            fr.v28.y -= pos.y;
            fr.v28.z -= pos.z;
            float dist = fr.v28.FUN_0022d110();
            f7c = f2c;
            if (dist < fc8) {
                fd8 = f24 + fbc;
                fc4 = 0.0f;
                fb8 = 0.0f;
                fc0 = 0;
                locked = 1;
                f7c = f20;
            } else if (fbc > fac) {
                fd8 = fd0 + fbc;
                fc4 = 0.0f;
                fb8 = 0.0f;
                fc0 = 0;
                locked = 1;
                f7c = fcc;
            } else if (locked == 0 && fbc >= fa8 && fbc >= fb0) {
                // pick the next weave side
                if (randomSide != 0) {
                    Rng_19e910 *rng = FUN_000964d0();
                    int side;
                    int n = 0;
                    do {
                        side = rng->FUN_00011380(-1, 1);
                        if (side != fc0)
                            break;
                    } while (++n < 10);
                    fc0 = side;
                } else if (setSide != 0) {
                    fc0 = setSide;
                    setSide = 0;
                } else if (flipSide != 0) {
                    if (fc0 == 0)
                        fc0 = 1;
                    fc0 = -fc0;
                } else {
                    fc0 = fc0 + 1;
                    if (fc0 > 1)
                        fc0 = -1;
                }
                float period;
                if (f30 != 1.0f) {
                    if (f34 == 0) {
                        period = fb4 / f30;
                        f34 = 1;
                    } else {
                        fr.u04.k = (f34 % 2 == 0) ? f34 + 2 : f34 + 1;
                        f34 = f34 + 1;
                        period = fb4 / ((float)fr.u04.k / f30);
                    }
                } else {
                    period = fb4;
                }
                fb0 = period + fbc;
            }
            int side = fc0;
            fr.u24.i = side;
            fr.u0c.amt = fc4 = (float)fr.u24.i * fb8;
            if (side != 0) {
                if (fr.u0c.amt > 0.0f) {
                    f98 = fd4 + f98;
                    fr.u0c.amt = fr.u0c.amt - f98;
                } else if (fr.u0c.amt < 0.0f) {
                    f98 = fd4 + f98;
                    fr.u0c.amt = f98 + fr.u0c.amt;
                }
                if (side > 0) {
                    if (fr.u0c.amt < 0.0f) {
                        f7c = f80;
                        fr.u0c.amt = 0.0f;
                    }
                } else if (side < 0) {
                    if (fr.u0c.amt > 0.0f) {
                        f7c = f80;
                        fr.u0c.amt = 0.0f;
                    }
                }
            }
            if (b38 != 0)
                moved = FUN_00098190(dt, speed, f7c, -3.40282347e+38f, target, 0, &pos, &dir, fr.u0c.amt, f48, f4c, fr.u08.mode);
            else
                moved = FUN_00098190(dt, speed, f7c, -3.40282347e+38f, target, 0, &pos, &dir, fr.u0c.amt, 0.0f, 0.0f, 1);
        } else {
            if (b38 != 0)
                moved = FUN_00098190(dt, speed, f7c, 0.0f, target, 0, &pos, &dir, fc4, f48, f4c, fr.u08.mode);
            else
                moved = FUN_00098190(dt, speed, f7c, 0.0f, target, 0, &pos, &dir, fc4, 0.0f, 0.0f, 1);
        }
        if (fr.ent != 0)
            fr.ent->f1d2c = moved;
        if (moved == 0) {
            if (target != 0)
                target->Release();
            target = 0;
        }

        // accelerate towards the cruise speed
        float cruise = f84;
        if (f88 <= 0.0f) {
            speed = cruise;
        } else {
            fr.u08.accel = f88 * dt;
            float diff = speed - cruise;
            if (diff < -fr.u08.accel)
                speed = fr.u08.accel + speed;
            else if (diff > fr.u08.accel)
                speed = speed - fr.u08.accel;
            else
                speed = cruise;
        }
        float s = speed;
        fr.v34 = dir;
        fr.v34.x = fr.v34.x * s;
        fr.v34.y = fr.v34.y * s;
        fr.v34.z = fr.v34.z * s;

        // fuel: once it runs out, gravity bends the flight
        if (f8c >= 0.0f) {
            float fuel = f8c - dt * speed;
            f8c = fuel;
            if (fuel < 0.0f) {
                float g = dt * 0.01f;
                f8c = 0.0f;
                fr.v40 = (*(Gravity_19e910**)&DAT_00554c10)->g;
                fr.v34.FUN_00011160(g, &fr.v40);
                dir.z = fr.v34.z;
                dir.x = fr.v34.x;
                dir.y = fr.v34.y;
                speed = dir.FUN_0022d110();
            }
        }
        pos.x = fr.v34.x * dt + pos.x;
        pos.y = fr.v34.y * dt + pos.y;
        pos.z = fr.v34.z * dt + pos.z;
        f94 = dt * f90 + f94;
    }

    // trail effect
    if (fr.owner != 0 && fr.owner->f114 == 0 && f9c >= 2 && fa0 == 0) {
        unsigned int lo = cfg->id128Lo;
        unsigned int hi = cfg->id128Hi;
        if ((lo | hi) != 0) {
            int fx = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70()->FUN_00022960(lo, hi);
            unsigned int *key = fr.owner->FUN_001d68d0()->f8->key;
            unsigned int klo = key[0];
            unsigned int khi = key[1];
            FUN_00011520(fr.u1a8.names, 8, 2, &FUN_0027af00);
            fr.u1a8.names[0].FUN_0027af60(klo, khi);
            fr.u1a8.names[1].FUN_0027af60(klo, khi);
            Cfg_19e910 *c = cfg;
            c->FUN_00193660(&fr.v40);
            fr.u04.f = c->f114 * 0.5f;
            FUN_00011520(fr.pts, 0xc, 2, &FUN_00011090);
            float y = fr.v40.y;
            float z = fr.v40.z;
            fr.pts[0].x = -fr.u04.f + fr.v40.x;
            fr.pts[0].y = y;
            fr.pts[0].z = z;
            fr.pts[1].x = fr.u04.f + fr.v40.x;
            fr.pts[1].y = y;
            fr.pts[1].z = z;
            Trails_19e910 *trails = FUN_0027f250();
            c = cfg;
            fr.u24.i = c->f144;
            fr.u04.i = c->f140;
            fr.u08.i = c->f124;
            fr.u20.i = c->f13c;
            fr.u0c.f = c->fb0;
            fa0 = trails->FUN_00283d60(fr.u0c.f, fr.u08.i, fr.owner->FUN_001d68d0(), fx, fr.u1a8.names, fr.pts, 2,
                                       fr.u1a8.names, *c->FUN_001936f0(&fr.buf), fr.u20.i, fr.u04.i, fr.u24.i);
            FUN_00013420(fr.u1a8.names, 8, 2, &FUN_0027af50);
        }
    }
    if (fr.owner == 0 || fr.owner->f114 != 0) {
        if (fa0 != 0) {
            Trails_19e910 *trails = FUN_0027f250();
            trails->FUN_002834e0(fa0);
            fa0 = 0;
        }
        f9c = 0;
    }
    if (f9c >= 1)
        f9c = 2;

    // collision sweep from the previous position
    World *w = DAT_004dd700;
    fr.hitThing = 0;
    fr.hitInfo = 0;
    fr.u7c.w24 = w->f24;
    fr.u20.w = w;
    fr.u24.cw = w->f10->f8;
    fr.u0c.hitObj = 0;
    fr.hit = false;
    if (fr.owner == 0 || fr.owner->f114 == 0) {
        fr.hit = fr.u7c.w24->FUN_00201e00(&prev, &pos, 1, &fr.hitPos, &fr.hitNormal, &fr.hitThing, &fr.hitInfo);
        fr.u04.f = 3.40282347e+38f;
        if (fr.hit) {
            fr.v58 = fr.hitPos;
            float dz = fr.v58.z - prev.z;
            float dy = fr.v58.y - prev.y;
            float dx = fr.v58.x - prev.x;
            fr.u04.f = (float)sqrt((dz * dz + dy * dy) + dx * dx);
            if (fr.hitInfo != 0 && fr.hitInfo->f38 == 5)
                fr.u0c.hitObj = fr.hitInfo->f3c->FUN_001d72e0();
        }
        Pool_19e910 *pool = FUN_00202f00();
        DAT_004d2a3c = 2;
        (*(char*)&DAT_004d2a40) = 0;
        (*(char*)&DAT_00554c1c) = 1;
        DAT_00554c18 = 0;
        if (fr.ent != 0) {
            fr.ent->FUN_000368d0(0);
            fr.ent->FUN_00035fa0(0);
        }
        if (fr.u24.cw->FUN_002ee140(pool, &prev, &pos, 0)) {
            Hit_19e910 *src = pool->f8;
            fr.u70.h.t = src->t;
            CollItem_19e910 *item = src->obj;
            fr.u70.h.shape = src->shape;
            if (fr.u70.h.t > 0.0f && fr.u70.h.t < fr.u04.f) {
                Coll_19e910 *what = item->f18;
                float px = pos.x;
                float py = pos.y;
                fr.hitPos.z = pos.z;
                fr.hitPos.x = px - prev.x;
                fr.hitPos.y = py - prev.y;
                fr.hitPos.z = fr.hitPos.z - prev.z;
                fr.hitPos.FUN_0022d110();
                float t = fr.u70.h.t;
                float hx = t * fr.hitPos.x;
                float hy = t * fr.hitPos.y;
                *(volatile float *)&fr.hitPos.z = t * fr.hitPos.z;
                fr.u04.f = 0.0f;
                fr.hitPos.x = hx + prev.x;
                fr.hitPos.y = hy + prev.y;
                fr.hitPos.z = *(volatile float *)&fr.hitPos.z + prev.z;
                FUN_002f1ce0(&prev, fr.u70.h.shape, &fr.hitNormal, &fr.u04.f);
                fr.u0c.hitObj = what;
                fr.hit = true;
            }
        }
        if (fr.ent != 0) {
            fr.ent->FUN_00035fa0(1);
            fr.ent->FUN_000368d0(1);
        }
    }
    prev.x = pos.x;
    prev.y = pos.y;
    prev.z = pos.z;

    // what did we hit?
    // The handling below is a single pass: `break` means "nothing more to do for this hit".
    Coll_19e910 *ho = fr.u0c.hitObj;
    while (ho != 0) {
        Node_19e910 *node = 0;
        Actor_19e910 *actor = 0;
        int type = ho->type;
        if (type == 1) {
            actor = (Actor_19e910 *)ho->f8;
            fr.u08.actor = actor;
        } else if (type == 5) {
            node = (Node_19e910 *)ho->f8;
            if (node == 0)
                break;
            actor = node->f148;
            fr.u08.actor = actor;
            if (actor == 0) {
                Holder_19e910 *hold = node->f114;
                if (hold != 0 && hold->fc == 1) {
                    if (node->fec->FUN_001d5e80(node->f40) == 2) {
                        actor = node->f114->f8;
                        fr.u08.actor = actor;
                    }
                }
            }
        } else if (type == 7) {
            Node_19e910 *n = (Node_19e910 *)ho->f8;
            if (n == 0)
                break;
            if (n->f10 == 5) {
                fr.hit = false;
                break;
            }
            if (fr.hit) {
                fr.evt.FUN_00059820();
                fr.evt.pos = fr.hitPos;
                fr.evt.normal = fr.hitNormal;
                fr.u04.f = speed;
                fr.evt.vel = dir;
                fr.evt.vel.x = fr.evt.vel.x * fr.u04.f;
                fr.evt.vel.y = fr.evt.vel.y * fr.u04.f;
                fr.evt.vel.z = fr.evt.vel.z * fr.u04.f;
                fr.evt.f78 = cfg->fd4;
                fr.evt.force = dir;
                float k = cfg->fd8;
                fr.evt.b14 = 1;
                fr.evt.force.x = fr.evt.force.x * k;
                fr.evt.force.y = fr.evt.force.y * k;
                fr.evt.force.z = fr.evt.force.z * k;
                n->FUN_00081420(&fr.evt);
                fr.evt.FUN_00059300();
            }
            break;
        }

        if (actor != 0) {
            // hit an actor
            Fx_19e910 *fx = DAT_004dd700->f44->FUN_00059ba0(f44);
            if (fx != 0)
                fx->FUN_00059a30();
            Team_19e910 *team = actor->f11c;
            if (actor->f10->id == f44) {
                fr.hit = false;
                break;
            }
            bool canDeflect = actor->FUN_0003b4f0(&dir) && team != 0 && (team->f14 == 1 || team->f14 == 2 || team->f14 == 3);
            if (canDeflect && fr.u08.actor == DAT_004dd700->f20->f124) {
                // the player's deflect needs the unlockable move (or the cheat)
                canDeflect = false;
                UnlockTable_19e910 *tab = DAT_004dd6ec->FUN_00086340();
                void *u = tab->FUN_00092ad0(0x2b9);
                if (u != 0) {
                    Unlock_19e910 *move = FUN_00344e74(u, 0, &DAT_0049dab8, &DAT_0049db1c, 0);
                    if (move != 0) {
                        Unlock_19e910 *cheat = FUN_00344e74(tab->FUN_00092ad0(0x1d), 0, &DAT_0049dab8, &DAT_0049dafc, 0);
                        canDeflect = (cheat != 0 && cheat->b8 == 0 && cheat->b20 != 0) ||
                                     (move->b8 == 0 && move->FUN_00091f40());
                    }
                }
            }
            if (canDeflect) {
                // deflected: the missile now belongs to the actor
                actor = fr.u08.actor;
                f44 = actor->f10->id;
                fr.hit = false;
                if (DAT_004dd700->f2c->FUN_001ccff0()) {
                    fr.u1a8.un.FUN_001cae40("unlockable_move_84");
                    DAT_004dd700->f30->FUN_001cbc20(&fr.u1a8.un);
                }
                fr.u50.mgr = actor->f1b60;
                if (fr.u50.mgr != 0) {
                    fr.evt.FUN_00059820();
                    fr.evt.pos = fr.hitPos;
                    fr.evt.normal = fr.hitNormal;
                    fr.u04.f = speed;
                    fr.evt.vel = dir;
                    fr.evt.vel.x = fr.evt.vel.x * fr.u04.f;
                    fr.evt.vel.y = fr.evt.vel.y * fr.u04.f;
                    fr.evt.vel.z = fr.evt.vel.z * fr.u04.f;
                    fr.evt.force = dir;
                    float k = cfg->fd8;
                    fr.evt.force.x = fr.evt.force.x * k;
                    fr.evt.force.y = fr.evt.force.y * k;
                    fr.evt.force.z = fr.evt.force.z * k;
                    if (fr.ent != 0)
                        FUN_00018810(&fr.evt.f4c, fr.ent->f12c);
                    if (fr.owner != 0)
                        FUN_00018810(&fr.evt.f50, fr.owner->FUN_001d72e0());
                    fr.evt.b14 = 1;
                    CFightParamsCollision_19e910 *job = (CFightParamsCollision_19e910 *)FUN_0008d690(0xb0);
                    job = job != 0 ? job->FUN_000598e0(actor->f10->id, &fr.evt) : 0;
                    job->AddRef();
                    fr.u04.sink = fr.u50.mgr->v8(job, 0);
                    if (fr.u04.sink != 0 && !actor->fdc.FUN_00231e80(fr.u04.sink))
                        fr.u04.sink->FUN_00231ad0(&actor->fdc, job, -1);
                    job->Release();
                    fr.evt.FUN_00059300();
                }
                RefObj_19e910 *tgt = actor->f328;
                if (tgt == 0) {
                    fr.v40.x = 0.0f;
                    fr.v40.y = 0.0f;
                    fr.v40.z = -1.0f;
                    actor->FUN_00035550(&fr.v40);
                    Cfg_19e910 *c = cfg;
                    fr.u50.f = c->f6c;
                    fr.u04.f = c->f68;
                    tgt = actor->FUN_00039c60(&pos, &fr.v40, fr.u04.f, fr.u50.f, 0, 0, 0);
                }
                FUN_00196640(tgt);
                if (tgt != 0 && FUN_00096b50(tgt, &fr.vcc, &fr.u50.f)) {
                    dir.FUN_00011110(&fr.vcc, &pos);
                    dir.FUN_0022d110();
                } else {
                    dir.x = dir.x * -1.0f;
                    dir.y = dir.y * -1.0f;
                    dir.z = dir.z * -1.0f;
                }
                life = cfg->fb0;
                Sounds_19e910 *snds = fr.u20.w->f20;
                const char *sfx = snds->FUN_00025890(8);
                if (sfx != 0 && *sfx != 0) {
                    fr.u50.snd = fr.u20.w->f3c->f4;
                    fr.u50.snd->FUN_000d4620(1, sfx, -1, *snds->FUN_00025930(&fr.u04.i, 0), -1.0f);
                }
            }
            if (fr.owner != 0) {
                if (!fr.hit)
                    break;
                Rider_19e910 *rider = fr.u08.actor->f1b64;
                if (rider != 0) {
                    float s = speed;
                    fr.v28 = dir;
                    fr.v28.x = fr.v28.x * s;
                    fr.v28.y = fr.v28.y * s;
                    fr.v28.z = fr.v28.z * s;
                    if (rider->FUN_0001e870(fr.owner, &fr.v28)) {
                        f44 = fr.u08.actor->f10->id;
                        life = cfg->fb0;
                        fr.hit = false;
                        break;
                    }
                }
            }
            if (!fr.hit)
                break;
            fr.evt.FUN_00059820();
            fr.evt.pos = fr.hitPos;
            fr.evt.normal = fr.hitNormal;
            fr.u04.f = speed;
            fr.evt.vel = dir;
            fr.evt.vel.x = fr.evt.vel.x * fr.u04.f;
            fr.evt.vel.y = fr.evt.vel.y * fr.u04.f;
            fr.evt.vel.z = fr.evt.vel.z * fr.u04.f;
            fr.evt.f78 = cfg->fd4;
            fr.evt.force = dir;
            fr.evt.f80 = 1.0f;
            {
                float k = cfg->fd8;
                fr.evt.force.x = fr.evt.force.x * k;
                fr.evt.force.y = fr.evt.force.y * k;
                fr.evt.force.z = fr.evt.force.z * k;
            }
            if (fr.ent != 0)
                FUN_00018810(&fr.evt.f4c, fr.ent->f12c);
            FUN_00018810(&fr.evt.f50, fr.u08.actor->f12c);
            fr.evt.b14 = 1;
            if (fr.ent != 0) {
                Queue_19e910 *q = cfg->fc8;
                if (q != 0) {
                    CFightParamsCollision_19e910 *job = (CFightParamsCollision_19e910 *)FUN_0008d690(0xb0);
                    job = job != 0 ? job->FUN_000598e0(f44, &fr.evt) : 0;
                    job->AddRef();
                    Sink_19e910 *sink = q->v8(job, 0);
                    if (sink != 0 && !fr.ent->fdc.FUN_00231e80(sink))
                        sink->FUN_00231ad0(&fr.ent->fdc, job, -1);
                    job->Release();
                }
            }
            actor = fr.u08.actor;
            if (actor->FUN_000360f0()) {
                actor->FUN_00043350(fr.evt.f78, fr.evt.f4c, fr.evt.f48, 1.0f, 0, 0);
                fr.evt.FUN_00059300();
                break;
            }
            Queue_19e910 *q = cfg->fbc;
            if (q != 0) {
                CFightParamsCollision_19e910 *job = (CFightParamsCollision_19e910 *)FUN_0008d690(0xb0);
                job = job != 0 ? job->FUN_000598e0(actor->f10->id, &fr.evt) : 0;
                job->AddRef();
                Sink_19e910 *sink = q->v8(job, 0);
                if (sink != 0)
                    sink->FUN_00231ad0(&actor->fdc, job, -1);
                job->Release();
                fr.evt.FUN_00059300();
                break;
            }
            Coll_19e910 *by = 0;
            if (fr.owner != 0)
                by = fr.owner->FUN_001d72e0();
            Cfg_19e910 *c = cfg;
            actor->FUN_00043ae0(by, &fr.hitPos, c->fd8, c->fb8, c->fd4, 0, 0, 0, 0);
            fr.evt.FUN_00059300();
            break;
        }

        if (node != 0) {
            // hit a character
            Actor_19e910 *src = fr.ent;
            if (src != 0) {
                if (node == src->f128) {
                    fr.hit = false;
                } else {
                    for (int n = 0; n < 8; n++) {
                        if (node == src->FUN_00035ef0(n)) {
                            fr.hit = false;
                            break;
                        }
                    }
                    src = fr.ent;
                }
            }
            if (node->FUN_001d6980()) {
                fr.hit = false;
                break;
            }
            if (!fr.hit)
                break;
            fr.u08.amount = cfg->fd4;
            if (src != 0) {
                int side = src->f11c->f1b0;
                if (node->f198 == side)
                    fr.u08.amount = fr.u08.amount * node->f19c;
                if (side == 2)
                    fr.u08.amount = DAT_004dd700->f0c->FUN_001dddf0() * fr.u08.amount;
            }
            if (fr.u08.amount > 0.0f)
                node->FUN_001d6ec0((int)fr.u08.amount, src != 0 ? src->f12c : 0, 0);
            if (node->FUN_001d7300() && node->f114 == 0 && fr.u0c.hitObj->f70 != 0) {
                node->FUN_001d82d0();
                float k = cfg->fd8;
                if (k != 0.0f) {
                    fr.v28 = dir;
                    fr.v28.x = fr.v28.x * k;
                    fr.v28.y = fr.v28.y * k;
                    fr.v28.z = k * fr.v28.z;
                    node->FUN_001d86d0(&fr.v28, &fr.hitPos);
                }
            }
        }
        break;
    }
    if (fr.owner == 0 || fr.owner->f114 == 0) {
        // orient the model along the flight direction
        fr.v40.x = 0.0f;
        fr.v40.y = 1.0f;
        fr.v40.z = 0.0f;
        bool vertical = dir.FUN_0022d2b0(&fr.v40, 1e-05f);
        fr.v40.z = 0.0f;
        if (vertical) {
            fr.v40.x = 1.0f;
            fr.v40.y = 0.0f;
        } else {
            fr.v40.x = 0.0f;
            fr.v40.y = 1.0f;
        }
        fr.vcc.FUN_000111b0(&dir, &fr.v40);
        fr.m.FUN_0022b980();
        fr.m.FUN_0022baf0(&fr.vcc, f94);
        fr.m.FUN_0022c3b0(&dir, &fr.v178);
        fr.u1a8.m2.FUN_0022b980();
        fr.v58 = cfg->v28;
        fr.v58.FUN_0022d110();
        if (!fr.v178.FUN_0022d2b0(&fr.v58, 1e-05f))
            FUN_00224db0(&fr.u1a8.m2, &fr.v58, &fr.v178);
        fr.u1a8.m2.trans.x = pos.x;
        fr.u1a8.m2.trans.y = pos.y;
        fr.u1a8.m2.trans.z = pos.z;
        fr.u54.factory->FUN_001dd470(h40, &fr.u1a8.m2, dt);
    }

    if (pos.y < fr.u7c.w24->floorY)
        life = 0.0f;
    if (life <= 0.0f) {
        fr.hitPos = pos;
        fr.hitNormal = dir;
    }
    if (fr.hit || life <= 0.0f) {
        // explode
        Node_19e910 *o = fr.owner;
        if (o != 0) {
            Holder_19e910 *hold = o->f114;
            if (hold != 0 && hold->fc == 1) {
                Actor_19e910 *holder = hold->f8;
                if (holder != 0) {
                    for (int n = 0; n < 8; n++) {
                        if (holder->FUN_00035ef0(n) == o) {
                            holder->FUN_0003aef0(n);
                            break;
                        }
                    }
                }
            }
        }
        Cfg_19e910 *c = cfg;
        unsigned int lo = c->id20Lo;
        unsigned int hi = c->id20Hi;
        if ((lo | hi) != 0)
            fr.u54.factory->FUN_001e2ed0(h40, lo, hi);
        if (o != 0) {
            const char *fxName = cfg->fdc;
            if (fxName != 0 && *fxName != 0)
                fr.u20.w->f34->FUN_001ebd80(o, fxName, 100.0f, 0);
        }
        fr.m.FUN_0022b980();
        fr.vdir = cfg->vf0;
        fr.v40.x = 0.0f;
        fr.v40.y = 0.0f;
        fr.v40.z = 0.0f;
        if (fr.vdir.FUN_0022d2b0(&fr.v40, 1e-05f)) {
            fr.vdir.x = FUN_000964e0() + 0.001f;
            fr.vdir.y = FUN_000964e0() + 0.001f;
            fr.vdir.z = FUN_000964e0() + 0.001f;
        }
        fr.vdir.FUN_0022d110();
        if (!fr.vdir.FUN_0022d2b0(&fr.hitNormal, 1e-05f))
            FUN_00224db0(&fr.m, &fr.vdir, &fr.hitNormal);
        fr.m.trans.x = fr.hitPos.x;
        fr.m.trans.y = fr.hitPos.y;
        fr.m.trans.z = fr.hitPos.z;
        Trails_19e910 *trails = FUN_0027f250();
        trails->FUN_00283a40(cfg->fe8, &fr.m, -1.0f, 1.0f);
        void *thing = fr.hitThing;
        life = 0.0f;
        if (thing != 0) {
            int decals = cfg->fe0;
            if (decals > 0) {
                fr.u54.decal = 0;
                fr.u20.w->f38->FUN_001f6cd0(thing, fr.hitInfo, &fr.hitPos, &fr.hitNormal, &dir, decals - 1, 1.0f, 1.0f, &fr.u54.decal, 0);
                if (o != 0)
                    fr.u20.w->f34->FUN_001ebea0(fr.u54.decal, o);
            }
        }

        // area damage
        fr.u08.rad = cfg->ffc;
        fr.u7c.rad2 = fr.u08.rad * fr.u08.rad;
        fr.u24.list = fr.u24.cw->FUN_002ed700();
        for (unsigned int i = 0; i < (unsigned int)(fr.u24.list->end - fr.u24.list->begin); i++) {
            Coll_19e910 *e = fr.u24.list->begin[i]->f18;
            if (e == 0 || e == fr.u0c.hitObj)
                continue;
            if (e->type == 1) {
                Actor_19e910 *a = (Actor_19e910 *)e->f8;
                if (a == 0 || a->f334 != 0)
                    continue;
                if (a->f128 != 0 && fr.u0c.hitObj == a->f128->FUN_001d72e0())
                    continue;
                if (a == fr.ent)
                    continue;
                Team_19e910 *team = a->f11c;
                if (team != 0) {
                    if (team->f14 == 4 || team->f14 == 5)
                        continue;
                    if (fr.ent != 0 && fr.ent->f11c->b384 != 0 && fr.ent->f11c->f1b0 == team->f1b0)
                        continue;
                }
                fr.tp1.x = 0.0f;
                fr.tp1.y = 0.0f;
                fr.tp1.z = 0.0f;
                a->FUN_000350c0(&fr.tp1);
                fr.v28.x = fr.tp1.x - fr.hitPos.x;
                fr.v28.y = fr.tp1.y - fr.hitPos.y;
                fr.v28.z = fr.tp1.z - fr.hitPos.z;
                if (!(fr.v28.FUN_0022d110() <= fr.u08.rad))
                    continue;
                if (FUN_002027c0(&fr.hitPos, &fr.tp1, 0, 1, &fr.u1a8.out, &fr.pts[0], 0, 0))
                    continue;
                fr.v58 = fr.tp1;
                if (team != 0)
                    fr.v58.FUN_00011160(-team->f34, &fr.v28);
                if (a->FUN_000360f0()) {
                    a->FUN_00043350(cfg->f10c, fr.ent != 0 ? fr.ent->f12c : 0, 0, 1.0f, 0, 0);
                    continue;
                }
                Queue_19e910 *q = cfg->f100;
                if (q != 0) {
                    fr.evt.FUN_00059820();
                    fr.evt.pos = fr.v58;
                    fr.evt.normal = fr.v28;
                    fr.evt.vel = fr.v28;
                    fr.evt.f78 = cfg->f10c;
                    fr.evt.b90 = 1;
                    fr.evt.f80 = 1.0f;
                    if (fr.ent != 0)
                        FUN_00018810(&fr.evt.f4c, fr.ent->f12c);
                    FUN_00018810(&fr.evt.f50, a->f12c);
                    fr.evt.b14 = 1;
                    CFightParamsCollision_19e910 *job = (CFightParamsCollision_19e910 *)FUN_0008d690(0xb0);
                    job = job != 0 ? job->FUN_000598e0(a->f10->id, &fr.evt) : 0;
                    job->AddRef();
                    Sink_19e910 *sink = q->v8(job, 0);
                    if (sink != 0)
                        sink->FUN_00231ad0(&a->fdc, job, -1);
                    job->Release();
                    fr.evt.FUN_00059300();
                } else {
                    Cfg_19e910 *cc = cfg;
                    a->FUN_00043ae0(0, &fr.v58, cc->f110, cc->fb8, cc->f10c, 0, 0, 0, 0);
                }
            } else if (e->type == 5) {
                Node_19e910 *n = (Node_19e910 *)e->f8;
                if (n == 0 || n->FUN_000134e0() || n->ffc == 1 || n->FUN_001d6980() || n->f148 != 0)
                    continue;
                fr.tp5 = e->v40;
                if (e->f70 != 0)
                    e->f70->FUN_0016fc60(&fr.tp5);
                fr.v178.x = fr.u50.dx = fr.tp5.x - fr.hitPos.x;
                fr.v178.y = fr.u54.dy = fr.tp5.y - fr.hitPos.y;
                fr.v178.z = fr.u04.dz = fr.tp5.z - fr.hitPos.z;
                if (fr.v178.FUN_000111f0() > fr.u7c.rad2 * 4.0f)
                    continue;
                fr.v34.x = 0.0f;
                fr.v34.y = 0.0f;
                fr.v34.z = 0.0f;
                fr.u20.t = 0.0f;
                fr.hitP2.x = 0.0f;
                fr.hitP2.y = 0.0f;
                fr.hitP2.z = 0.0f;
                void *shape = fr.u24.list->begin[i]->f20;
                if (shape != 0) {
                    FUN_002f1ce0(&fr.hitPos, shape, &fr.v34, &fr.u20.t);
                    if (!(fr.u20.t <= fr.u08.rad))
                        continue;
                    fr.v34.x = fr.v34.x * -1.0f;
                    fr.vcc.x = 0.0f;
                    fr.vcc.y = 0.0f;
                    fr.vcc.z = 0.0f;
                    fr.v34.y = fr.v34.y * -1.0f;
                    fr.v34.z = fr.v34.z * -1.0f;
                    if (fr.v34.FUN_0022d2b0(&fr.vcc, 1e-05f)) {
                        fr.v34.x = 0.0f;
                        fr.v34.y = 1.0f;
                        fr.v34.z = 0.0f;
                    }
                    Vec3 *off = FUN_00083e00(&fr.tmp2cc, &fr.v34, fr.u20.t);
                    float hx = fr.hitPos.x + off->x;
                    float hy = fr.hitPos.y + off->y;
                    fr.tmp1e8.z = fr.hitPos.z + off->z;
                    fr.hitP2.z = fr.tmp1e8.z;
                    fr.hitP2.x = hx;
                    fr.hitP2.y = hy;
                } else {
                    fr.u1a8.out.z = fr.u04.dz;
                    fr.v34.x = -fr.u50.dx;
                    fr.v34.y = -fr.u54.dy;
                    fr.v34.z = -fr.u1a8.out.z;
                    fr.u20.t = fr.v34.FUN_0022d110();
                    fr.hitP2 = fr.tp5;
                    if (!(fr.u20.t <= fr.u08.rad))
                        continue;
                }
                if (cfg->f10c > 0.0f)
                    n->FUN_001d6ec0((int)cfg->f10c, fr.ent != 0 ? fr.ent->f12c : 0, 0);
                if (n->FUN_001d7300() && n->f114 == 0 && e->f70 != 0) {
                    n->FUN_001d82d0();
                    float k = cfg->f110;
                    if (k > 0.0f) {
                        fr.vs = fr.v34;
                        fr.vs.x = fr.vs.x * k;
                        fr.vs.y = fr.vs.y * k;
                        fr.vs.z = fr.vs.z * k;
                        n->FUN_001d86d0(&fr.vs, &fr.hitP2);
                    }
                }
            } else if (e->type == 7) {
                Node_19e910 *n = (Node_19e910 *)e->f8;
                if (n == 0 || n->f10 == 5 || fr.u0c.hitObj == n->f100)
                    continue;
                fr.u70.p = n->v64;
                fr.d7.x = fr.u70.p.x - fr.hitPos.x;
                fr.d7.y = fr.u70.p.y - fr.hitPos.y;
                fr.d7.z = fr.u70.p.z - fr.hitPos.z;
                if (fr.d7.FUN_0022d110() <= fr.u08.rad) {
                    fr.v40 = fr.u70.p;
                    fr.evt2.FUN_00059820();
                    fr.evt2.pos = fr.v40;
                    fr.evt2.normal = fr.d7;
                    fr.evt2.vel = fr.d7;
                    fr.evt2.f78 = 1.0f;
                    fr.evt2.b14 = 1;
                    n->FUN_00081420(&fr.evt2);
                    fr.evt2.FUN_00059300();
                }
            }
        }
    }
    FUN_00266da0(fr.tag);
}
