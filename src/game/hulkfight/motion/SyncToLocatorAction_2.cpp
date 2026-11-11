// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00175cc0..0x00175fd0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::SyncToLocatorAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff45f2cf {
#define TREE_TU_END }
namespace fn_ff45f2cf {} using namespace fn_ff45f2cf;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff45f2cf {
extern "C" char DAT_00417f48[];
class Ref_175cc0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Helper_175cc0 {
  public:
    void Init();
    void InitSub();
};
class TeleportToLocatorAction_175cc0 {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int value;
    Ref_175cc0* ref;
    char pad2[4];
    Helper_175cc0 sub;
    TeleportToLocatorAction_175cc0(int x, Ref_175cc0* r);
};
extern void* g_vftable_175d10[];
class Ref_175d10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175d10 {
  public:
    void* vptr;
};
struct Vec_175d10 {
    int a;
    void Destroy();
};
class TeleportToLocatorAction_175d10 : public Action_175d10 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_175d10* m20;
    char pad2[4];
    Vec_175d10 m28;
    ~TeleportToLocatorAction_175d10();
};
extern "C" char DAT_00417f64[];
class Ref_175d50 {
  public:
    virtual void F();
};
class Link_175d50 {
  public:
    virtual void A();
    virtual void B();
};
class Action_175d50 {
  public:
    void Init();
};
class Part_175d50 {
  public:
    void Init();
};
class SyncToLocatorAction_175d50 : public Action_175d50 {
  public:
    char pad0[0x1c];
    int mA;
    Link_175d50* mLink;
    char pad24[4];
    Part_175d50 part;
    char pad2c[4];
    int mX;
    int mY;
    char pad38[12];
    int mZ;
    SyncToLocatorAction_175d50* Func(int a, Ref_175d50* r);
};
extern void* g_vftable_175db0[];
class Ref_175db0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175db0 {
  public:
    void* vptr;
};
void Free(void*) throw();
struct Sub_175db0 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_175db0*) throw();
void __fastcall SubFini2(Sub_175db0*) throw();
class SyncToLocatorAction_175db0 : public Action_175db0 {
  public:
    char p1c[24];
    void* m1c;
    Ref_175db0* m20;
    char p28[4];
    Sub_175db0 s28;
    char p30[7];
    Ref_175db0* m30;
    ~SyncToLocatorAction_175db0() throw();
};
struct V3_175e00 {
    float x, y, z;
};
struct Xform_175e00 {
    char pad00[0x30];
    V3_175e00 pos;
    char pad3c[0x54 - 0x3c];
    hulk_freg FUN_002220d0();
    void FUN_00221d20(float angle);
    void FUN_0022be40(const V3_175e00* p);
};
struct Joint_175e00 {
    char pad00[0x18];
    Xform_175e00 xf;
};
struct Timing_175e00 {
};
struct Clock_175e00 {
    Timing_175e00* FUN_00059a30();
};
struct Target_175e00 {
    Clock_175e00* FUN_000592a0();
};
hulk_freg __cdecl FUN_00224fc0(float from, float to);
} // namespace fn_ff45f2cf
namespace hulkfight { namespace motion {
class SyncToLocatorAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x20 - 4];
    Target_175e00* owner;
    char pad24[0x30 - 0x24];
    Joint_175e00* joint;
    float targetAngle;
    V3_175e00 goal;
    float rate;
    V3_175e00 vel;
};
} }

namespace fn_ff45f2cf {

// 0x00175cc0 FUN_00175cc0 (80 B): matches/0x00175cc0.cpp
// sym: ??0TeleportToLocatorAction_175cc0@fn_ff45f2cf@@QAE@HPAVRef_175cc0@1@@Z
TeleportToLocatorAction_175cc0::TeleportToLocatorAction_175cc0(int x, Ref_175cc0* r) {
    ((Helper_175cc0*)this)->Init();
    vptr = ((hulk_intptr)DAT_00417f48);
    value = 0;
    ref = 0;
    sub.InitSub();
    value = x;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
}


// 0x00175d10 FUN_00175d10 (58 B): matches/0x00175d10.cpp
// sym: ??1TeleportToLocatorAction_175d10@fn_ff45f2cf@@QAE@XZ
TeleportToLocatorAction_175d10::~TeleportToLocatorAction_175d10() {
    vptr = g_vftable_175d10;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m28.Destroy();
    ((fight::Action *)(Action_175d10 *)this)->FUN_002326a0();
}


// 0x00175d50 FUN_00175d50 (85 B): matches/0x00175d50.cpp
// sym: ?Func@SyncToLocatorAction_175d50@fn_ff45f2cf@@QAEPAV12@HPAVRef_175d50@2@@Z
SyncToLocatorAction_175d50* SyncToLocatorAction_175d50::Func(int a, Ref_175d50* r) {
    Init();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00417f64);
    mA = 0;
    mLink = 0;
    part.Init();
    mX = 0;
    mY = 0;
    mZ = 0;
    mA = a;
    if (r)
        r->F();
    if (mLink)
        mLink->B();
    mLink = (Link_175d50*)r;
    return this;
}


// 0x00175db0 FUN_00175db0 (77 B): matches/0x00175db0.cpp
// sym: ??1SyncToLocatorAction_175db0@fn_ff45f2cf@@QAE@XZ
SyncToLocatorAction_175db0::~SyncToLocatorAction_175db0() throw() {
    vptr = g_vftable_175db0;
    _ReadWriteBarrier();
    if (m30) {
        m30->Release();
        m30 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    FUN_0027af50(&s28);
    ((fight::Action *)(Action_175db0 *)this)->FUN_002326a0();
}

} // namespace fn_ff45f2cf

// 0x00175e00 hulkfight::motion::SyncToLocatorAction::vfunc_5 (457 B): equivalent/0x00175e00.cpp
// sym: ?vfunc_5@SyncToLocatorAction@motion@hulkfight@@UAE_NHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// hulkfight::motion::SyncToLocatorAction::vfunc_5 @ 0x00175e00
bool hulkfight::motion::SyncToLocatorAction::vfunc_5(int skip, float dt)
{
    if (owner == 0)
        return false;
    if (joint == 0)
        return false;
    if (skip != 0)
        return true;
    owner->FUN_000592a0()->FUN_00059a30();
    float step = dt * rate;
    float cur = joint->xf.FUN_002220d0();
    float diff = FUN_00224fc0(targetAngle, cur);
    union {
        float f;
        unsigned int u;
    } ad, as;
    ad.f = diff;
    ad.u &= 0x7fffffff;
    as.f = step;
    as.u &= 0x7fffffff;
    if (ad.f < as.f)
        cur = targetAngle;
    else
        cur = cur - step;
    joint->xf.FUN_00221d20(cur);
    V3_175e00 v = vel;
    double xv = (double)v.x * dt;
    float yv = v.y * dt;
    float zv = v.z * dt;
    Joint_175e00* j = joint;
    V3_175e00 p = j->xf.pos;
    double dx = goal.x - p.x;
    double dy = goal.y - p.y;
    double dz = goal.z - p.z;
    double distGoal = sqrt(dz * dz + dy * dy + dx * dx);
    double distStep = sqrt(zv * zv + yv * yv + xv * xv);
    V3_175e00 np;
    if (!(distStep >= distGoal)) {
        np.x = (float)(xv + p.x);
        np.y = p.y + yv;
        np.z = p.z + zv;
    } else {
        np = goal;
    }
    j->xf.FUN_0022be40(&np);
    return true;
}

