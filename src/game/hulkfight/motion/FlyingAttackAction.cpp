// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001353c0..0x00135be0 (kind game, layer game, confidence high), dominant class hulkfight::motion::FlyingAttackAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9de9b68 {
#define TREE_TU_END }
namespace fn_f9de9b68 {} using namespace fn_f9de9b68;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9de9b68 {
class Thing_1353c0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_1353c0 {
  public:
    Action_1353c0();
    virtual void X();
    virtual void Y();
};
class FlyingBrakeAction : public Action_1353c0 {
  public:
    FlyingBrakeAction(void* p, Thing_1353c0* t);
    char pad[0x1c - 4];
    int mF[9];
};
extern void* g_vftable_135420[];
class Ref_135420 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_135420 {
  public:
    void* vptr;
};
class FlyingBrakeAction_135420 : public Action_135420 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_135420* m20;
    Ref_135420* m24;
    ~FlyingBrakeAction_135420();
};
extern "C" char DAT_00411dc4[];
struct Ref_135470 {
    virtual void AddRef();
    virtual void Release();
};
struct ThisCall_00232660 {
    void BaseCtor();
};
class FlyingAttackAction {
  public:
    void* volatile vft;
    char pad04[0x18];
    void* volatile arg;
    Ref_135470* ref;
    int x24;
    int x28;
    int x2c;
    int x30;
    int x34;
    int x38;
    FlyingAttackAction* Run(void*, Ref_135470*);
};
class Ref_1354d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1354d0 {
  public:
    void* vptr;
};
class FlyingAttackAction_1354d0 : public Action_1354d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1354d0* m20;
    Ref_1354d0* m24;
    Ref_1354d0* m28;
    ~FlyingAttackAction_1354d0();
};
struct Tail_135700 {
    char pad[0x12c];
    int field;
};
struct Mid_135700 {
    Tail_135700* GetTail();
};
struct Obj_135700 {
};
struct Inner_135700 {
    virtual void f0();
    virtual void f1();
    int pad;
    P8* p8;
    int kind;
};
class FlyingAttackAction_135700 {
  public:
    char pad[0x20];
    Obj_135700* mA;
    int spare;
    Inner_135700* mItem;
    void Run();
};
struct A_135ba0 {
    void init();
    int check();
};
struct Result_135ba0 {
    void apply(int, int);
};
struct FlyingAttackAction_nv_135ba0 {
    void mid();
};


// 0x001353c0 FUN_001353c0 (89 B): matches/0x001353c0.cpp
// sym: ??0FlyingBrakeAction@fn_f9de9b68@@QAE@PAXPAVThing_1353c0@1@@Z
FlyingBrakeAction::FlyingBrakeAction(void* p, Thing_1353c0* t) : Action_1353c0() {
    int i;
    for (i = 0; i < 9; i++)
        mF[i] = 0;
    mF[0] = (hulk_intptr)p;
    if (t)
        t->A();
    if (mF[1])
        ((Thing_1353c0*)mF[1])->B();
    mF[1] = (hulk_intptr)t;
}


// 0x00135420 FUN_00135420 (69 B): matches/0x00135420.cpp
// sym: ??1FlyingBrakeAction_135420@fn_f9de9b68@@QAE@XZ
FlyingBrakeAction_135420::~FlyingBrakeAction_135420() {
    vptr = g_vftable_135420;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_135420 *)this)->FUN_002326a0();
}


// 0x00135470 FUN_00135470 (86 B): matches/0x00135470.cpp
// sym: ?Run@FlyingAttackAction@fn_f9de9b68@@QAEPAV12@PAXPAURef_135470@2@@Z
FlyingAttackAction* FlyingAttackAction::Run(void* a, Ref_135470* r) {
    ((ThisCall_00232660*)(this))->BaseCtor();
    vft = (void*)((hulk_intptr)DAT_00411dc4);
    arg = 0;
    ref = 0;
    x24 = 0;
    x28 = 0;
    x2c = 0;
    x30 = 0;
    x34 = 0;
    x38 = 0;
    arg = a;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    return this;
}


// 0x001354d0 FUN_001354d0 (74 B): matches/0x001354d0.cpp
// sym: ??1FlyingAttackAction_1354d0@fn_f9de9b68@@QAE@XZ
FlyingAttackAction_1354d0::~FlyingAttackAction_1354d0() {
    vptr = g_vftable_00411dc4;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1354d0 *)this)->FUN_002326a0();
}

} // namespace fn_f9de9b68

