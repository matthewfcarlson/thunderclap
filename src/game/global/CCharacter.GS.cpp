// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000382c0..0x00044910 (kind game, layer game, confidence medium), dominant class CCharacter
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f21e3c3e {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f21e3c3e {} using namespace fn_f21e3c3e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f21e3c3e {
struct Vec3_382c0 {
    float x, y, z;
};
struct Bias {
    float p0;
    float p4;
    float p8;
};
struct Limits_382c0 {
    char pad0[0x18];
    float minY;
};
} // namespace fn_f21e3c3e
struct World {
    char pad0[0x24];
    Limits_382c0 *limits;
};
namespace fn_f21e3c3e {
struct Anchor_382c0 {
    // equiv-conv: FUN_00059a50 ecx stack
    bool FUN_00059a50(Vec3_382c0 *out);
};
class Camera {
public:
    char pad0[8];
    int f8;
    int fc;
    Anchor_382c0 *anchor;
    char pad14[0x12c];
    int mode;

    bool FUN_000352b0(Vec3_382c0 *out);
    bool FUN_00035550(Vec3_382c0 *out);
    bool FUN_000382c0(Vec3_382c0 *out);
};
extern "C" int FUN_00267760(char *buf, int size, const char *fmt, ...);
class Src_3f650 {
public:
    char pad0[0x168 - 0x0];
    int s12;
    int s13;
    char pad3[0x37d - 0x170];
    char s11;
    char pad5[0x438 - 0x37e];
    int s0;
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int s17;
    char s18;
    char pad14[0x458 - 0x455];
    int s6;
    int s7;
    int s8;
    int s9;
    int s10;
    char pad20[0x470 - 0x46c];
    int s14;
    char s15;
    char s16;
    float FUN_00045f90(char *name);
};
class Entity {
public:
    char pad0[0x11c - 0x0];
    Src_3f650 * src;
    char pad2[0x394 - 0x120];
    int d13;
    char pad4[0x1cf8 - 0x398];
    int d0;
    int d2;
    int d1;
    char pad8[0x1d08 - 0x1d04];
    int d17;
    char pad10[0x1d14 - 0x1d0c];
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    char pad16[0x1d30 - 0x1d28];
    int d8;
    int d9;
    int d10;
    char pad20[0x1d40 - 0x1d3c];
    char d11;
    char pad22[0x1d48 - 0x1d41];
    int d14;
    char d15;
    char d16;
    char pad26[0x1f50 - 0x1d4e];
    char d18;
    char pad28[0x213c - 0x1f51];
    int d12;
    void FUN_0003ed40(char *name, float value);
    void FUN_0003f650();
};


// 0x000382c0 FUN_000382c0 (318 B): equivalent/0x000382c0.cpp
// sym: ?FUN_000382c0@Camera@fn_f21e3c3e@@QAE_NPAUVec3_382c0@2@@Z @0a7c1fafe546 @w2e92b2428bc0
// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 16/16)
// FUN_000382c0 @ 0x000382c0
    // equiv-conv: FUN_00059a50 ecx stack
bool Camera::FUN_000382c0(Vec3_382c0 *out)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    Vec3_382c0 pos;
    Vec3_382c0 off;

    if (!anchor->FUN_00059a50(&pos)) {
        return false;
    }
    if (f8 != (*(int*)&DAT_004dc0e0) || fc != (*(int*)((char*)&DAT_004dc0e0 + 4))) {
        if (!FUN_000352b0(out))
            *out = pos;
        return true;
    }
    *out = pos;
    Bias *b = 0;
    switch (mode) {
    case 1:
    case 2:
        b = ((Bias*)&DAT_0048f5d4);
        break;
    case 3:
        FUN_000352b0(out);
        break;
    case 4:
        b = ((Bias*)&DAT_0048f5e0);
        break;
    }
    if (b != 0) {
        FUN_00035550(&off);
        out->x = off.x * b->p8 + out->x;
        out->z = off.z * b->p8 + out->z;
        out->y = off.y * b->p8 + out->y + b->p4;
    }
    float limit = DAT_004dd700->limits->minY;
    if (limit > out->y)
        out->y = limit;
    return true;
}

} // namespace fn_f21e3c3e

// 0x0003b1c0 FUN_0003b1c0 (355 B): equivalent/0x0003b1c0.cpp [wrapped: conflict: World]
// sym: ?FUN_0003b1c0@Timer@fn_0003b1c0@@QAE_NM_N@Z @01b81550a43b @w0c40b05b49d9
namespace fn_0003b1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 30/30)
// FUN_0003b1c0 @ 0x0003b1c0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


struct Msg_3b1c0 {
    char data[0xb0];
};

struct Dispatcher_3b1c0 {
    void FUN_001cbc20(Msg_3b1c0 *m);
};

struct World {
    char pad0[0x30];
    Dispatcher_3b1c0 *dispatcher;
};


struct Source_3b1c0 {
    int id;
};

struct Info_3b1c0 {
    char pad0[0x134];
    float limit;
};

class Timer {
public:
    char pad0[0x10];
    Source_3b1c0 *source;
    char pad14[0x11c - 0x14];
    Info_3b1c0 *info;
    char pad120[0x1b0c - 0x120];
    float value;
    float maxValue;
    char pad1b14[4];
    float trigger;
    int count;
    char pad1b20[8];
    int mode;
    bool FUN_0003b1c0(float dt, bool force);
};

bool Timer::FUN_0003b1c0(float dt, bool force)
{
    Msg_3b1c0 msg;

    if (!force) {
        if (trigger > 0.0f || count > 0) {
            if (dt < value) {
                return false;
            }
        }
    }

    bool wasZero = (value <= 0.0f);
    World *sys = DAT_004dd700;
    value = dt;
    if (dt < 0.0f)
        value = 0.0f;

    Info_3b1c0 *inf = info;
    if (inf) {
        if (maxValue < value)
            value = maxValue;
        if (!force) {
            float lim = inf->limit;
            if (lim > value && mode != 2)
                value = lim;
        }
        if (value <= 0.0f && !wasZero) {
            Dispatcher_3b1c0 *d = sys->dispatcher;
            if (d) {
                ((Msg_3b1c0 *)((owners::C_1c9a40 *)&msg)->FUN_001c9a40((unsigned)(source->id)));
                d->FUN_001cbc20(&msg);
            }
        }
    }
    return true;
}
} // namespace fn_0003b1c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0003c1d0 FUN_0003c1d0 (4074 B): equivalent/0x0003c1d0.cpp [wrapped: conflict: DAT_004e2198; DAT_004e219c]
// sym: ?FUN_0003c1d0@Character_3c1d0@fn_0003c1d0@@QAEXHM@Z @d2650de39232 @w80d30ab4bc9f
namespace fn_0003c1d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3284 inputs, branch coverage 206/224, incomplete)
// FUN_0003c1d0 @ 0x0003c1d0
// cl-flags: /GS

