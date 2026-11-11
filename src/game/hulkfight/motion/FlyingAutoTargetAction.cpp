// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00135ef0..0x001364a0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::FlyingAutoTargetAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa1d6404 {
#define TREE_TU_END }
namespace fn_fa1d6404 {} using namespace fn_fa1d6404;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa1d6404 {
class Obj_135ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_135ef0 {
  public:
    virtual void X();
    Action_135ef0();
};
class FlyingAutoTargetAction_135ef0 : public Action_135ef0 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_135ef0* m20;
    int m24;
    int m28;
    FlyingAutoTargetAction_135ef0(int, Obj_135ef0*);
};
extern void* g_vftable_135f40[];
class Ref_135f40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_135f40 {
  public:
    void* vptr;
};
class FlyingAutoTargetAction_135f40 : public Action_135f40 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_135f40* m20;
    Ref_135f40* m24;
    Ref_135f40* m28;
    ~FlyingAutoTargetAction_135f40();
};


// 0x00135ef0 FUN_00135ef0 (74 B): matches/0x00135ef0.cpp
// sym: ??0FlyingAutoTargetAction_135ef0@fn_fa1d6404@@QAE@HPAVObj_135ef0@1@@Z
// Same code shape as 0x00174c10 (propagated; names are from that function)
FlyingAutoTargetAction_135ef0::FlyingAutoTargetAction_135ef0(int v, Obj_135ef0* p) : Action_135ef0() {
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


// 0x00135f40 FUN_00135f40 (74 B): matches/0x00135f40.cpp
// sym: ??1FlyingAutoTargetAction_135f40@fn_fa1d6404@@QAE@XZ
FlyingAutoTargetAction_135f40::~FlyingAutoTargetAction_135f40() {
    vptr = g_vftable_135f40;
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
    ((fight::Action *)(Action_135f40 *)this)->FUN_002326a0();
}

} // namespace fn_fa1d6404

// 0x00135f90 hulkfight::motion::FlyingAutoTargetAction::vfunc_5 (1289 B): equivalent/0x00135f90.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@FlyingAutoTargetAction@motion@hulkfight@fn_00135f90@@UAEDHM@Z
namespace fn_00135f90 {
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 48/48)
// hulkfight::motion::FlyingAutoTargetAction::vfunc_5 @ 0x00135f90
struct V3_135f90 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_135f90 *other, float epsilon);
    void FUN_00011160(float s, V3_135f90 *d);
};

union FloatBits_135f90 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_135f90 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" hulk_freg __cdecl FUN_00224f10(V3_135f90 *v);
extern "C" void __cdecl FUN_00224d70(float angle, V3_135f90 *v);
extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_00224ea0(float x, float z);
extern "C" hulk_freg __cdecl FUN_00224fc0(float a, float b);

class Target_135f90 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    struct Mesh_135f90 *mesh;
    int kind;
    char pad10[0x40 - 0x10];
    V3_135f90 pos;
};

struct Mesh_135f90 {
    char pad0[0x11c];
    struct Info_135f90 *info;
    char pad120[0x140 - 0x120];
    int type;
};

struct Info_135f90 {
    char pad0[0x30];
    float height;
};

struct Stats_135f90 {
    char pad0[0x328];
    Target_135f90 *target;
    char pad32c[0x2064 - 0x32c];
    V3_135f90 aim2064;
    char pad2070[4];
    V3_135f90 aim2074;
    V3_135f90 aim2080;
    void FUN_000359c0(int n);
    void FUN_000350c0(V3_135f90 *out);
    void FUN_00035550(V3_135f90 *out);
    hulk_freg FUN_000354c0();
    bool FUN_0003a440(V3_135f90 *w, V3_135f90 *v, float a, int c2c, Target_135f90 *t);
    Target_135f90 *FUN_00039c60(V3_135f90 *w, V3_135f90 *v, int c28, int c2c, unsigned int flags, int z0, int z1);
    void FUN_0003ffa0(Target_135f90 *t, int z);
};

struct Pool_135f90 {
    Stats_135f90 *FUN_00059a30();
};

struct Owner_135f90 {
    Pool_135f90 *FUN_000592a0();
};

struct Transform_135f90 {
    void FUN_0022be40(V3_135f90 *p);
    void FUN_00221d20(float a);
};