// 0x00135520 hulkfight::motion::FlyingAttackAction::vfunc_3 (472 B): equivalent/0x00135520.cpp [wrapped: conflict: FlyingAttackAction]
// sym: ?vfunc_3@FlyingAttackAction@fn_00135520@@UAE_NHH@Z
namespace fn_00135520 {
// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 14/14)
// hulkfight::motion::FlyingAttackAction::vfunc_3 @ 0x00135520
struct V3_135520 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Name_135520 {
    unsigned int lo, hi;
};

struct Matrix {
};

struct Xform_135520 {
    char data[0x54];
    void FUN_00221be0(const Xform_135520* src);
    void FUN_00221d20(float v);
    void FUN_00222180(const V3_135520* v);
    Matrix* FUN_00221c40();
};

class JointDriver_135520 {
public:
    virtual void AddRef();
    char pad4[4];
    Name_135520 name;
    char pad10[8];
    Xform_135520 xform;
    JointDriver_135520* FUN_002248f0(int a);
};

struct Linked_135520 {
    void FUN_0003ee70(int handle);
};

class RefObj_135520 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Linked_135520* linked;
    int kind;
};

struct Tracker_135520 {
    char pad0[0x10];
    Xform_135520 xf;
    void FUN_00222890(JointDriver_135520* d, float a, float b, float c, float e, float f, float g);
};

struct Stats_135520 {
    char pad0[0x12c];
    int handle;
    char pad130[0x328 - 0x130];
    RefObj_135520* body;
    void FUN_000350c0(V3_135520* out);
};

struct Fighter_135520 {
    Stats_135520* FUN_00059a30();
    Tracker_135520* FUN_00059a40();
};

struct Holder_135520 {
};

struct Config_135520 {
    char pad0[0x14];
    V3_135520 vec14;
    int f20;
    char pad24[0x30 - 0x24];
    char flag30;
    char pad31[0x34 - 0x31];
    float f34;
    float f38;
    float f3c;
};

void* __cdecl FUN_00263ea0(unsigned int size);
hulk_freg __cdecl FUN_00224f10(V3_135520* v);
extern "C" void __cdecl FUN_00096a90(RefObj_135520* r, V3_135520* out);

class FlyingAttackAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_135520* cfg;
    Holder_135520* holder;
    JointDriver_135520* driver;
    RefObj_135520* ref;
    int f2c;
    V3_135520 dir;
};

bool FlyingAttackAction::vfunc_3(int a, int b)
{
    struct Frame {
        hulk_freg f3c;
        hulk_freg f38;
        hulk_freg f34;
        V3_135520 pos;
        V3_135520 tmp;
    } fr;
    Fighter_135520* fighter = ((Fighter_135520 *)((owners::Object_592a0 *)holder)->FUN_000592a0());
    Stats_135520* stats = fighter->FUN_00059a30();
    Tracker_135520* tr = fighter->FUN_00059a40();
    if (tr == 0)
        return false;
    Config_135520* c = cfg;
    fr.f34 = c->f34;
    fr.f38 = c->f38;
    fr.f3c = c->f3c;
    void* mem = FUN_00263ea0(0x70);
    JointDriver_135520* d;
    if (mem != 0)
        d = ((JointDriver_135520*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"flyingAttack");
    driver->AddRef();
    driver->xform.FUN_00221be0(&tr->xf);
    tr->FUN_00222890(driver, -1.0f, fr.f34, 1.0f, fr.f38, fr.f3c, -1.0f);

    fr.tmp = cfg->vec14;
    ((owners::M_22c3b0 *)(tr->xf.FUN_00221c40()))->FUN_0022c3b0((float *)(const V3_135520 *)(&fr.tmp), (float *)(V3_135520 *)(&dir));
    dir.FUN_0022d110();

    fr.pos.x = 0.0f;
    fr.pos.y = 0.0f;
    fr.pos.z = 0.0f;
    stats->FUN_000350c0(&fr.pos);
    RefObj_135520* r = stats->body;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    if (r) {
        FUN_00096a90(r, &dir);
        dir.x = dir.x - fr.pos.x;
        dir.y = dir.y - fr.pos.y;
        dir.z = dir.z - fr.pos.z;
        dir.FUN_0022d110();
        if (r->kind == 1)
            r->linked->FUN_0003ee70(stats->handle);
    }
    if (cfg->flag30) {
        driver->xform.FUN_00222180(&dir);
    } else {
        float arg1 = FUN_00224f10(&dir);
        driver->xform.FUN_00221d20(arg1);
    }
    f2c = cfg->f20;
    return true;
}
} // namespace fn_00135520