struct V3_3c1d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_3c1d0 *other, float eps);
    hulk_freg FUN_00018990();
};

struct V4_3c1d0 : V3_3c1d0 {
    float w;
};

struct Mtx {
    float m[16];
};

struct Kin {
    char pad[4];
    hulk_freg FUN_002220d0();
    Mtx *FUN_00221c40();
    V4_3c1d0 *FUN_00221cd0();
};

struct Body_3c1d0 {
    char pad00[0x10];
    Kin kin;
    void FUN_002226e0(Kin *k);
    void FUN_002226f0(V3_3c1d0 *p);
    void FUN_00222720(V4_3c1d0 *q);
};

struct Part_3c1d0 {
    Body_3c1d0 *FUN_00059a40();
    bool FUN_00059a50(V3_3c1d0 *out);
};

struct Info_3c1d0 {
    char pad00[0x6c];
    int f6c;
};

struct Mgr_3c1d0 {
};

struct Hook_3c1d0 {
    virtual void v0();
    virtual void v1();
};

struct Ctl_3c1d0 {
    char pad00[0x14];
    int mode;               // 0x14
    char pad18[0x30 - 0x18];
    float f30;
    float f34;
    bool FUN_000456e0();
};

struct Owner_3c1d0 {
    char pad00[0x11c];
    Ctl_3c1d0 *f11c;
};

struct Pair_3c1d0 {
    char pad00[8];
    int f8;
    int fc;
};

struct Obj_3c1d0 {
    char pad00[8];
    Owner_3c1d0 *f8;
    int type;               // 0xc
    char pad10[0x50 - 0x10];
    V3_3c1d0 v50;
    char pad5c[0x74 - 0x5c];
    Pair_3c1d0 *f74;
};

struct Plane_3c1d0 {
    int id;
    Obj_3c1d0 *obj;
    int f8;
    V3_3c1d0 pos;                 // 0xc
    V3_3c1d0 n;                   // 0x18
    float d;                // 0x24
};

extern int DAT_004e2198;
extern int DAT_004e219c;

bool __cdecl FUN_00018960(unsigned int a, unsigned int b, float c);
void __cdecl FUN_00018810(Hook_3c1d0 **slot, Obj_3c1d0 *o);
bool __cdecl FUN_00044510(Obj_3c1d0 *o, int k);
void __cdecl FUN_00224d70(unsigned int angle, V3_3c1d0 *v);

union W_3c1d0 {
    Obj_3c1d0 *o;
    float f;
    int i;
    unsigned int u;
};

struct Frame_3c1d0 {
    W_3c1d0 t10;                  // 0x10
    char pad14[2];
    char f16;
    char f17;
    V3_3c1d0 disp;                // 0x18
    int k;                  // 0x24
    V3_3c1d0 u;                   // 0x28
    V3_3c1d0 w;                   // 0x34
    V3_3c1d0 cur;                 // 0x40
    V3_3c1d0 m;                   // 0x4c
    W_3c1d0 thr;                  // 0x58
    W_3c1d0 n;                    // 0x5c
    W_3c1d0 t60;                  // 0x60
    V3_3c1d0 s;                   // 0x64
    float half;             // 0x70
    W_3c1d0 ang;                  // 0x74
    int mode;               // 0x78
    float rad;              // 0x7c
    V3_3c1d0 base;                // 0x80
    W_3c1d0 t8c;                  // 0x8c
    V4_3c1d0 n2;                  // 0x90
    V3_3c1d0 delta;               // 0xa0
    struct Kin *kin;        // 0xac
    float lim1;             // 0xb0
    float half308;          // 0xb4
    V3_3c1d0 q;                   // 0xb8
    V3_3c1d0 r2;                  // 0xc4
    V3_3c1d0 out;                 // 0xd0
    V3_3c1d0 G;                   // 0xdc
    float q1;               // 0xe8
    float f34raw;           // 0xec
    V3_3c1d0 P;                   // 0xf0
    V3_3c1d0 r3;                  // 0xfc
    float nd;               // 0x108
    float half220;          // 0x10c
    float s216;             // 0x110
    Body_3c1d0 *body;             // 0x114
    V3_3c1d0 up;                  // 0x118
    Mtx mtx;                // 0x124
    char flags[0x80];       // 0x164
};

class Character_3c1d0 {
public:
    char pad00[0x10];
    Part_3c1d0 *part;             // 0x10
    Kin kin14;              // 0x14
    char pad18[0x44 - 0x18];
    V3_3c1d0 f44;
    char pad50[0x11c - 0x50];
    Ctl_3c1d0 *f11c;
    char pad120[8];
    Mgr_3c1d0 *f128;
    int f12c;
    char pad130[0x140 - 0x130];
    int f140;
    unsigned int f144;
    float f148;
    char pad14c[0x328 - 0x14c];
    Obj_3c1d0 *f328;
    char pad32c[0x634 - 0x32c];
    int count;              // 0x634
    Plane_3c1d0 list[130];        // 0x638
    char pad1a88[0x1ab8 - 0x1a88];
    V3_3c1d0 hitPos;              // 0x1ab8
    V3_3c1d0 hitNrm;              // 0x1ac4
    Hook_3c1d0 *f1ad0;
    char pad1ad4[0x1aec - 0x1ad4];
    V3_3c1d0 vH;                  // 0x1aec
    V3_3c1d0 vG;                  // 0x1af8
    int f1b04;
    char pad1b08[0x1b20 - 0x1b08];
    int f1b20;
    int f1b24;
    char pad1b28[0x1d4d - 0x1b28];
    char f1d4d;

    void FUN_00038e80(int a, Obj_3c1d0 *o, int b, V3_3c1d0 *m, V3_3c1d0 *s, float thr);
    void FUN_0003c1d0(int unused, float dt);
};

