// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136850..0x00136dc0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::AirToGroundTargetAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc9ef4a6 {
#define TREE_TU_END }
namespace fn_fc9ef4a6 {} using namespace fn_fc9ef4a6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc9ef4a6 {
extern "C" char DAT_00411e34[];
class Ref_136850 {
  public:
    virtual void Fn();
    virtual void Release();
};
class AirToGroundTargetAction_136850 {
  public:
    void Init_00232660();
};
class AirToGroundTargetAction {
  public:
    int vf;
    char pad[0x18];
    int a, b, c, d, e, f;
    AirToGroundTargetAction(int x, Ref_136850* r);
};
extern void* hulk_at_00411e34[];
class Ref_1368a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1368a0 {
  public:
    void* vptr;
};
class AirToGroundTargetAction_1368a0 : public Action_1368a0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1368a0* m20;
    Ref_1368a0* m24;
    Ref_1368a0* m28;
    ~AirToGroundTargetAction_1368a0();
};
class Obj_136d60 {
  public:
    virtual void a();
    virtual void b();
    Obj_136d60* query_00059a40();
    void act_00222970(void*, int);
};
class Source_136d60 {
  public:
};


// 0x00136850 FUN_00136850 (80 B): matches/0x00136850.cpp
// sym: ??0AirToGroundTargetAction@fn_fc9ef4a6@@QAE@HPAVRef_136850@1@@Z
AirToGroundTargetAction::AirToGroundTargetAction(int x, Ref_136850* r) {
    ((AirToGroundTargetAction_136850*)this)->Init_00232660();
    Ref_136850* q = r;
    volatile int* p = &vf;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_00411e34);
    volatile int* z = &a;
    *z = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (q)
        q->Fn();
    if (b)
        ((Ref_136850*)b)->Release();
    b = (hulk_intptr)q;
}


// 0x001368a0 FUN_001368a0 (74 B): matches/0x001368a0.cpp
// sym: ??1AirToGroundTargetAction_1368a0@fn_fc9ef4a6@@QAE@XZ
AirToGroundTargetAction_1368a0::~AirToGroundTargetAction_1368a0() {
    vptr = hulk_at_00411e34;
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
    ((fight::Action *)(Action_1368a0 *)this)->FUN_002326a0();
}

} // namespace fn_fc9ef4a6

// 0x001368f0 hulkfight::motion::AirToGroundTargetAction::vfunc_5 (1123 B): equivalent/0x001368f0.cpp [wrapped: conflict: AirToGroundTargetAction]
// sym: ?v5@AirToGroundTargetAction@fn_001368f0@@UAEDTArg1_1368f0@2@M@Z
namespace fn_001368f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 43/44, incomplete)
// hulkfight::motion::AirToGroundTargetAction::vfunc_5 @ 0x001368f0

struct V3_1368f0 {
    float x, y, z;
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


class Prop_1368f0 {
  public:
    virtual void addRef();
    virtual void release();
};

struct Sub18_1368f0 {
    void FUN_00221d20(float v);
};
struct Target_1368f0 {
    char pad[0x18];
    Sub18_1368f0 sub;
};

struct Mover_1368f0 {
    char pad0[0x328];
    Prop_1368f0 *prop;
    hulk_freg FUN_000354c0();
};

struct Pos_1368f0 {
    void FUN_00059a50(V3_1368f0 *out);
};
struct Inner_1368f0 {
    Mover_1368f0 *FUN_00059a30();
};
struct Source_1368f0 {
};

struct Info_1368f0 {
    char pad0[0x14];
    float lo;
    float hi;
    float rate;
    float grav;
    float f24;
    float f28;
};

extern "C" void FUN_00096a90(Prop_1368f0 *p, V3_1368f0 *out);
hulk_freg FUN_00224f10(V3_1368f0 *v);
hulk_freg FUN_00224fc0(float a, float b);
void FUN_00224d70(float a, V3_1368f0 *v);

struct Frame_1368f0 {
    float g;
    float t1;
    float t2;
    V3_1368f0 d;
    V3_1368f0 pos;
    V3_1368f0 w;
    V3_1368f0 pn;
    V3_1368f0 q;
};

union Arg1_1368f0 {
    int flag;
    float v;
};

class AirToGroundTargetAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(Arg1_1368f0 a1, float dt);
    char pad04[0x1c - 4];
    Info_1368f0 *info;
    Source_1368f0 *source;
    Target_1368f0 *target;
    Prop_1368f0 *prop;
    float speed;
    float vy;
};

