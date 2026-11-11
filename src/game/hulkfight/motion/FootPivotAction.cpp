// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00174c10..0x00174fb0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::FootPivotAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f18e0a3f {
#define TREE_TU_END }
namespace fn_f18e0a3f {} using namespace fn_f18e0a3f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f18e0a3f {
class Obj_174c10 {
  public:
    virtual void A();
    virtual void B();
};
class Action_174c10 {
  public:
    virtual void X();
    Action_174c10();
};
class FootPivotAction : public Action_174c10 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_174c10* m20;
    int m24;
    int m28;
    FootPivotAction(int, Obj_174c10*);
};
extern void* hulk_at_00417ebc[];
class Ref_174c60 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_174c60 {
  public:
};
class FootPivotAction_174c60 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_174c60* m20;
    char p24[4];
    Ref_174c60* m28;
    void f();
};
struct Vec3_174cb0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_174cb0 *other, float eps);
};
struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3_174cb0 *in, Vec3_174cb0 *out);
};
struct Transform_174cb0 {
    void FUN_00221d20(float v);
};
struct JointObject_174cb0 {
    char pad0[0x18];
    Transform_174cb0 transform;
};
struct Target_174cb0 {
    char pad0[0x40];
    Vec3_174cb0 pos;
};
struct Stats_174cb0 {
    char pad0[0x328];
    Target_174cb0 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_174cb0 aim;
    hulk_freg FUN_000354c0();
    void FUN_00035720(Vec3_174cb0 *v);
};
struct Skeleton2 {
    char pad0[0x1c];
    Matrix *matrices;
};
struct Skeleton1 {
    char pad0[0x64];
    Skeleton2 *inner;
};
struct Body_174cb0 {
    Stats_174cb0 *FUN_00059a30();
    Skeleton1 *FUN_00059a40();
    void FUN_00059a50(Vec3_174cb0 *out);
};
struct Pivot {
    char pad0[0x20];
    Vec3_174cb0 local;
    float angleOffset;      // 0x2c
    float turnRate;         // 0x30
    char useTarget;         // 0x34
};
Body_174cb0 *__fastcall FUN_000592a0(void *owner);
extern "C" hulk_freg FUN_00224f10(Vec3_174cb0 *v);
extern "C" hulk_freg FUN_00224fc0(float from, float to);
extern "C" void FUN_00224d70(float angle, Vec3_174cb0 *v);
} // namespace fn_f18e0a3f
namespace hulkfight { namespace motion {
class FootPivotAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, float dt);
    char pad04[0x18];
    Pivot *pivot;           // 0x1c
    void *owner;            // 0x20
    unsigned int index;     // 0x24
    JointObject_174cb0 *joint;     // 0x28
};
} }

namespace fn_f18e0a3f {

// 0x00174c10 FUN_00174c10 (74 B): matches/0x00174c10.cpp
// sym: ??0FootPivotAction@fn_f18e0a3f@@QAE@HPAVObj_174c10@1@@Z
FootPivotAction::FootPivotAction(int v, Obj_174c10* p) : Action_174c10() {
    volatile int* q = &m1c;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    m1c = v;
    if (p)
        p->A();
    if (m20)
        m20->B();
    m20 = p;
}


// 0x00174c60 FUN_00174c60 (69 B): matches/0x00174c60.cpp
// sym: ?f@FootPivotAction_174c60@fn_f18e0a3f@@QAEXXZ
void FootPivotAction_174c60::f() {
    vptr = hulk_at_00417ebc;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(((Helper_174c60*)this)))->FUN_002326a0();
}

} // namespace fn_f18e0a3f

// 0x00174cb0 hulkfight::motion::FootPivotAction::vfunc_5 (759 B): equivalent/0x00174cb0.cpp
// sym: ?vfunc_5@FootPivotAction@motion@hulkfight@@UAE_NHM@Z @bef30f912ccd @wbd7cc0ad6c1f
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 20/20)
// hulkfight::motion::FootPivotAction::vfunc_5 @ 0x00174cb0
namespace hulkfight { namespace motion {
bool FootPivotAction::vfunc_5(int a1, float dt)
{
    // One contiguous frame: the stubs fill through the pointers handed to callees.
    struct {
        float out;
        float rate;
        Vec3_174cb0 t;
        float angleNow;
        float target;
        Vec3_174cb0 d;
        Vec3_174cb0 m;
        Vec3_174cb0 f;
        Vec3_174cb0 r;
        Vec3_174cb0 a;
        Vec3_174cb0 z;
        Matrix mtx;
    } fr;

    if (a1 != 0)
        return true;

    Body_174cb0 *body = FUN_000592a0(owner);
    if (body == 0)
        return false;
    Stats_174cb0 *stats = body->FUN_00059a30();
    if (stats == 0)
        return false;
    Skeleton1 *skel = body->FUN_00059a40();
    if (skel == 0)
        return false;

    Matrix *mats = skel->inner->matrices;
    fr.a.x = 0.0f;
    fr.a.y = 0.0f;
    fr.a.z = 0.0f;
    fr.mtx = mats[index];
    fr.t = pivot->local;
    fr.mtx.FUN_0022c2b0(&fr.t, &fr.a);

    fr.m.x = 0.0f;
    fr.m.y = 0.0f;
    fr.m.z = 0.0f;
    body->FUN_00059a50(&fr.m);

    fr.d.x = fr.a.x - fr.m.x;
    fr.d.y = fr.a.y - fr.m.y;
    fr.d.z = fr.a.z - fr.m.z;
    fr.angleNow = stats->FUN_000354c0();

    float ang;
    if (pivot->useTarget) {
        Target_174cb0 *tgt = stats->target;
        if (tgt != 0) {
            fr.t.x = tgt->pos.x - fr.m.x;
            fr.t.y = tgt->pos.y - fr.m.y;
            fr.t.z = tgt->pos.z - fr.m.z;
            ang = FUN_00224f10(&fr.t);
        } else {
            ang = 0.0f;
        }
    } else {
        fr.t = stats->aim;
        fr.z.x = 0.0f;
        fr.z.y = 0.0f;
        fr.z.z = 0.0f;
        if (!fr.t.FUN_0022d2b0(&fr.z, 1e-5f))
            ang = FUN_00224f10(&fr.t);
        else
            ang = fr.angleNow;
    }

    fr.target = ang + pivot->angleOffset;
    fr.rate = pivot->turnRate;
    if (!(fr.rate < 0.0f)) {
        float diff = FUN_00224fc0(fr.angleNow, fr.target);
        float step = fr.rate * dt;
        union {
            float f;
            unsigned int u;
        } a;
        a.f = diff;
        a.u &= 0x7fffffff;
        if (a.f <= step)
            fr.out = fr.target;
        else if (!(diff < 0.0f))
            fr.out = step + fr.angleNow;
        else
            fr.out = fr.angleNow - step;
    } else {
        fr.out = fr.target;
    }

    joint->transform.FUN_00221d20(fr.out);

    float delta = fr.out - fr.angleNow;
    fr.r = fr.d;
    FUN_00224d70(delta, &fr.r);
    fr.f.x = fr.d.x - fr.r.x;
    fr.f.y = fr.d.y - fr.r.y;
    fr.f.z = fr.d.z - fr.r.z;
    stats->FUN_00035720(&fr.f);
    return true;
}
} }