void Character_3c1d0::FUN_0003c1d0(int unused, float dt)
{
    Frame_3c1d0 fr;
    Body_3c1d0 *body = part->FUN_00059a40();
    fr.body = body;
    if (f128 != 0) {
        Info_3c1d0 *info = ((Info_3c1d0 *)((owners::C_1d72e0 *)f128)->FUN_001d72e0());
        if (info != 0 && info->f6c == 1)
            body->FUN_002226e0((Kin *)((char *)info + 0x10));
    }
    fr.cur.x = 0;
    fr.cur.y = 0;
    fr.cur.z = 0;
    part->FUN_00059a50(&fr.cur);
    fr.base = f44;
    if (f1ad0 != 0) {
        f1ad0->v1();
        f1ad0 = 0;
    }
    fr.rad = f148;
    Ctl_3c1d0 *c = f11c;
    fr.mode = c->mode;
    fr.half220 = fr.rad * 0.5f;
    fr.half308 = fr.rad * 0.5f;
    fr.f34raw = c->f34;
    fr.half = c->f30 * 0.5f;
    f144 = 0;
    f1b04 = 0;
    if (!(f1b20 > 0)) {
        fr.disp.x = fr.cur.x - fr.base.x;
        fr.delta.x = fr.disp.x;
        fr.disp.y = fr.cur.y - fr.base.y;
        fr.delta.y = fr.disp.y;
        fr.disp.z = fr.cur.z - fr.base.z;
        fr.delta.z = fr.disp.z;
        fr.delta.FUN_0022d110();
        fr.kin = &kin14;
        fr.ang.f = kin14.FUN_002220d0();
        Body_3c1d0 *b2 = part->FUN_00059a40();
        // st(0): the angle (FUN_002220d0 returns atan2's unrounded st(0)) is subtracted before any store
        hulk_freg t = (b2 == 0) ? (hulk_freg)0.0f : (hulk_freg)b2->kin.FUN_002220d0();
        hitNrm.z = 0;
        hitNrm.y = 0;
        hitNrm.x = 0;
        fr.n.i = count;
        fr.ang.f = t - fr.ang.f;
        fr.f17 = 0;
        fr.lim1 = 1.0f;
        if (fr.n.i - 1 > 0) {
            fr.t60.i = fr.n.i - 1;
            fr.k = 1;
            Plane_3c1d0 *p = &list[0];
            do {
                fr.w = fr.cur;
                fr.w.x = fr.w.x - p->pos.x;
                fr.w.y = fr.w.y - p->pos.y;
                fr.w.z = fr.w.z - p->pos.z;
                if (((fr.w.z * p->n.z + fr.w.y * p->n.y) + fr.w.x * p->n.x) > 0.0f
                    && fr.k < fr.n.i) {
                    fr.t10.i = fr.n.i - fr.k;
                    Plane_3c1d0 *q = p + 1;
                    do {
                        fr.u = fr.cur;
                        fr.u.x = fr.u.x - q->pos.x;
                        fr.u.y = fr.u.y - q->pos.y;
                        fr.u.z = fr.u.z - q->pos.z;
                        if (((fr.u.z * q->n.z + fr.u.y * q->n.y) + fr.u.x * q->n.x) > 0.0f) {
                            hulk_freg cs = (p->n.z * q->n.z + p->n.y * q->n.y) + q->n.x * p->n.x;
                            if (cs < -9.99999975e-06f && cs > -0.99999f) {
                                fr.s.x = p->n.x + q->n.x;
                                fr.s.y = p->n.y + q->n.y;
                                fr.s.z = p->n.z + q->n.z;
                                fr.s.FUN_0022d110();
                                volatile float *vm = &fr.m.x;
                                vm[2] = -fr.w.z;
                                vm[0] = -fr.w.x - fr.u.x;
                                vm[0] = vm[0] * 0.5f;
                                vm[1] = (-fr.w.y - fr.u.y) * 0.5f;
                                vm[0] = vm[0] + fr.cur.x;
                                vm[1] = vm[1] + fr.cur.y;
                                vm[2] = (vm[2] - fr.u.z) * 0.5f + fr.cur.z;
                                if (p->d < q->d)
                                    fr.thr.f = p->d;
                                else
                                    fr.thr.f = q->d;
                                FUN_00038e80(0, p->obj, -1, &fr.m, &fr.s, fr.thr.f);
                            }
                        }
                        q++;
                        fr.t10.i--;
                    } while (fr.t10.i != 0);
                }
                fr.k++;
                p++;
                fr.t60.i--;
            } while (fr.t60.i != 0);
        }

        // main pass over the planes
        for (fr.k = 0; fr.k < count; fr.k++) {
            if (fr.k == -1)
                continue;
            Plane_3c1d0 *e = &list[fr.k];
            Obj_3c1d0 *o = e->obj;
            fr.flags[fr.k] = 0;
            fr.t10.o = o;
            if (o != 0 && o->type == 1 && o->f8->f11c != 0 && f1b24 > 0)
                continue;
            fr.P = e->pos;
            if (fr.mode == 5) {
                Mtx *mp = fr.kin->FUN_00221c40();
                fr.mtx = *mp;
                fr.up.x = 0;
                fr.up.y = 1.0f;
                fr.up.z = 0;
                ((owners::M_22c3b0 *)&(fr.mtx))->FUN_0022c3b0((float *)(V3_3c1d0 *)(&fr.up), (float *)(V3_3c1d0 *)(&fr.out));
                if (((fr.P.z * fr.out.z + fr.P.y * fr.out.y) + fr.out.x * fr.P.x)
                        + (-((fr.mtx.m[14] * fr.out.z + fr.mtx.m[13] * fr.out.y)
                             + fr.mtx.m[12] * fr.out.x))
                    < fr.half308)
                    continue;
                o = fr.t10.o;
            } else if (f140 != 4 && o != f328) {
                hulk_freg t1 = e->pos.y - fr.cur.y;
                hulk_freg x;
                if (f140 == 3) {
                    t1 = t1 + fr.rad;
                    x = 0.155f;
                } else {
                    x = fr.half308;
                }
                if (o->type == 5)
                    x = x * 0.5f;
                if (t1 < x)
                    continue;
                if (f140 == 1 && e->n.y > 0.5f) {
                    if (t1 < fr.rad)
                        continue;
                }
            }
            if (!(f11c != 0 && f11c->FUN_000456e0())) {
                if (e->n.y > 0.5f) {
                    e->n.y = 0;
                    hulk_freg len = e->n.FUN_0022d110();
                    if (fr.mode == 5 && len < 0.8f)
                        continue;
                    fr.t8c.f = len;
                    fr.t8c.u &= 0x7fffffff;
                    if (fr.t8c.f <= 0.1f)
                        continue;
                }
            }
            if (f140 == 4) {
                fr.G = vG;
                fr.q1 = -((fr.G.z * vH.z + fr.G.y * vH.y) + fr.G.x * vH.x);
                fr.n2.x = e->n.x;
                fr.n2.y = e->n.y;
                fr.n2.z = e->n.z;
                fr.n2.w = -((fr.n2.z * e->pos.z + fr.n2.y * e->pos.y) + fr.n2.x * e->pos.x);
                if (fr.G.FUN_0022d2b0(&fr.n2, 1e-05f)) {
                    fr.t60.f = fr.q1 - fr.n2.w;
                    fr.t60.u &= 0x7fffffff;
                    if (fr.t60.f <= 9.99999975e-06f)
                        continue;
                }
            }
            V3_3c1d0 *nn = &e->n;
            double dot = (fr.disp.y * nn->y + fr.disp.z * nn->z) + fr.disp.x * nn->x;
            if (dot < 0.0f) {
                fr.flags[fr.k] = 1;
                if (fr.k > -1) {
                    // push-out distance: kept unrounded on the FPU stack for the products, stored rounded in t10
                    double push = (e->d > 0.0f && -dot > e->d) ? e->d : -dot;
                    fr.t10.f = (float)push;
                    fr.s = *nn;
                    fr.s.y = (float)(fr.s.y * push);
                    fr.s.z = (float)(fr.s.z * push);
                    fr.disp.x = (float)(fr.s.x * push + fr.disp.x);
                    fr.disp.y = fr.s.y + fr.disp.y;
                    fr.disp.z = fr.s.z + fr.disp.z;
                    if (e->d < 0.0f) {
                        Obj_3c1d0 *ob = e->obj;
                        if (ob == 0 || ob->type != 1 || FUN_00044510(ob, 2)
                            || FUN_00044510(e->obj, 3) || FUN_00044510(e->obj, 5)) {
                            fr.nd = -e->d;
                            fr.s216 = fr.t10.f;
                            if (-e->d > fr.t10.f) {
                                fr.w = *nn;
                                bool cl = false;
                                if (f1d4d)
                                    cl = fr.w.y < -0.5f;
                                if (f140 != 3) {
                                    if (fr.w.y > 0.5f || cl)
                                        fr.w.y = 0;
                                }
                                hulk_freg lim = (f1d4d ? 2.0f : 10.0f) * dt;
                                fr.t10.f = fr.nd - fr.s216;
                                hulk_freg amt = (lim > fr.t10.f) ? fr.t10.f : lim;
                                fr.w.x = fr.w.x * amt;
                                fr.w.y = fr.w.y * amt;
                                fr.disp.x = fr.w.x + fr.disp.x;
                                fr.disp.y = fr.w.y + fr.disp.y;
                                fr.disp.z = amt * fr.w.z + fr.disp.z;
                            }
                        }
                    }
                } else {
                    fr.disp.x = 0;
                    fr.disp.z = 0;
                    fr.disp.y = 0;
                    continue;
                }
                fr.f16 = 0;
                if (o == 0)
                    continue;
                if (e->id != f12c)
                    continue;
                Pair_3c1d0 *pr = o->f74;
                if (pr != 0 && pr->f8 == DAT_004e2198 && pr->fc == DAT_004e219c) {
                    fr.f16 = 1;
                } else if (o->type == 1) {
                    if (o->f8 == 0)
                        continue;
                    Ctl_3c1d0 *c2 = o->f8->f11c;
                    if (c2 == 0)
                        continue;
                    int mm = c2->mode;
                    if (mm < 2)
                        continue;
                    if (mm > 3 && mm != 5)
                        continue;
                } else if (o->type == 5) {
                    if (!(o->v50.FUN_00018990() < 5.0f))
                        continue;
                } else {
                    continue;
                }
                fr.t10.f = nn->y;
                fr.t10.u &= 0x7fffffff;
                bool goB = !(fr.t10.f <= 0.1f);
                if (!goB && f140 == 1) {
                    hulk_freg t = e->pos.y - fr.cur.y;
                    if (!(t > fr.half * -0.8f))
                        goB = true;
                    else if (!(t < fr.half * 0.8f))
                        goB = true;
                }
                if (!goB) {
                    fr.q.x = fr.delta.x;
                    fr.q.y = fr.delta.y;
                    fr.q.z = fr.delta.z;
                    fr.q.y = 0;
                    fr.q.FUN_0022d110();
                    // x87: the dot is stored with fst and the register copy is compared with the best so far
                    hulk_freg facing = (fr.q.z * nn->z + fr.q.y * nn->y) + fr.q.x * nn->x;
                    fr.t10.f = facing;
                    if (!(facing < fr.lim1))
                        continue;
                    V3_3c1d0 *ep = &e->pos;
                    hitPos.x = ep->x;
                    hitPos.y = e->pos.y;
                    hitPos.z = ep->z;
                    hitNrm.x = nn->x;
                    hitNrm.y = nn->y;
                    hitNrm.z = nn->z;
                    FUN_00018810(&f1ad0, e->obj);
                    fr.lim1 = fr.t10.f;
                    if (fr.t10.f < -0.8f) {
                        f144 = f144 | 2;
                        if (fr.f16)
                            f144 = f144 | 4;
                    }
                    if (fr.mode == 5 && fr.f16 && e->d < -0.05f) {
                        unsigned int au = fr.ang.u;
                        if (!FUN_00018960(au, 0, 1e-05f)) {
                            fr.u.x = ep->x - fr.base.x;
                            fr.u.y = ep->y - fr.base.y;
                            fr.u.z = ep->z - fr.base.z;
                            fr.r2 = fr.u;
                            FUN_00224d70(au, &fr.r2);
                            fr.r3 = fr.r2;
                            if (((fr.r3.z - fr.u.z) * nn->z + (fr.r3.y - fr.u.y) * nn->y)
                                    + (fr.r3.x - fr.u.x) * nn->x
                                < 0.0f) {
                                fr.ang.f = 0;
                                fr.f17 = 1;
                            }
                        }
                    }
                    continue;
                }
                if (!(fr.delta.y > 0.85f))
                    continue;
                fr.thr.f = nn->y - (-1.0f);
                fr.thr.u &= 0x7fffffff;
                if (!(fr.thr.f <= 0.3f))
                    continue;
                if (f140 != 1) {
                    if (e->pos.y - fr.cur.y > fr.half * 0.5f) {
                        f144 = f144 | 8;
                        continue;
                    }
                    if (f140 != 1)
                        continue;
                }
                if (e->pos.y - fr.cur.y > fr.half * 1.5f)
                    f144 = f144 | 8;
                continue;
            }

            // surface faces away from the displacement
            {
                Obj_3c1d0 *ob = e->obj;
                if (ob != 0) {
                    int ty = ob->type;
                    bool go = false;
                    if (ty == 5 && (e->pos.y - fr.base.y) > fr.half220)
                        go = true;
                    else if ((e->pos.y - fr.base.y) > fr.rad)
                        go = true;
                    if (go && -(fr.f34raw * 0.5f) > e->d) {
                        bool pass;
                        if (ty != 1 && ob->f74 != 0 && ob->f74->f8 == DAT_004e2198
                            && ob->f74->fc == DAT_004e219c)
                            pass = true;
                        else
                            pass = FUN_00044510(ob, 2) || FUN_00044510(e->obj, 3)
                                   || FUN_00044510(e->obj, 5);
                        if (pass) {
                            fr.w = *nn;
                            bool cl = false;
                            if (f1d4d)
                                cl = fr.w.y < -0.5f;
                            if (f140 != 3) {
                                if (fr.w.y > 0.5f || cl)
                                    fr.w.y = 0;
                            }
                            fr.t10.f = -e->d;
                            hulk_freg lim = dt * 4.0f;
                            hulk_freg amt = (lim > fr.t10.f) ? fr.t10.f : lim;
                            fr.w.x = fr.w.x * amt;
                            fr.w.y = fr.w.y * amt;
                            fr.disp.x = fr.w.x + fr.disp.x;
                            fr.disp.y = fr.w.y + fr.disp.y;
                            fr.disp.z = amt * fr.w.z + fr.disp.z;
                        }
                    }
                }
            }
            if (e->obj == 0)
                continue;
            if (e->obj->type != 5)
                continue;
            if (!(fr.delta.y >= 0.0f))
                continue;
            fr.n.f = e->n.y - (-1.0f);
            fr.n.u &= 0x7fffffff;
            if (!(fr.n.f <= 0.3f))
                continue;
            if (f140 != 1) {
                if (e->pos.y - fr.cur.y > fr.half * 0.5f) {
                    f144 = f144 | 8;
                    continue;
                }
                if (f140 != 1)
                    continue;
            }
            if (e->pos.y - fr.cur.y > fr.half * 1.5f)
                f144 = f144 | 8;
        }

        fr.cur.x = fr.base.x + fr.disp.x;
        fr.cur.y = fr.base.y + fr.disp.y;
        fr.cur.z = fr.base.z + fr.disp.z;
        fr.body->FUN_002226f0(&fr.cur);
        if (fr.mode == 5 && fr.f17) {
            V4_3c1d0 *qv = fr.kin->FUN_00221cd0();
            fr.n2.x = qv->x;
            fr.n2.y = qv->y;
            fr.n2.z = qv->z;
            fr.n2.w = qv->w;
            fr.body->FUN_00222720(&fr.n2);
        }
    }
}
} // namespace fn_0003c1d0