namespace fn_f9de9b68 {

// 0x00135700 FUN_00135700 (92 B): matches/0x00135700.cpp
// sym: ?Run@FlyingAttackAction_135700@fn_f9de9b68@@QAEXXZ
void FlyingAttackAction_135700::Run() {
    if (mItem != 0 && mItem->kind == 1) {
        Tail_135700* t = ((Mid_135700 *)((owners::Object_592a0 *)mA)->FUN_000592a0())->GetTail();
        P8* p = mItem->p8;
        if (p != 0) {
            int v = t->field;
            if (p->Get() == v)
                p->Set(0);
        }
    }
    if (mItem != 0) {
        mItem->f1();
        mItem = 0;
    }
}

} // namespace fn_f9de9b68

// 0x00135760 hulkfight::motion::FlyingAttackAction::vfunc_5 (1073 B): equivalent/0x00135760.cpp [wrapped: conflict: FlyingAttackAction]
// sym: ?vfunc_5@FlyingAttackAction@fn_00135760@@UAE_NHM@Z
namespace fn_00135760 {
// STATUS: equivalent (tools/equiv.py level 3: 20015 inputs, branch coverage 32/32)
// hulkfight::motion::FlyingAttackAction::vfunc_5 @ 0x00135760


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


struct V3_135760 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000111b0(const V3_135760 *a, const V3_135760 *b);
    hulk_freg FUN_000111f0();
};

union Bits_135760 {
    float f;
    unsigned int u;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_135760 *axis, float angle);
};

struct Xform_135760 {
    char data[0x54];
    void FUN_00222180(V3_135760 *v);
    void FUN_00221d20(float v);
};

class FlyDriver_135760 {
public:
    virtual void AddRef();
    char pad4[0x14];
    Xform_135760 xform;                // 0x18
};

struct Stats_135760 {
    char pad0[0x1a88];
    float f1a88;
    char pad1a8c[0x2064 - 0x1a8c];
    V3_135760 v2064;
    float f2070;
};

struct Fighter_135760 {
    Stats_135760 *FUN_00059a30();
    void FUN_00059a50(V3_135760 *out);
};

struct Holder_135760 {
};

struct Config_135760 {
    char pad0[0x14];
    V3_135760 vec14;
    int f20;
    float f24;
    float f28;
    Bits_135760 f2c;
    char flag30;
};

hulk_freg __cdecl FUN_00224f10(V3_135760 *v);
void __cdecl FUN_00224d70(float angle, V3_135760 *v);
extern "C" int __cdecl FUN_00098190(unsigned int dt, unsigned int acc, unsigned int mag, int a, void *ref, int b,
                         V3_135760 *vel, V3_135760 *dir, int c, int d, int e, int f);

class FlyingAttackAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x1c - 4];
    Config_135760 *cfg;                // 0x1c
    Holder_135760 *holder;             // 0x20
    FlyDriver_135760 *driver;          // 0x24
    void *ref;                  // 0x28
    float f2c;                  // 0x2c
    V3_135760 dir;                     // 0x30
    void FUN_00135700();
};