char AirToGroundTargetAction::v5(Arg1_1368f0 a1, float dt)
{
    if (a1.flag)
        return 1;
    if (!target)
        return 0;
    Frame_1368f0 f;
    Inner_1368f0 *inner = ((Inner_1368f0 *)((owners::Object_592a0 *)source)->FUN_000592a0());
    Mover_1368f0 *mover = inner->FUN_00059a30();
    ((owners::C_359c0 *)mover)->FUN_000359c0(3);
    f.pos.x = 0;
    f.pos.y = 0;
    f.pos.z = 0;
    ((Pos_1368f0 *)inner)->FUN_00059a50(&f.pos);
    if (!prop) {
        Prop_1368f0 *np = mover->prop;
        if (np)
            np->addRef();
        if (prop)
            prop->release();
        prop = np;
    }
    a1.v = mover->FUN_000354c0();
    if (prop) {
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        FUN_00096a90(prop, &f.q);
        f.d.x = f.q.x - f.pos.x;
        f.d.y = f.q.y - f.pos.y;
        f.d.z = f.q.z - f.pos.z;
        f.t1 = FUN_00224f10(&f.d);
        f.t2 = info->f24;
        if (f.t2 <= 0.0f) {
            a1.v = f.t1;
        } else {
            float r = FUN_00224fc0(a1.v, f.t1);
            f.t2 = f.t2 * dt;
            f.g = r;
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = r;
            bits.u &= 0x7fffffff;
            if (bits.f <= f.t2) {
                a1.v = f.t1;
            } else if (r < 0.0f) {
                a1.v = a1.v - f.t2;
            } else {
                a1.v = f.t2 + a1.v;
            }
        }
    }
    float v1 = a1.v;
    target->sub.FUN_00221d20(v1);
    f.g = info->grav;
    a1.v = speed;
    if (prop) {
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        FUN_00096a90(prop, &f.q);
        f.d.x = f.q.x - f.pos.x;
        f.d.y = f.q.y - f.pos.y;
        f.d.z = f.q.z - f.pos.z;
        if (f.d.y < 0.0f && f.g > 0.0f) {
            double inv = 1.0f / (double)(-f.g);
            double vy2 = (double)vy * (double)vy;
            double tt = (double)(-f.d.y) * (double)(-f.g);
            double disc = vy2 - (tt + tt);
            f.t2 = (float)(sqrt(disc) * inv);
            double tc = (double)(-vy) * inv;
            f.t1 = (float)((double)f.t2 + tc);
            double t2v = tc - (double)f.t2;
            double cand = 0.0f;
            bool have = false;
            if (f.t1 > 0.0f) {
                cand = f.t1;
                have = true;
            } else if (t2v > 0.0f) {
                cand = t2v;
                have = true;
            }
            if (have && cand > 0.0f) {
                double hd = sqrt((double)f.d.z * (double)f.d.z + (double)f.d.x * (double)f.d.x) - (double)info->f28;
                if (hd > 0.0f)
                    a1.v = (float)(hd / cand);
            }
        }
    }
    Info_1368f0 *inf = info;
    f.t2 = inf->rate;
    if (f.t2 <= 0.0f) {
        speed = a1.v;
    } else {
        double diff = (double)a1.v - (double)speed;
        f.t1 = f.t2 * dt;
        union {
            float f;
            unsigned int u;
        } bits;
        bits.f = (float)diff;
        bits.u &= 0x7fffffff;
        f.t2 = bits.f;
        if (f.t2 < f.t1) {
            speed = a1.v;
        } else if (diff < 0.0f) {
            speed = speed - f.t1;
        } else {
            speed = f.t1 + speed;
        }
    }
    float lo = inf->lo;
    float hi = inf->hi;
    a1.v = lo;
    float c;
    if (speed >= lo && speed <= hi)
        c = speed;
    else if (hi < speed)
        c = hi;
    else
        c = lo;
    speed = c;
    double newvy = (double)vy - (double)f.g * (double)dt;
    vy = (float)newvy;
    double sc = (double)c * (double)dt;
    f.w = (*(V3_1368f0*)&DAT_004abf64);
    f.w.x = (float)((double)f.w.x * sc);
    f.w.z = (float)((double)f.w.z * sc);
    f.w.y = (float)(newvy * (double)dt);
    FUN_00224d70(v1, &f.w);
    f.pn.x = f.pos.x + f.w.x;
    f.pn.y = f.pos.y + f.w.y;
    f.pn.z = f.pos.z + f.w.z;
    ((owners::Target_22be40 *)&(target->sub))->FUN_0022be40((const int *)(V3_1368f0 *)(&f.pn));
    return 1;
}
} // namespace fn_001368f0


// 0x00136d60 hulkfight::motion::AirToGroundTargetAction::vfunc_4 (56 B): matches/0x00136d60.cpp
// sym: ?vfunc_4@AirToGroundTargetAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::AirToGroundTargetAction::vfunc_4() {
    Obj_136d60* x = ((Obj_136d60 *)((owners::Object_592a0 *)((*(Source_136d60 * *)&this->f_20)))->FUN_000592a0());
    x = x->query_00059a40();
    if (x) {
        x->act_00222970((*(void * *)&this->f_24), 0);
        if ((*(Obj_136d60 * *)&this->f_28)) {
            (*(Obj_136d60 * *)&this->f_28)->b();
            (*(Obj_136d60 * *)&this->f_28) = 0;
        }
    }
}