namespace fn_f21e3c3e {

// 0x0003f650 FUN_0003f650 (348 B): matches/0x0003f650.cpp
// sym: ?FUN_0003f650@Entity@fn_f21e3c3e@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4)
// FUN_0003f650 @ 0x0003f650
void Entity::FUN_0003f650()
{
    Src_3f650 *s = src;
    if (s == 0) {
        return;
    }
    d0 = s->s0;
    d1 = s->s1;
    d2 = s->s2;
    d3 = s->s3;
    d4 = s->s4;
    d5 = s->s5;
    d6 = s->s6;
    d7 = s->s7;
    d8 = s->s8;
    d9 = s->s9;
    d10 = s->s10;
    d11 = s->s11;
    d12 = s->s12;
    d13 = s->s13;
    d14 = s->s14;
    d15 = s->s15;
    d16 = s->s16;
    d17 = s->s17;
    d18 = s->s18;
    for (int i = 1; i <= 14; i++) {
        char name[32];
        FUN_00267760(name, 32, "Attack%d", i);
        float v = s->FUN_00045f90(name);
        FUN_0003ed40(name, v);
    }
}

} // namespace fn_f21e3c3e

// 0x000401a0 FUN_000401a0 (590 B): equivalent/0x000401a0.cpp [wrapped: conflict: World]
// sym: ?FUN_000401a0@Character_401a0@fn_000401a0@@QAEXXZ @f5413cb56748 @wbf957dda2d54
namespace fn_000401a0 {
// STATUS: equivalent (tools/equiv.py level 3: 19195 inputs, branch coverage 38/38)
// FUN_000401a0 @ 0x000401a0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


struct Tuning_401a0 {
    bool FUN_00092940(int id);
};

struct Rig_401a0 {
    char pad0[0x128];
    float f128;  // 0x128
    float f12c;  // 0x12c
    char pad130[0x8];
    float f138;  // 0x138
    float f13c;  // 0x13c
    float f140;  // 0x140
    float f144;  // 0x144
    float f148;  // 0x148
    float f14c;  // 0x14c
    __int64 FUN_000443c0();
};

struct Hud_401a0 {
    char pad00[8];
    void* panel;
};

struct Pause {
    void FUN_000d2c30();
};

struct PauseHolder {
    char pad00[8];
    Pause* pause;           // 0x08
};

struct World {
    char pad00[0x3c];
    PauseHolder* holder;    // 0x3c
    char pad40[0x54 - 0x40];
    struct Registry_401a0* registry;  // 0x54
};

struct Registry_401a0 {
};


class Character_401a0 {
public:
    void FUN_000401a0();