struct Rig_135f90 {
    char pad0[0x18];
    Transform_135f90 transform;
};

struct Config_135f90 {
    char pad0[0x14];
    float f14;
    V3_135f90 vec18;
    float f24;
    int i28;
    int i2c;
};

namespace hulkfight { namespace motion {

class FlyingAutoTargetAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int a0, float a1);
    char pad04[0x18];
    Config_135f90 *cfg;     // 0x1c
    Owner_135f90 *owner;    // 0x20
    Rig_135f90 *rig;        // 0x24
    Target_135f90 *tgt;     // 0x28
};

char FlyingAutoTargetAction::vfunc_5(int a0, float a1)
{
    if (a0 != 0)
        return 1;
    if (rig == 0)
        return 0;

    Pool_135f90 *pool = owner->FUN_000592a0();
    Stats_135f90 *stats = pool->FUN_00059a30();
    stats->FUN_000359c0(3);
    V3_135f90 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;
    stats->FUN_000350c0(&w);
    V3_135f90 t;
    stats->FUN_00035550(&t);
    V3_135f90 v = t;
    bool usedFallback = false;

    if (tgt == 0) {
        V3_135f90 z;
        v = stats->aim2080;
        z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
        if (v.FUN_0022d2b0(&z, 1e-5f)) {
            v = stats->aim2074;
            z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
            if (v.FUN_0022d2b0(&z, 1e-5f)) {
                v = stats->aim2064;
                z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
                if (v.FUN_0022d2b0(&z, 1e-5f)) {
                    v = t;
                    usedFallback = true;
                }
            }
        }

        Target_135f90 *found = stats->target;
        bool direct = false;
        if (found) {
            if (stats->FUN_0003a440(&w, &v, 6.2831855f, cfg->i2c, found))
                direct = true;
        }
        if (!direct) {
            found = stats->FUN_00039c60(&w, &v, cfg->i28, cfg->i2c, 0x80000000u, 0, 0);
            if (!usedFallback && found == 0) {
                v = t;
                found = stats->FUN_00039c60(&w, &v, cfg->i28, cfg->i2c, 0x80000000u, 0, 0);
            }
        }
        if (found)
            found->v0();
        if (tgt)
            tgt->v1();
        tgt = found;
    }

    V3_135f90 dest = w;
    if (tgt) {
        if (stats->target == 0)
            stats->FUN_0003ffa0(tgt, 0);
        V3_135f90 p = tgt->pos;
        v.x = p.x - w.x;
        v.y = p.y - w.y;
        v.z = p.z - w.z;
        float h = FUN_00224f10(&v);
        V3_135f90 rv = cfg->vec18;
        FUN_00224d70(h + 3.14159274f, &rv);
        V3_135f90 q;
        q.x = rv.x + p.x;
        q.y = rv.y + p.y;
        q.z = rv.z + p.z;
        if (tgt->kind == 1) {
            Mesh_135f90 *m = tgt->mesh;
            if (m) {
                Info_135f90 *info = m->info;
                if (info) {
                    int type = m->type;
                    if (type != 3 && type != 4)
                        q.y = q.y + info->height;
                }
            }
        }
        V3_135f90 d;
        d.x = q.x - w.x;
        d.y = q.y - w.y;
        d.z = q.z - w.z;
        float len = d.FUN_0022d110();
        float c24 = cfg->f24;
        if (c24 < 0.0f) {
            dest = q;
        } else {
            double s = (double)c24 * (double)a1;
            if (s > (double)len)
                dest = q;
            else
                dest.FUN_00011160((float)s, &d);
        }
    }
    rig->transform.FUN_0022be40(&dest);

    float cur = stats->FUN_000354c0();
    float ang = FUN_00224ea0(v.x, v.z);
    float c14 = cfg->f14;
    float out = ang;
    if (!(c14 <= 0.0f)) {
        float r = FUN_00224fc0(cur, ang);
        float step = c14 * a1;
        if (!(AbsF(r) <= step)) {
            if (r < 0.0f)
                out = cur - step;
            else
                out = step + cur;
        }
    }
    rig->transform.FUN_00221d20(out);
    return 1;
}

}}
} // namespace fn_00135f90

