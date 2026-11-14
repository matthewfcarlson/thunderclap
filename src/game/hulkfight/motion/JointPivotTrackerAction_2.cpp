// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00173c00..0x00174660 (kind game, layer game, confidence medium), dominant class hulkfight::motion::JointPivotTrackerAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fee916a2 {
#define TREE_TU_END }
namespace fn_fee916a2 {} using namespace fn_fee916a2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fee916a2 {
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_173c00 {
  public:
    virtual void Fn();
    char pad[0x18];
    Action_173c00();
};
struct Slot {
    volatile int value;
    Slot() : value(0) {}
};
class JointPivotTrackerAction : public Action_173c00 {
  public:
    virtual void Fn();
    Slot a;
    hulk_intptr b, c;
    char pad2[0x58];
    int d;
    JointPivotTrackerAction(int, Ref*);
};
extern void* hulk_at_00417e0c[];
class Ref_173c50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_173c50 {
  public:
    void* vptr;
};
void Free(void*);
struct Sub_173c50 {
    char c;
};
void __fastcall SubFini(Sub_173c50*);
void __fastcall SubFini2(Sub_173c50*);
class JointPivotTrackerAction_173c50 : public Action_173c50 {
  public:
    char p1c[24];
    void* m1c;
    Ref_173c50* m20;
    Ref_173c50* m24;
    char p80[88];
    Ref_173c50* m80;
    ~JointPivotTrackerAction_173c50();
};
struct V3_173ca0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000111b0(V3_173ca0 *a, V3_173ca0 *b);
    void FUN_00011160(float s, V3_173ca0 *b);
};
struct Q4 {
    float x, y, z, w;
    void FUN_000111b0(V3_173ca0 *a, V3_173ca0 *b);
};
struct Mat4_173ca0 {
    float m[12];
    V3_173ca0 t;
    float w;
    void FUN_0022b980();
    void FUN_0022c0b0();
    void FUN_0022c3b0(V3_173ca0 *in, V3_173ca0 *out);
    void FUN_0022baf0(V3_173ca0 *axis, float angle);
    void FUN_0022bec0(V3_173ca0 *a, V3_173ca0 *b);
    void FUN_0022ca90(Mat4_173ca0 *a, Mat4_173ca0 *b);
    void FUN_0022c2b0(Q4 *in, V3_173ca0 *out);
};
bool __cdecl FUN_00018960(float a, float b, float eps);
int __cdecl FUN_00011070(float v);
struct Slot18 {
    void FUN_00221c60(Mat4_173ca0 *m);
};
class JointDriver {
public:
    char pad00[0x10];
    int jointIndex;
    char pad14[4];
    Slot18 slot18;
    char pad18[0x70 - 0x18];
};
struct SkelInfo {
    char pad00[0x28];
    unsigned short *parents;
};
struct Skel_173ca0 {
    char pad00[8];
    SkelInfo *info;
    char pad0c[0x1c - 0xc];
    Mat4_173ca0 *mats;
};
struct Rig_173ca0 {
    char pad00[0x64];
    Skel_173ca0 *skel;
    void FUN_00222970(JointDriver *d, int a);
    void FUN_00222890(JointDriver *d, float a, int b, float c, int e, int f, float g);
};
struct Tracker_173ca0;
struct Stats_173ca0 {
    Tracker_173ca0 *FUN_0003ffe0(unsigned int a, unsigned int b, unsigned int flag, Tracker_173ca0 *prev, V3_173ca0 *out);
};
struct Fighter_173ca0 { char pad[4]; };
Fighter_173ca0 *__fastcall FUN_000592a0(void *owner);
Stats_173ca0 *__fastcall FUN_00059a30(Fighter_173ca0 *f);
Rig_173ca0 *__fastcall FUN_00059a40(Fighter_173ca0 *f);
struct Obj35 {
    void FUN_00035020(V3_173ca0 *p);
    void FUN_000350c0(V3_173ca0 *p);
};
struct Info8 {
    char pad00[0x2c];
    Q4 q;
};
struct Comp_173ca0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info8 *vf8();
};
class Char_173ca0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat4_173ca0 *vf15();
    char pad04[0x11c - 4];
    Comp_173ca0 *f11c;
    char pad120[0x148 - 0x120];
    Obj35 *f148;
    void FUN_001d69f0(V3_173ca0 *p);
};
struct Tracker_173ca0 {
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    void *obj;
    int kind;
    char pad10[0x40 - 0x10];
    V3_173ca0 pos;
};
struct TrackerData_173ca0 {
    char pad00[0x38];
    float rate;
    float lo;
    float hi;
    unsigned char flag;
    char pad45[3];
    unsigned int i48;
    unsigned int i4c;
    int mode;
    int i54;
    int i58;
    int i5c;
};
} // namespace fn_fee916a2
namespace hulkfight { namespace motion {
class JointPivotTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x1c - 4];
    TrackerData_173ca0 *data;
    void *owner;
    JointDriver *driver;
    V3_173ca0 side;
    V3_173ca0 axis;
    Mat4_173ca0 mat;
    Tracker_173ca0 *tracker;
};
} }
namespace fn_fee916a2 {
static inline float AbsF(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}
struct Frame_173ca0 {
    float s10;                      // 0x10: scratch / hi / lim
    union { int idx; float c; unsigned int flagw; unsigned char flagb; } u14;
    union { Skel_173ca0 *skel; float angle; } u18;
    V3_173ca0 v1c;                         // 0x1c
    V3_173ca0 p28;                         // 0x28
    float lo;                       // 0x34
    V3_173ca0 out38;                       // 0x38
    Rig_173ca0 *rig;                       // 0x44
    V3_173ca0 t48;                         // 0x48
    V3_173ca0 v54;                         // 0x54
    V3_173ca0 d60;                         // 0x60
    float s6c;                      // 0x6c
    V3_173ca0 v70;                         // 0x70
    Q4 q7c;                         // 0x7c
    V3_173ca0 v8c;                         // 0x8c
    Mat4_173ca0 m98;                       // 0x98
    Mat4_173ca0 md8;                       // 0xd8
    Mat4_173ca0 m118;                      // 0x118
    Mat4_173ca0 m158;                      // 0x158
    Mat4_173ca0 m198;                      // 0x198
    Mat4_173ca0 m1d8;                      // 0x1d8
    Mat4_173ca0 m218;                      // 0x218
};


// 0x00173c00 FUN_00173c00 (77 B): matches/0x00173c00.cpp
// sym: ??0JointPivotTrackerAction@fn_fee916a2@@QAE@HPAVRef@1@@Z
JointPivotTrackerAction::JointPivotTrackerAction(int x, Ref* r) : Action_173c00() {
    b = 0;
    c = 0;
    d = 0;
    a.value = x;
    if (r)
        r->Add();
    if (b)
        ((Ref*)b)->Release();
    b = (hulk_intptr)r;
}


// 0x00173c50 FUN_00173c50 (80 B): matches/0x00173c50.cpp
// sym: ??1JointPivotTrackerAction_173c50@fn_fee916a2@@QAE@XZ
JointPivotTrackerAction_173c50::~JointPivotTrackerAction_173c50() {
    vptr = hulk_at_00417e0c;
    _ReadWriteBarrier();
    if (m80) {
        m80->Release();
        m80 = 0;
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
    ((fight::Action *)(Action_173c50 *)this)->FUN_002326a0();
}

} // namespace fn_fee916a2

// 0x00173ca0 hulkfight::motion::JointPivotTrackerAction::vfunc_5 (2494 B): equivalent/0x00173ca0.cpp
// sym: ?vfunc_5@JointPivotTrackerAction@motion@hulkfight@@UAE_NHM@Z @1b0c222c3e01 @w3b89a04adb20
// STATUS: equivalent (tools/equiv.py level 3: 3128 inputs, branch coverage 95/98, incomplete)
// hulkfight::motion::JointPivotTrackerAction::vfunc_5 @ 0x00173ca0
bool hulkfight::motion::JointPivotTrackerAction::vfunc_5(int a, float dt)
{
    if (a != 0 || dt == 0.0f)
        return true;

    Frame_173ca0 F;
    Fighter_173ca0 *fighter = FUN_000592a0(owner);
    Stats_173ca0 *stats = FUN_00059a30(fighter);
    F.rig = FUN_00059a40(fighter);
    F.u18.skel = F.rig->skel;
    TrackerData_173ca0 *d = data;

    F.u14.flagb = d->flag;
    Tracker_173ca0 *tr = stats->FUN_0003ffe0(d->i48, d->i4c, F.u14.flagw, tracker, &F.d60);
    if (tr)
        tr->AddRef();
    if (tracker)
        tracker->Release();
    tracker = tr;

    F.u14.idx = driver->jointIndex;
    F.m98 = F.u18.skel->mats[F.u14.idx];
    F.t48 = F.m98.t;
    F.p28.x = 0;
    F.p28.y = 0;
    F.p28.z = 0;

    bool ok = false;
    if (tr) {
        F.p28 = tr->pos;
        d = data;
        int mode = d->mode;
        if (tr->kind == 1) {
            Obj35 *o = (Obj35 *)tr->obj;
            if (mode == 1)
                o->FUN_000350c0(&F.p28);
            else if (mode == 2)
                o->FUN_00035020(&F.p28);
        } else if (tr->kind == 5) {
            Char_173ca0 *o = (Char_173ca0 *)tr->obj;
            if (o) {
                o->FUN_001d69f0(&F.p28);
                if (o->f148) {
                    if (mode == 1)
                        o->f148->FUN_000350c0(&F.p28);
                    else if (mode == 2)
                        o->f148->FUN_00035020(&F.p28);
                } else if (mode == 2 || mode == 1) {
                    if (o->f11c) {
                        Info8 *inf = o->f11c->vf8();
                        if (inf) {
                            F.q7c = inf->q;
                            o->vf15()->FUN_0022c2b0(&F.q7c, &F.p28);
                        }
                    }
                }
            }
        }
        if (!_isnan((double)F.p28.x) && !_isnan((double)F.p28.y) && !FUN_00011070(F.p28.z)
            && AbsF(F.p28.x) < 5000.0f && AbsF(F.p28.y) < 5000.0f && AbsF(F.p28.z) < 5000.0f)
            ok = true;
    }

    if (ok) {
        F.d60.x = F.p28.x - F.t48.x;
        F.d60.y = F.p28.y - F.t48.y;
        F.d60.z = F.p28.z - F.t48.z;
        F.d60.FUN_0022d110();
    } else {
        if (tr) {
            if (tracker) {
                tracker->Release();
                tracker = 0;
            }
        }
        if (data->flag) {
            F.rig->FUN_00222970(driver, 0);
            return true;
        }
        if (FUN_00018960(F.d60.FUN_0022d110(), 0.0f, 1e-5f)) {
            F.rig->FUN_00222970(driver, 0);
            return true;
        }
    }

    F.m98.FUN_0022c3b0(&axis, &F.out38);
    // the original keeps dot (negated) in st0 and never rounds it to float
    hulk_freg dot = F.out38.z * F.d60.z + F.out38.y * F.d60.y + F.out38.x * F.d60.x;
    F.v1c = F.d60;
    dot = -dot;
    F.v1c.x = F.v1c.x + F.out38.x * dot;
    F.v1c.y = F.v1c.y + F.out38.y * dot;
    F.v1c.z = F.v1c.z + F.out38.z * dot;
    if (FUN_00018960(F.v1c.FUN_0022d110(), 0.0f, 1e-5f))
        F.m98.FUN_0022c3b0(&side, &F.v1c);

    {
        unsigned short par = F.u18.skel->info->parents[F.u14.idx];
        if (par == F.u14.idx || par == 0xffff)
            F.m158.FUN_0022b980();
        else
            F.m158 = F.u18.skel->mats[par];
    }

    d = data;
    F.lo = d->lo;
    F.s10 = d->hi;
    bool narrow = (F.s10 - F.lo) < 6.28318548f;
    F.u18.angle = 0.0f;
    if (narrow) {
        F.m158.FUN_0022c3b0(&side, &F.t48);
        float dot2 = F.t48.x * F.out38.x + F.t48.z * F.out38.z + F.t48.y * F.out38.y;
        F.v54 = F.t48;
        F.v54.FUN_00011160(-dot2, &F.out38);
        F.u14.c = F.v54.x * F.v1c.x + F.v54.z * F.v1c.z + F.v54.y * F.v1c.y;
        if (FUN_00018960(AbsF(F.u14.c), 1.0f, 1e-5f)) {
            if (F.u14.c < 0.0f)
                F.u18.angle = -3.14159274f;
            else
                F.u18.angle = 0.0f;
        } else {
            F.u18.angle = FUN_00018a20(F.u14.c);
            F.q7c.FUN_000111b0(&F.v1c, &F.v54);
            if (F.q7c.x * F.out38.x + F.q7c.z * F.out38.z + F.q7c.y * F.out38.y < 0.0f)
                F.u18.angle = -F.u18.angle;
        }
        if (F.u18.angle < F.lo) {
            F.u18.angle = F.lo;
            F.m118.FUN_0022baf0(&F.out38, F.lo);
            F.m118.FUN_0022c3b0(&F.v54, &F.v1c);
        } else if (F.u18.angle > F.s10) {
            F.u18.angle = F.s10;
            F.m118.FUN_0022baf0(&F.out38, F.s10);
            F.m118.FUN_0022c3b0(&F.v54, &F.v1c);
        }
    }

    F.m98.FUN_0022c3b0(&side, &F.v70);
    F.u14.c = data->rate;
    if (F.u14.c <= 0.0f) {
        F.v8c = F.v1c;
    } else {
        // the original compares the unrounded dot4 with 1 (fst, then fcomp st0), the stored one with -1, and keeps
        // the chosen angle (acos's st0) unrounded for the comparison
        hulk_freg dot4u = F.v70.x * F.v1c.x + F.v70.z * F.v1c.z + F.v70.y * F.v1c.y;
        float dot4 = (float)dot4u;
        F.s10 = F.u14.c * dt;
        if (((dot4u >= 1.0f) ? (hulk_freg)0.0f
                             : ((dot4 <= -1.0f) ? (hulk_freg)3.14159274f : (hulk_freg)FUN_00018a20(dot4))) <= F.s10) {
            F.v8c = F.v1c;
        } else {
            F.t48.FUN_000111b0(&F.v1c, &F.v70);
            if (narrow) {
                float a3;
                F.u14.c = F.v70.x * F.v54.x + F.v70.z * F.v54.z + F.v70.y * F.v54.y;
                if (FUN_00018960(AbsF(F.u14.c), 1.0f, 1e-5f)) {
                    if (F.u14.c < 0.0f)
                        a3 = -3.14159274f;
                    else
                        a3 = 0.0f;
                } else {
                    F.u14.c = FUN_00018a20(F.u14.c);
                    F.q7c.FUN_000111b0(&F.v70, &F.v54);
                    if (F.q7c.x * F.out38.x + F.q7c.z * F.out38.z + F.q7c.y * F.out38.y < 0.0f)
                        a3 = -F.u14.c;
                    else
                        a3 = F.u14.c;
                }
                if (F.u18.angle < -1.57079637f) {
                    if (a3 > F.u18.angle + 3.14159274f)
                        F.s10 = -F.s10;
                } else if (F.u18.angle > 1.57079637f) {
                    if (a3 < F.u18.angle - 3.14159274f)
                        F.s10 = -F.s10;
                }
            }
            F.m118.FUN_0022baf0(&F.t48, F.s10);
            F.m118.FUN_0022c3b0(&F.v70, &F.v8c);
        }
    }

    F.m198.FUN_0022b980();
    F.m198.FUN_0022bec0(&F.v8c, &F.out38);
    F.m1d8.FUN_0022ca90(&mat, &F.m198);
    F.md8 = F.m158;
    F.md8.t.z = 0;
    F.md8.t.y = 0;
    F.md8.t.x = 0;
    F.md8.FUN_0022c0b0();
    F.m218.FUN_0022ca90(&F.m1d8, &F.md8);
    driver->slot18.FUN_00221c60(&F.m218);
    d = data;
    F.rig->FUN_00222890(driver, -1.0f, d->i54, 1.0f, d->i58, d->i5c, -1.0f);
    return true;
}