    char pad0[0x11c];
    Rig_401a0* rig;  // 0x11c
    char pad120[0x19ec];
    float f1b0c;  // 0x1b0c
    float f1b10;  // 0x1b10
    float f1b14;  // 0x1b14
    char pad1b18[0x10];
    int f1b28;  // 0x1b28
    char pad1b2c[0x584];
    int f20b0;  // 0x20b0
};

void Character_401a0::FUN_000401a0()
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (rig == 0) {
        f20b0 = 0;
    } else {
        f20b0 = 0;
        Tuning_401a0* tuning = ((Tuning_401a0 *)((owners::A_86340 *)(DAT_004dd700->registry))->FUN_00086340());
        Rig_401a0* r = rig;
        // the load of f128 happens before the null test (hidden from the compiler)
        f1b10 = r->f128;
        if (rig && rig->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            if (tuning->FUN_00092940(0x27b)) {
                f1b10 = rig->f138 + f1b10;
                if (tuning->FUN_00092940(0x298)) {
                    f1b10 = rig->f13c + f1b10;
                    if (tuning->FUN_00092940(0x2ba))
                        f1b10 = rig->f140 + f1b10;
                }
            }
            f1b14 = f1b10;
            f1b10 = rig->f144 + f1b10;
            if (tuning->FUN_00092940(0x28b)) {
                f1b10 = rig->f148 + f1b10;
                if (tuning->FUN_00092940(0x29e))
                    f1b10 = rig->f14c + f1b10;
            }
        }

        r = rig;
        if (r && r->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            if (tuning->FUN_00092940(0x2e5)) {
                f1b10 = f1b10 + f1b10;
                f1b14 = f1b14 + f1b14;
            }
        } else {
            if (tuning->FUN_00092940(0x2e6))
                f1b10 = f1b10 + f1b10;
            if (tuning->FUN_00092940(0x2e7))
                f1b10 = f1b10 * 0.5f;
            f1b14 = f1b10;
        }

        r = rig;
        f1b28 = 0;
        f1b0c = r->f12c * f1b14;
        if (rig && rig->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            Pause* pause = DAT_004dd700->holder->pause;
            if (pause)
                pause->FUN_000d2c30();
        }
    }
}
} // namespace fn_000401a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00040970 FUN_00040970 (1089 B): equivalent/0x00040970.cpp [wrapped: conflict: World]
// sym: ?FUN_00040970@Actor_40970@fn_00040970@@QAEXPAUWorld@2@M@Z @a35ebee64893 @wb55044f6312f
namespace fn_00040970 {
// STATUS: equivalent (tools/equiv.py level 3: 3104 inputs, branch coverage 76/78, incomplete)
// FUN_00040970 @ 0x00040970
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


union Bits_40970 {
    float f;
    unsigned int u;
};

struct Buf_40970 {
    char data[0xb0];
    void FUN_001c9a40(unsigned int id);
};

struct Flags_40970 {
    bool FUN_00092940(int id);
};

struct Opts_40970 {
    Flags_40970 *FUN_00086340();
};

struct Sink_40970 {
    void FUN_001cbc20(Buf_40970 *b);
};

struct Hero_40970;
struct World {
    char pad00[0x20];
    struct Hero_40970 *hero;          // 0x20
    char pad24[0xc];
    Sink_40970 *sink30;               // 0x30
    char pad34[0x20];
    Opts_40970 *opts;                 // 0x54
};

struct Hero_40970 {
    bool FUN_00025d30(void *self);
};


struct Ref_40970 {
    unsigned int *id;
};

struct CCharacter_40970 {
    char pad00[0x130];
    float f130;
    float f134;
    char pad138[0x18];
    Bits_40970 f150;
    float f154;
    float f158;
    float f15c;
    char pad160[0x4c];
    float f1ac;
    void FUN_000443c0();
};

struct Sub_40970 {
    void FUN_00059790(int v);
};

struct Timer {
    unsigned int first;
    void FUN_002322f0(int a, float dt);
};

class Actor_40970 {
public:
    char pad000[0x10];
    unsigned int *f10;          // 0x10
    char pad14[0xc8];
    Timer t0dc;                 // 0xdc
    char pad0e0[0x24];
    Sub_40970 *sub104;                // 0x104
    unsigned int f108;          // 0x108
    float f10c;
    float f110;
    char pad114[4];
    char b118;                  // 0x118
    char pad119[3];
    CCharacter_40970 *o11c;               // 0x11c
    char pad120[0x1e0];
    float f300;
    float f304;
    char pad308[0xc];
    float f314;                 // 0x314
    char pad318[8];
    float f320;
    char pad324[0x10];
    int f334;
    int f338;
    char pad33c[0x50];
    float f38c;
    char pad390[0x1b0c - 0x390];
    Bits_40970 f1b0c;                 // 0x1b0c
    float f1b10;
    float f1b14;
    float f1b18;
    int f1b1c;
    char pad1b20[8];
    int f1b28;                  // 0x1b28
    float f1b2c;
    float f1b30;
    char b1b34;                 // 0x1b34
    char pad1b35[0x1e48 - 0x1b35];
    float f1e48;
    float f1e4c;
    int f1e50;
    float f1e54;
    char pad1e58[8];
    float f1e60[14];
    void FUN_00040550(float dt);
    void FUN_00040970(World *w, float dt);
};

void Actor_40970::FUN_00040970(World *w, float dt)
{
    struct Frame {
        float limit;
        Bits_40970 g;
        Bits_40970 av;
        Buf_40970 buf;
    } f;
    if (b118 != 0) {
        return;
    }
    dt = dt * f314;
    if (f110 > 0.0f) {
        double r = f110 - dt;
        f110 = r;
        if (r < 0.0)
            f110 = 0.0f;
    }
    if (f1b18 > 0.0f) {
        double r = f1b18 - dt;
        f1b18 = r;
        if (r < 0.0)
            f1b18 = 0.0f;
    }
    FUN_00040550(dt);
    sub104->FUN_00059790(0);
    f1e48 = dt + f1e48;
    f1e4c = dt + f1e4c;
    if (f1b28 != 0)
        f1b2c = dt + f1b2c;
    CCharacter_40970 *o = o11c;
    if (o != 0) {
        double v = f1b30 - dt * o->f15c;
        if (!(0.0 < v))
            v = 0.0;
        f1b30 = v;
        o->FUN_000443c0();
    }
    if (f1e50 != 0 && f1e54 > 0.0f)
        f1e54 = f1e54 - dt;
    for (int i = 0; i < 14; i++)
        f1e60[i] = dt + f1e60[i];

    if (o11c != 0) {
        if (f1b0c.f > 0.0f) {
            f.av = f1b0c;
            f.limit = o11c->f130 * f1b14;
            CCharacter_40970 *oc = o11c;
            bool proceed;
            if (b1b34 == 0) {
                if (f1e4c > oc->f154) {
                    b1b34 = 1;
                    f1b30 = 0.0f;
                }
                proceed = false;
            } else if (!(f1b30 >= oc->f158)) {
                proceed = true;
            } else {
                b1b34 = 0;
                proceed = false;
            }
            if (proceed && f.av.f < f.limit) {
                f.g = oc->f150;
                double base;
                if (((Hero_40970 *)w->hero)->FUN_00025d30(this) && w->opts->FUN_00086340()->FUN_00092940(0x2e2))
                    base = f.g.f * 10.0f;
                else
                    base = f.g.f;
                double t = base * dt + f.av.f;
                if (t > f.limit)
                    t = f.limit;
                bool skip = false;
                if (f1b18 > 0.0f || f1b1c > 0)
                    if (t < f1b0c.f)
                        skip = true;
                if (!skip) {
                    World *wd = DAT_004dd700;
                    bool wasNeg = (f1b0c.f <= 0.0f);
                    f1b0c.f = t;
                    if (t < 0.0)
                        f1b0c.f = 0.0f;
                    if (o11c != 0) {
                        if (f1b10 < f1b0c.f)
                            f1b0c.f = f1b10;
                        if (o11c->f134 > f1b0c.f && f1b28 != 2)
                            f1b0c.f = o11c->f134;
                        if (f1b0c.f <= 0.0f && !wasNeg && wd->sink30 != 0) {
                            f.buf.FUN_001c9a40(*f10);
                            wd->sink30->FUN_001cbc20(&f.buf);
                        }
                    }
                }
            }
        }
        if (f320 > 0.0f) {
            double r = f320 - dt * o11c->f1ac;
            f320 = r;
            if (r < 0.0)
                f320 = 0.0f;
        }
    }
    if (f334 != 0 || f338 != 0)
        f38c = dt + f38c;
    t0dc.FUN_002322f0(2, dt);
    if (f108 != t0dc.first) {
        f300 = 0.0f;
        f304 = 0.0f;
    }
}
} // namespace fn_00040970
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00042b40 FUN_00042b40 (2051 B): equivalent/0x00042b40.cpp [wrapped: conflict: World]
// sym: ?Setup@Chara_42b40@fn_00042b40@@QAEDPAVRig_42b40@2@@Z @3e43ca9cdbe7 @w8b918347fc9f
namespace fn_00042b40 {
// STATUS: equivalent (tools/equiv.py level 3: 1716 inputs, branch coverage 74/74)
// FUN_00042b40 @ 0x00042b40
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(unsigned int size);
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct V3_42b40 { float x, y, z; };

struct Mat_42b40 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
};

