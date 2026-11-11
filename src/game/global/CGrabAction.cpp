// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001df20..0x0001e870 (kind game, layer game, confidence high), dominant class CGrabAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faea5d7a {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faea5d7a {} using namespace fn_faea5d7a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faea5d7a {
struct Vec3 {
    float x, y, z;
};
class RefObj {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};
struct Binder;
struct CFightParamsCollision_1df20 : public RefObj {
    CFightParamsCollision_1df20 *FUN_000598e0(void *a, struct Obj *o) throw();
};
struct Binder {
    void FUN_00231ad0(struct Bind *b, CFightParamsCollision_1df20 *m, unsigned int flags) throw();
};
struct Bind {
    RefObj *ref;
    Binder *cur;
    char FUN_00231e80(Binder *r) throw();
};
class Factory {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual Binder *v8(CFightParamsCollision_1df20 *m, int z) throw();
};
struct Obj {
    char pad00[8];
    Vec3 a;
    char pad14[4];
    Vec3 b;
    char flag;
    char pad25[0x4c - 0x25];
    RefObj *s4c;
    RefObj *s50;
    int f54;
    char pad58[0x6c - 0x58];
    RefObj *s6c;
    RefObj *s70;
    int f74;
    char pad78[0x94 - 0x78];
    void FUN_00059820() throw();
    void FUN_00059300() throw();
};
void __cdecl FUN_00018810(RefObj **slot, RefObj *v) throw();
void __cdecl FUN_000187a0(RefObj **slot, RefObj *v) throw();
void __cdecl FUN_00018840(RefObj **slot, RefObj *v) throw();
void *__cdecl FUN_0008d690(unsigned int size) throw();
struct Info {
    char pad000[0x1b0];
    int f1b0;
};
struct Holder {
};
struct Entity {
    char pad000[0x10];
    void **f10;
    char pad14[0xdc - 0x14];
    Bind fdc;
    char padE4[0x11c - 0xe4];
    Info *info;
    char pad120[0x128 - 0x120];
    Holder *f128;
    RefObj *f12c;
    char pad130[0x330 - 0x130];
    Entity *f330;
    Entity *f334;
    Entity *f338;
    char pad33c[0x20b0 - 0x33c];
    int f20b0;
    char FUN_000360f0() throw();
    int FUN_00036270() throw();
    int FUN_00038f90(Vec3 *p, int a, int z) throw();
    char FUN_0003a590(struct World *g, Entity *e) throw();
    void FUN_0003a680(Entity *t, int a, int b, int c, void *m, float e5, float e6, float e7) throw();
    void FUN_0003a9d0(int v) throw();
    float FUN_000354c0() throw();
    void FUN_0003b160(struct Prop *p) throw();
    void FUN_0003b190(struct Prop *p) throw();
};
struct Fighter {
    void FUN_00059a50(Vec3 *out) throw();
};
struct List {
    char pad000[0xc];
    int count;
    char pad010[0x124 - 0x10];
    Entity *player;
    Entity *FUN_00024190(int i) throw();
};
struct Item {
    char pad00[0x2c];
    float f2c;
};
struct Prop {
    char pad00[0x28];
    unsigned int f28;
    char pad2c[0x64 - 0x2c];
    Vec3 pos;
    char pad70[0x100 - 0x70];
    struct P100 *f100;
};
struct P20 { char pad[0x20]; struct P34 *f20; };
struct P34 { char pad[0x34]; float f34; };
struct P74 { char pad[0x74]; P20 *f74; };
struct P100 { };
struct Mgr {
    int FUN_00079270() throw();
};
} // namespace fn_faea5d7a
struct World {
    char pad00[0x20];
    List *list;
    char pad24[0x4c - 0x24];
    Mgr *mgr;
};
namespace fn_faea5d7a {
struct Owner {
    char pad00[8];
    void *f08;
};
struct Cfg {
    char pad00[0x2c];
    union {
        float f2c;
        int i2c;
    };
    int f30;
    char pad34[4];
    Factory *f38;
    char pad3c[8];
    Factory *f44;
};
Fighter *__fastcall FUN_000592a0(Owner *owner) throw();
Entity *__fastcall FUN_00059a30(Fighter *f) throw();
class Ctrl {
public:
    char pad00[0x1c];
    Owner *f1c;
    Cfg *f20;
    char pad24[0x38 - 0x24];
    char done;
    char pad39[3];
    RefObj *f3c;
    void FUN_0001df20(Vec3 *a1, Vec3 *a2);
};


// 0x0001df20 FUN_0001df20 (1364 B): equivalent/0x0001df20.cpp
// sym: ?FUN_0001df20@Ctrl@fn_faea5d7a@@QAEXPAUVec3@2@0@Z @b7b4c8a7e494 @wbc2b83212d5d
// STATUS: equivalent (tools/equiv.py level 3: 2874 inputs, branch coverage 75/78, incomplete)
// FUN_0001df20 @ 0x0001df20
void Ctrl::FUN_0001df20(Vec3 *a1, Vec3 *a2)
{
    struct Frame {
        Vec3 pos;
        Obj o;
    } fr;

    Fighter *fighter = FUN_000592a0(f1c);
    Entity *edi = FUN_00059a30(fighter);
    Entity *player = DAT_004dd700->list->player;
    fr.pos.x = 0.0f;
    fr.pos.y = 0.0f;
    fr.pos.z = 0.0f;
    fighter->FUN_00059a50(&fr.pos);
    List *list = DAT_004dd700->list;
    int count = list->count;
    Entity *esi = 0;
    int r = 0;
    bool found = false;
    if (count > 0) {
        int idx = 0;
        do {
            esi = list->FUN_00024190(idx);
            if (esi != edi) {
                Info *p = esi->info;
                if (p != 0 && esi->f20b0 == 0 && !esi->FUN_000360f0() && esi->f338 == 0 && esi->f334 == 0) {
                    if (p->f1b0 != edi->info->f1b0) {
                        int lim = f20->f30;
                        if (!(esi->FUN_00036270() > lim)) {
                            r = esi->FUN_00038f90(a1, f20->i2c, 0);
                            if (r != 0) {
                                if (edi->FUN_0003a590((World *)DAT_004dd700, esi)) {
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            idx = idx + 1;
        } while (idx < count);
    }
    if (!found) {
        if (((int)((owners::Thing_36020 *)edi)->FUN_00036020()) != 0)
            return;
        if (edi->f334 != 0)
            return;
        if (((int)((owners::C_35ef0 *)edi)->FUN_00035ef0((hulk_intptr)0)) != 0)
            return;
        if (list->player != edi)
            return;
        Mgr *m = DAT_004dd700->mgr;
        int n = m->FUN_00079270();
        if (n <= 0)
            return;
        int i = 0;
        do {
            Prop *p = ((Prop *)((owners::Target_79280 *)m)->FUN_00079280(i));
            if (!((p->f28 >> 7) & 1)) {
                double dx = a1->x - p->pos.x;
                double dy = a1->y - p->pos.y;
                double dz = a1->z - p->pos.z;
                double rr = ((P74 *)p->f100)->f74->f20->f34 + f20->f2c;
                if (dz * dz + dy * dy + dx * dx < rr * rr) {
                    Factory *fac = f20->f44;
                    if (fac != 0) {
                        edi->FUN_0003b190(p);
                        Binder *b = fac->v8((CFightParamsCollision_1df20 *)f1c, 0);
                        if (b != 0) {
                            if (!edi->fdc.FUN_00231e80(b)) {
                                b->FUN_00231ad0(&edi->fdc, (CFightParamsCollision_1df20 *)f1c, 0x80000000);
                                if (edi->fdc.cur == b) {
                                    edi->FUN_0003b160(p);
                                    ((owners::C_80cb0 *)p)->FUN_00080cb0(5);
                                }
                            }
                        }
                    }
                    done = 1;
                    return;
                }
            }
            i = i + 1;
        } while (i < n);
        return;
    }

    fr.o.FUN_00059820();
    FUN_00018810(&fr.o.s4c, edi->f12c);
    FUN_00018810(&fr.o.s50, esi->f12c);
    fr.o.a = *a1;
    fr.o.b = *a2;
    fr.o.f54 = f20->f30;
    fr.o.f74 = r;
    fr.o.flag = 1;
    FUN_000187a0(&fr.o.s6c, f3c);
    FUN_00018840(&fr.o.s70, edi->fdc.ref);
    edi->f330 = esi;
    if (edi->info->f1b0 == 3 && esi != player && esi->f128 != 0)
        edi->FUN_0003a9d0(((int)((owners::C_1d72e0 *)(esi->f128))->FUN_001d72e0()));
    edi->FUN_000354c0();
    esi->f330 = edi;
    Factory *fac = f20->f44;
    char grabbed = 0;
    if (fac != 0) {
        void *mem = FUN_0008d690(0xb0);
        CFightParamsCollision_1df20 *b;
        if (mem)
            b = ((CFightParamsCollision_1df20 *)mem)->FUN_000598e0(f1c->f08, &fr.o);
        else
            b = 0;
        b->AddRef();
        edi->f330 = esi;
        Binder *bi = fac->v8(b, 0);
        if (bi != 0) {
            if (!edi->fdc.FUN_00231e80(bi)) {
                bi->FUN_00231ad0(&edi->fdc, b, 0x80000000);
                if (edi->fdc.cur == bi && esi->fdc.cur == bi) {
                    edi->f334 = esi;
                    edi->FUN_0003a680(0, -1, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                    esi->FUN_0003a680(edi, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                    esi->f334 = 0;
                    grabbed = 1;
                }
            }
        }
        b->Release();
    }
    Factory *fac2 = f20->f38;
    if (fac2 != 0) {
        void *mem = FUN_0008d690(0xb0);
        CFightParamsCollision_1df20 *b;
        if (mem)
            b = ((CFightParamsCollision_1df20 *)mem)->FUN_000598e0(*esi->f10, &fr.o);
        else
            b = 0;
        b->AddRef();
        esi->f330 = edi;
        Binder *bi = fac2->v8(b, 0);
        if (bi != 0) {
            bi->FUN_00231ad0(&esi->fdc, b, 0x80000000);
            if (!grabbed && edi->fdc.cur == bi && esi->fdc.cur == bi) {
                esi->f334 = edi;
                esi->FUN_0003a680(0, -1, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                edi->FUN_0003a680(esi, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                edi->f334 = 0;
            }
        }
        b->Release();
    }
    done = 1;
    fr.o.FUN_00059300();
}

} // namespace fn_faea5d7a

// 0x0001e480 CGrabAction::vfunc_6 (330 B): equivalent/0x0001e480.cpp [wrapped: conflict: CAction; CGrabAction; FUN_0008d690]
// sym: ?vfunc_6@CGrabAction@fn_0001e480@@UAEDH@Z @a4b166b9a773 @w031b6b70dcaa
namespace fn_0001e480 {
// STATUS: equivalent (tools/equiv.py level 3: 19934 inputs, branch coverage 8/8)
// CGrabAction::vfunc_6 @ 0x0001e480
struct Vec3_1e480 { float x, y, z; };

struct Mat_1e480 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_1e480 *in, Vec3_1e480 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat_1e480 *matrices;
};

struct Body_1e480 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_1e480 { char pad[4]; };
Fighter_1e480 *__fastcall FUN_000592a0(void *owner);
Body_1e480 *__fastcall FUN_00059a40(Fighter_1e480 *f);

class CGrabAction;

class Link_1e480 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats_1e480 {
    char pad0[0x130];
    int active;
    char pad134[0x330 - 0x134];
    int f330;
    char pad334[0x1b64 - 0x334];
    CGrabAction *grab;
    void FUN_0003b190(Link_1e480 *link);
};
Stats_1e480 *__fastcall FUN_00059a30(Fighter_1e480 *f);

struct Data_1e480 {
    char pad0[0x20];
    Vec3_1e480 offset;
    int handle;
};

struct Flags_1e480 {
    char pad0[0x70];
    unsigned char on;
    char pad71;
    unsigned char off;
};

class Effect_1e480 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_1e480 *m, int arg);
    char pad04[4];
    CGrabAction *owner;
    int mode;
    char pad10[0x74 - 0x10];
    Flags_1e480 *flags;
};

struct CollisionSphere_1e480 {
    CollisionSphere_1e480 *FUN_002efe50(Vec3_1e480 *v, int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
extern "C" Effect_1e480 *__cdecl FUN_002efca0(CollisionSphere_1e480 *init, const char *name);

struct Sys_1e480 {
    char pad0[8];
    void FUN_001b4230(Effect_1e480 *e);
};
Sys_1e480 *__cdecl FUN_001b6580();

class CAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *ownerObj;
    Data_1e480 *data;
    int matrixIndex;
    Effect_1e480 *effect;
    Vec3_1e480 pos;
};

class CGrabAction : public CAction {
public:
    virtual char vfunc_6(int arg);
};

char CGrabAction::vfunc_6(int arg)
{
    Fighter_1e480 *fighter = FUN_000592a0(ownerObj);
    Stats_1e480 *stats = FUN_00059a30(fighter);
    Body_1e480 *body = FUN_00059a40(fighter);
    if (body == 0)
        return 0;

    Vec3_1e480 off = data->offset;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &pos);

    stats->grab = this;
    stats->f330 = 0;
    stats->FUN_0003b190(0);
    if (stats->active != 0) {
        CollisionSphere_1e480 *init = 0;
        void *mem = FUN_0008d690(0x48);
        if (mem != 0) {
            Vec3_1e480 zero;
            zero.x = 0; zero.y = 0; zero.z = 0;
            int handle = data->handle;
            init = ((CollisionSphere_1e480 *)mem)->FUN_002efe50(&zero, handle);
        }
        Effect_1e480 *e = FUN_002efca0(init, 0);
        e->mode = 4;
        e->owner = this;
        e->vfunc_0();
        if (effect != 0)
            ((Link_1e480 *)effect)->vfunc_1();
        effect = e;
        Flags_1e480 *fl = e->flags;
        fl->on = 1;
        fl->off = 0;
        Effect_1e480 * arg1_ = effect;
        FUN_001b6580()->FUN_001b4230(arg1_);
        Mat_1e480 t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[14] = pos.z;
        t.m[13] = pos.y;
        effect->vfunc_6(&t, 0);
    }
    return 1;
}
} // namespace fn_0001e480


// 0x0001e5d0 CGrabAction::vfunc_8 (591 B): equivalent/0x0001e5d0.cpp [wrapped: conflict: CAction; CGrabAction; FUN_000592a0; Skeleton]
// sym: ?vfunc_8@CGrabAction@fn_0001e5d0@@UAEDH@Z @e06e3615d1bc @w0d4fc22bc4bd
namespace fn_0001e5d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CGrabAction::vfunc_8 @ 0x0001e5d0
struct Vec3_1e5d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat_1e5d0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_1e5d0 *in, Vec3_1e5d0 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat_1e5d0 *matrices;
};

struct Body_1e5d0 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_1e5d0 { char pad[4]; };
Fighter_1e5d0 *__fastcall FUN_000592a0(void *owner);
Body_1e5d0 *__fastcall FUN_00059a40(Fighter_1e5d0 *f);

class Link_1e5d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Data_1e5d0 {
    char pad0[0x20];
    Vec3_1e5d0 offset;
    float f2c;
};

class Effect_1e5d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_1e5d0 *m, int arg);
};

class CAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual char vfunc_8(int arg);
    char pad04[0x18];
    void *ownerObj;
    Data_1e5d0 *data;
    int matrixIndex;
    Effect_1e5d0 *effect;
    Vec3_1e5d0 pos;
    char finished;
    void FUN_0001df20(Vec3_1e5d0 *at, Vec3_1e5d0 *delta);
};

class CGrabAction : public CAction {
public:
    virtual char vfunc_8(int arg);
};

char CGrabAction::vfunc_8(int arg)
{
    if (finished)
        return 0;
    Fighter_1e5d0 *fighter = FUN_000592a0(ownerObj);
    Body_1e5d0 *body = FUN_00059a40(fighter);
    if (body == 0)
        return 0;

    Vec3_1e5d0 off = data->offset;
    Vec3_1e5d0 world;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &world);

    Vec3_1e5d0 d;
    d.x = world.x - pos.x;
    d.y = world.y - pos.y;
    d.z = world.z - pos.z;
    volatile float dist = d.FUN_0022d110();
    volatile float limit = data->f2c + data->f2c;

    bool simple = dist < limit;
    if (!simple) {
        union { float f; unsigned int u; } a;
        a.f = limit;
        a.u = a.u & 0x7fffffff;
        simple = a.f <= 1e-05f;
    }
    if (simple) {
        FUN_0001df20(&world, &d);
    } else {
        double q = dist / limit;
        int n = (int)q;
        if (q - (float)n > 0.0f)
            n++;
        if (n > 0x40)
            n = 0x40;
        double step = dist / (float)n;
        Vec3_1e5d0 cur = pos;
        Vec3_1e5d0 sv = d;
        sv.x = (float)(sv.x * step);
        sv.y = (float)(sv.y * step);
        sv.z = (float)(sv.z * step);
        for (int i = 0; i < n; i++) {
            cur.x = cur.x + sv.x;
            cur.y = cur.y + sv.y;
            cur.z = cur.z + sv.z;
            FUN_0001df20(&cur, &d);
            if (finished)
                break;
        }
    }

    if (effect != 0) {
        Mat_1e5d0 t;
        t.FUN_0022b980();
        t.m[12] = world.x;
        t.m[13] = world.y;
        t.m[14] = world.z;
        effect->vfunc_6(&t, arg);
    }
    pos.x = world.x;
    pos.y = world.y;
    pos.z = world.z;
    return !finished;
}
} // namespace fn_0001e5d0