bool FlyingAttackAction::vfunc_5(int a, float dt)
{
    struct Frame {
        Bits_135760 mag;
        hulk_freg acc;
        hulk_freg d;
        V3_135760 t18;
        V3_135760 vel;
        V3_135760 w;
        V3_135760 w2;
        Matrix m;
    } fr;

    if (a != 0)
        return true;
    if (driver == 0)
        return false;

    Fighter_135760 *fighter = ((Fighter_135760 *)((owners::Object_592a0 *)holder)->FUN_000592a0());
    Stats_135760 *stats = fighter->FUN_00059a30();
    ((owners::C_359c0 *)stats)->FUN_000359c0(3);
    fr.vel.x = 0.0f;
    fr.vel.y = 0.0f;
    fr.vel.z = 0.0f;
    fighter->FUN_00059a50(&fr.vel);

    Config_135760 *c = cfg;
    void *r = ref;
    double accd = dt * c->f24 + f2c;
    fr.acc = accd;
    f2c = accd;
    fr.mag = c->f2c;

    if (r != 0) {
        Bits_135760 dtb;
        dtb.f = dt;
        Bits_135760 accb;
        accb.f = fr.acc;
        if (!FUN_00098190(dtb.u, accb.u, fr.mag.u, 0, r, 0, &fr.vel, &dir, 0, 0, 0, 1))
            FUN_00135700();
    } else {
        hulk_freg f2070 = stats->f2070;
        V3_135760 *vc = &c->vec14;
        fr.t18 = *vc;
        fr.w = *vc;
        V3_135760 *sel = (f2070 <= 0.0f) ? &dir : &stats->v2064;
        FUN_00224d70(FUN_00224f10(sel), &fr.t18);
        fr.t18.FUN_0022d110();
        if (fr.mag.f < 0.0f) {
            dir = fr.t18;
        } else {
            double m2 = fr.mag.f * dt;
            fr.acc = m2;
            double cv;
            if (m2 < 0.0 || fr.acc > 3.14159274f)
                cv = -1.0f;
            else
                cv = cos(fr.acc);
            double d = fr.t18.z * dir.z + fr.t18.y * dir.y + fr.t18.x * dir.x;
            fr.d = d;
            if (d >= cv - DAT_004dd940) {
                dir = fr.t18;
            } else if (!((DAT_004dd940 - 1.0f) >= fr.d)) {
                fr.w.FUN_000111b0(&fr.t18, &dir);
                if (fr.w.FUN_000111f0() > 0.0f) {
                    fr.m.FUN_0022b980();
                    fr.m.FUN_0022baf0(&fr.w, fr.acc);
                    ((owners::M_22c3b0 *)&(fr.m))->FUN_0022c3b0((float *)(const V3_135760 *)(&dir), (float *)(V3_135760 *)(&dir));
                }
            }
        }
    }

    double s = dt * f2c;
    fr.t18 = dir;
    double px = fr.t18.x * s;
    fr.t18.y = fr.t18.y * s;
    fr.t18.z = fr.t18.z * s;
    fr.w = fr.vel;
    fr.vel.x = px + fr.vel.x;
    fr.vel.y = fr.t18.y + fr.vel.y;
    fr.vel.z = fr.t18.z + fr.vel.z;

    double lim = stats->f1a88 + cfg->f28;
    if (fr.vel.y < lim) {
        fr.vel.y = lim;
        fr.t18.x = fr.vel.x - fr.w.x;
        fr.t18.y = fr.vel.y - fr.w.y;
        fr.t18.z = fr.vel.z - fr.w.z;
        fr.t18.FUN_0022d110();
        if (fr.mag.f < 0.0f) {
            dir = fr.t18;
        } else {
            double dd = fr.t18.z * dir.z + fr.t18.y * dir.y + fr.t18.x * dir.x;
            double ang = fr.mag.f * dt;
            fr.acc = ang;
            double cv = cos(ang);
            if (dd >= cv) {
                dir = fr.t18;
            } else if (!(dd <= -1.0f)) {
                fr.w2.FUN_000111b0(&fr.t18, &dir);
                fr.m.FUN_0022b980();
                fr.m.FUN_0022baf0(&fr.w2, fr.acc);
                fr.w = dir;
                ((owners::M_22c3b0 *)&(fr.m))->FUN_0022c3b0((float *)(const V3_135760 *)(&fr.w), (float *)(V3_135760 *)(&dir));
            }
        }
    }

    ((owners::Target_22be40 *)&(driver->xform))->FUN_0022be40((const int *)(V3_135760 *)(&fr.vel));
    if (cfg->flag30)
        driver->xform.FUN_00222180(&dir);
    else
    {
        float tmp1 = FUN_00224f10(&dir);
        driver->xform.FUN_00221d20(tmp1);
    }
    return true;
}
} // namespace fn_00135760


// 0x00135ba0 hulkfight::motion::FlyingAttackAction::vfunc_4 (55 B): matches/0x00135ba0.cpp
// sym: ?vfunc_4@FlyingAttackAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::FlyingAttackAction::vfunc_4() {
    A_135ba0* edi = ((A_135ba0 *)((owners::Object_592a0 *)((*(A_135ba0 * *)&this->f_20)))->FUN_000592a0());
    edi->init();
    ((FlyingAttackAction_nv_135ba0*)this)->mid();
    hulk_intptr result = edi->check();
    if (result)
        ((Result_135ba0*)result)->apply(this->f_24, 0);
}