struct Str_42b40 {
    char data[8];
    void FUN_0027af10(int a, int b);
    void FUN_0027af50();
    void FUN_0027af60(int a, int b);
    void FUN_0027af70(Str_42b40 *s);
};

class RefObj_42b40 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Skel_42b40 {
    int FUN_0027b200(unsigned __int64 key);
    int FUN_00034ce0(const char *s);
    RefObj_42b40 *FUN_0027b240();
};

struct Mat0x10 {
    Mat_42b40 *FUN_00221c40();
};

struct P18_42b40 {
    char pad00[0x10];
    Mat0x10 m10;
};

struct Pair_42b40 { int a; int b; };

class RigBase : public RefObj_42b40 {};
struct RigSub;
class Rig_42b40 : public RefObj_42b40 {
public:
    char pad04[4];
    RigSub *f8;
    int fc;
    char pad10[4];
    int f14;
    char pad18[0x2c - 0x18];
    int f2c;
    float f30;
    float f34;
    V3_42b40 v38;
    char pad44[0x2f8 - 0x44];
    char b2f8;
    char pad2f9[3];
    float f2fc;
    char f300[0x2c];
    int w32c[9];
    char pad350[0x35c - 0x350];
    int w35c[8];
    unsigned char b37c;
    char pad37d;
    unsigned char b37e;
    unsigned char b37f;
    char pad380[4];
    unsigned char b384;
    char pad385[3];
    int w388;
    char pad38c[0x3b0 - 0x38c];
    V3_42b40 *FUN_00044360();
    Skel_42b40 *FUN_00044410();
    int FUN_000446c0(int i);
    unsigned __int64 FUN_000446e0(int i);
    V3_42b40 *FUN_00044710(V3_42b40 *out, int i);
    V3_42b40 *FUN_00044760(V3_42b40 *out, int i);
};

struct RigSub { char pad[8]; int f8; int fc; };

struct Gadget_42b40 {
    void FUN_002f2700(int a);
    void FUN_002f2730(float a);
};

struct EntrySub {
    char pad00[0x10];
    Str_42b40 s10;
    char pad18[0x1c - 0x18];
    Gadget_42b40 *g;
    char pad20[0x70 - 0x20];
    char b70;
    char pad71;
    char b72;
};

struct Chara_42b40;

struct Entry_42b40 {
    char pad00[8];
    Chara_42b40 *owner;
    int kind;
    char pad10[0x74 - 0x10];
    EntrySub *sub;
};

struct Obj2f0 { Obj2f0 *FUN_00222620(hulk_intptr a); };
struct Obj48 { Obj48 *FUN_002efe50(V3_42b40 *a, float b); };
struct Obj8c_42b40 { Obj8c_42b40 *FUN_002f3070(V3_42b40 *a, V3_42b40 *b, float c, float d, int e); };

struct Link10 {
    void FUN_00059d00(Obj2f0 *o);
    P18_42b40 *FUN_00059a40();
};

struct Node10 {
    char pad00[0x20];
    char b20;
    void FUN_001c5050(int a);
};
struct Node124_42b40 {
    char pad00[0x10];
    Node10 *f10;
    void FUN_001c5e20(RefObj_42b40 *a);
};

struct Dir_42b40 {
    void FUN_00065cb0(Pair_42b40 *p);
    Dir_42b40 *FUN_001c3d90();
    void FUN_001c3b30(Str_42b40 *s);
    Node124_42b40 *FUN_001c3b20(Str_42b40 *a, Str_42b40 *b);
};
Dir_42b40 *FUN_001c3d90();

struct Obj128_42b40;
struct Reg_42b40 {
    Obj128_42b40 *FUN_001e4ae0(const char *name, V3_42b40 *a, V3_42b40 *b, int c, int d, int e);
    Obj128_42b40 *FUN_001e4760(int obj, char *name, int a, Mat_42b40 *m, int b, int c, int d);
};

struct World {
    char pad00[0xc];
    Reg_42b40 *f0c;
};

struct Obj128_42b40 {
    virtual void AddRef();
    virtual void Release();
    char pad04[0x11c - 4];
    struct Rig2 *f11c;
    char pad120[0x148 - 0x120];
    Chara_42b40 *f148;
    char pad14c[0x1d8 - 0x14c];
    char b1d8;
    int FUN_001d68d0();
};

struct Rig2 { char pad00[0x18]; hulk_intptr f18; };

struct Sink284 { void FUN_00284820(int a); };

struct Holder_42b40 { Dir_42b40 *FUN_000678d0(); };

struct Mgr_42b40 { Mgr_42b40 *FUN_001b6580(); void FUN_001b4060(Chara_42b40 *c); void FUN_001b4540(Obj128_42b40 *o); void FUN_001b4450(Obj128_42b40 *o, int a); };

Entry_42b40 *__cdecl FUN_002efca0(void *obj, char *name);
void __cdecl FUN_00018810(RefObj_42b40 **slot, Entry_42b40 *e);
void __cdecl FUN_00037510(RefObj_42b40 **slot, RefObj_42b40 *r);
Dir_42b40 *FUN_000678d0();
Mgr_42b40 *FUN_001b6580();

struct Chara_42b40 {
    char pad00[8];
    int f8;
    int fc;
    Link10 *f10;
    char pad14[0x11c - 0x14];
    Rig_42b40 *rig;
    RefObj_42b40 *f120;
    Node124_42b40 *f124;
    Obj128_42b40 *f128;
    RefObj_42b40 *f12c;
    RefObj_42b40 *f130;
    char pad134[0x148 - 0x134];
    int f148;
    char pad14c[0x1b0c - 0x14c];
    float f1b0c;
    char pad1b10[0x1ca8 - 0x1b10];
    int w1ca8[9];
    int w1ccc[8];
    unsigned char b1cec;
    unsigned char b1ced;
    unsigned char b1cee;
    unsigned char b1cef;
    int w1cf0;
    char pad1cf4[0x1e48 - 0x1cf4];
    float f1e48;
    char pad1e4c[0x1f54 - 0x1e4c];
    int f1f54;
    char pad1f58[0x20b8 - 0x1f58];
    char name[0x40];
    void FUN_0003b620(int a);
    void FUN_00035190(Mat_42b40 *m);
    void FUN_000401a0();
    void FUN_0003acf0(int a, hulk_intptr b, int c, int d, int e, Mat_42b40 *m);
    char Setup(Rig_42b40 *r);
};

char Chara_42b40::Setup(Rig_42b40 *r)
{
    World *world = DAT_004dd700;
    if (rig == r) {
        return 1;
    }
    Mat_42b40 m44;
    m44.FUN_0022b980();
    P18_42b40 *p = f10->FUN_00059a40();
    if (p) {
        Mat_42b40 *src = p->m10.FUN_00221c40();
        m44 = *src;
    }
    FUN_0003b620(1);
    f10->FUN_00059d00(0);
    if (f124 != 0) {
        Str_42b40 s1;
        s1.FUN_0027af10(f8, fc);
        FUN_001c3d90()->FUN_001c3b30(&s1);
        s1.FUN_0027af50();
        f124 = 0;
    }
    if (f120) {
        f120->Release();
        f120 = 0;
    }
    if (f130) {
        f130->Release();
        f130 = 0;
    }
    if (f12c) {
        f12c->Release();
        f12c = 0;
    }
    if (r)
        r->AddRef();
    if (rig)
        rig->Release();
    rig = r;
    if (!r) {
        return 1;
    }
    Skel_42b40 *sk = r->FUN_00044410();
    if (sk) {
        f1f54 = sk->FUN_0027b200(FUN_002672f0("Head", 0, 0));
        if (f1f54 == 0xffff) {
            f1f54 = sk->FUN_00034ce0("Neck");
            if (f1f54 == 0xffff) {
                f1f54 = sk->FUN_00034ce0("turret");
                if (f1f54 == 0xffff)
                    f1f54 = 0;
            }
        }
        Reg_42b40 *reg = world->f0c;
        f128 = reg->FUN_001e4ae0(name, rig->FUN_00044360(), rig->FUN_00044360(), 1, 0, 0);
        if (f128) {
            f128->AddRef();
            f128->b1d8 = 1;
            FUN_00037510(&f120, (RefObj_42b40 *)f128->f11c->f18);
        } else {
            FUN_00037510(&f120, sk->FUN_0027b240());
            Str_42b40 sa;
            sa.FUN_0027af10(rig->f8->f8, rig->f8->fc);
            Str_42b40 sb;
            sb.FUN_0027af10(f8, fc);
            f124 = FUN_001c3d90()->FUN_001c3b20(&sb, &sa);
            sb.FUN_0027af50();
            sa.FUN_0027af50();
            if (f124) {
                f124->FUN_001c5e20(f120);
                Node10 *n10 = f124->f10;
                int v = rig->fc;
                if (n10) {
                    n10->FUN_001c5050(v);
                    n10->b20 = (v == 0);
                }
            }
        }

        Obj2f0 *o2f0 = (Obj2f0 *)thunk_FUN_0008d690(0x2f0);
        Obj2f0 *eo;
        if (o2f0)
            eo = o2f0->FUN_00222620((hulk_intptr)f120);
        else
            eo = 0;
        ((Str_42b40 *)((char *)eo + 8))->FUN_0027af70((Str_42b40 *)&f8);
        f10->FUN_00059d00(eo);
        FUN_00035190(&m44);

        float f34 = rig->f34;
        float rr = rig->f30 * 0.5f - f34;
        V3_42b40 vA = rig->v38;
        vA.z = -vA.z;
        vA.y = vA.y + rr + f34;
        void *made;
        if (rr < 0.0f) {
            Obj48 *o48 = (Obj48 *)FUN_0008d690(0x48);
            if (o48)
                made = o48->FUN_002efe50(&vA, f34);
            else
                made = 0;
        } else {
            union { char c; int i; } bu;
            bu.c = 0;
            if (rig->f14 == 2 || rig->f14 == 3) {
                bu.c = 1;
                rr = rr + f34;
            }
            Obj8c_42b40 *o8c = (Obj8c_42b40 *)FUN_0008d690(0x8c);
            if (o8c) {
                V3_42b40 up;
                up.x = 0;
                up.y = 1.0f;
                up.z = 0;
                made = o8c->FUN_002f3070(&vA, &up, rr, f34, bu.i);
            } else {
                made = 0;
            }
        }
        Entry_42b40 *e = FUN_002efca0(made, 0);
        if (e) {
            EntrySub *es = e->sub;
            es->g->FUN_002f2700(0);
            es->g->FUN_002f2730(1.0f);
            es->b70 = 1;
            es->s10.FUN_0027af60(0x29a, 0);
            e->kind = 1;
            e->owner = this;
            FUN_00018810(&f12c, e);
        }
        if (rig->b2f8) {
            Obj48 *o48 = (Obj48 *)FUN_0008d690(0x48);
            Obj48 *ob;
            if (o48)
                ob = o48->FUN_002efe50((V3_42b40 *)rig->f300, rig->f2fc);
            else
                ob = 0;
            char buf[0x40];
            FUN_00267760(buf, 0x40, "%s_csm", name);
            Entry_42b40 *e2 = FUN_002efca0(ob, buf);
            if (e2) {
                EntrySub *es = e2->sub;
                es->b70 = 1;
                es->b72 = 0;
                es->s10.FUN_0027af60(0x309, 0);
                e2->kind = 2;
                e2->owner = this;
                FUN_00018810(&f130, e2);
            }
        }
        FUN_001b6580()->FUN_001b4060(this);
        if (f128) {
            f128->f148 = this;
            FUN_001b6580()->FUN_001b4540(f128);
            FUN_001b6580()->FUN_001b4450(f128, 0);
        }
    }

    f148 = rig->f2c;
    if (f1b0c < 0.0f)
        FUN_000401a0();
    for (int i = 0; i < 8; i++) {
        int pr = rig->FUN_000446c0(i);
        if (pr == 0)
            continue;
        Mat_42b40 m88;
        m88.FUN_0022b980();
        char buf[0x100];
        FUN_00267760(buf, 0x100, "%s_attachedprop_%d", name, DAT_004dc300);
        Reg_42b40 *reg = world->f0c;
        int cnt = DAT_004dc300;
        DAT_004dc300 = cnt + 1;
        Obj128_42b40 *po = reg->FUN_001e4760(pr, buf, 0, &m88, 1, 0, 0);
        if (po == 0)
            continue;
        po->b1d8 = 1;
        hulk_intptr tp = po->FUN_001d68d0();
        if (tp)
            ((Sink284 *)tp)->FUN_00284820(0);
        int bone = 0;
        if (sk) {
            bone = sk->FUN_0027b200(rig->FUN_000446e0(i));
            if (bone == 0xffff)
                bone = 0;
        }
        Mat_42b40 mc8;
        mc8.FUN_0022b980();
        V3_42b40 t1;
        V3_42b40 *tr = rig->FUN_00044760(&t1, i);
        mc8.FUN_0022bc20(tr->x, tr->y, tr->z);
        V3_42b40 t2;
        V3_42b40 *tr2 = rig->FUN_00044710(&t2, i);
        mc8.m[12] = tr2->x;
        mc8.m[13] = tr2->y;
        mc8.m[14] = tr2->z;
        FUN_0003acf0(i, (hulk_intptr)po, bone, 0, 0, &mc8);
    }

    Rig_42b40 *c = rig;
    if (c->f14 == 0)
        f1e48 = 100000.0f;
    for (int i = 0; i < 9; i++)
        w1ca8[i] = c->w32c[i];
    for (int i = 0; i < 8; i++)
        w1ccc[i] = c->w35c[i];
    b1cec = c->b37c;
    b1ced = c->b37e;
    b1cee = c->b37f;
    b1cef = c->b384;
    w1cf0 = c->w388;
    if (b1cee) {
        Pair_42b40 ps;
        ps.a = f8;
        ps.b = fc;
        FUN_000678d0()->FUN_00065cb0(&ps);
    }
    return 1;
}
} // namespace fn_00042b40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

