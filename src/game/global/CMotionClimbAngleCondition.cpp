// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004dc00..0x0004ded0 (kind game, layer game, confidence medium), dominant class CMotionClimbAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f7347cb6 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7347cb6 {} using namespace fn_f7347cb6;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7347cb6 {
extern void* CCondition_4dc00_vftable[];
class CCondition_4dc00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CClimbEdgeCondition : public CCondition_4dc00 {
  public:
    CClimbEdgeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4dc30_vftable[];
class CCondition_4dc30 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CMotionClimbAngleCondition : public CCondition_4dc30 {
  public:
    CMotionClimbAngleCondition* vfunc_5(signed char flags);
};


// 0x0004dc00 CClimbEdgeCondition::vfunc_5 (36 B): matches/0x0004dc00.cpp
// sym: ?vfunc_5@CClimbEdgeCondition@fn_f7347cb6@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CClimbEdgeCondition* CClimbEdgeCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4dc00_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004dc30 CMotionClimbAngleCondition::vfunc_5 (36 B): matches/0x0004dc30.cpp
// sym: ?vfunc_5@CMotionClimbAngleCondition@fn_f7347cb6@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CMotionClimbAngleCondition* CMotionClimbAngleCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4dc30_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f7347cb6

// 0x0004dc60 CMotionClimbAngleCondition::vfunc_7 (623 B): equivalent/0x0004dc60.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_7@CMotionClimbAngleCondition@fn_0004dc60@@UAE_NPAX@Z
namespace fn_0004dc60 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 16/16)
// CMotionClimbAngleCondition::vfunc_7 @ 0x0004dc60
struct Vec3_4dc60 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_4dc60* other, float epsilon);
    hulk_freg FUN_0022d110();
    void FUN_000111b0(const Vec3_4dc60* a, const Vec3_4dc60* b);
};

struct Stats_4dc60 {
    char pad0[0x1ae0];
    Vec3_4dc60 aimB;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3_4dc60 aimA;
    bool FUN_000356c0(Vec3_4dc60* out);
};

void* __fastcall FUN_000592a0(void* params);
extern "C" Stats_4dc60* __fastcall FUN_00059a30(void* owner);
extern "C++" __declspec(nothrow) hulk_freg FUN_00018a20(float v);
extern "C" hulk_freg FUN_00224fc0(float a, float b);

union FloatBits_4dc60 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_4dc60 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class CMotionClimbAngleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(void* params);
    char pad04[8];
    float angleTolerance;
    float limitAngle;
    float minLength;
};

struct Frame_4dc60 {
    float a;
    Vec3_4dc60 dir;
    Vec3_4dc60 vel;
    Vec3_4dc60 tmp; // zero / up / scaled-correction temp share one slot
    Vec3_4dc60 cross;
};

bool CMotionClimbAngleCondition::vfunc_7(void* params)
{
    Stats_4dc60* stats = FUN_00059a30(FUN_000592a0(params));
    Frame_4dc60 f;

    f.dir = stats->aimA;
    f.tmp.x = 0.0f;
    f.tmp.y = 0.0f;
    f.tmp.z = 0.0f;
    if (f.dir.FUN_0022d2b0(&f.tmp, 1e-5f)) {
        f.dir = stats->aimB;
        f.tmp.x = 0.0f;
        f.tmp.y = 0.0f;
        f.tmp.z = 0.0f;
        if (f.dir.FUN_0022d2b0(&f.tmp, 1e-5f))
            return 0;
    }
    f.dir.y = 0.0f;
    f.dir.FUN_0022d110();

    if (!stats->FUN_000356c0(&f.vel))
        return 0;

    double d = f.vel.z * f.dir.z + f.vel.x * f.dir.x + f.vel.y * f.dir.y;
    if (d < 0.0) {
        double nd = -d;
        f.tmp.x = f.dir.x;
        f.tmp.y = f.dir.y;
        f.tmp.z = f.dir.z;
        f.tmp.y = f.tmp.y * nd;
        f.tmp.z = f.tmp.z * nd;
        f.tmp.x = f.tmp.x * nd;
        f.vel.x = f.vel.x + f.tmp.x;
        f.vel.y = f.vel.y + f.tmp.y;
        f.vel.z = f.vel.z + f.tmp.z;
    }
    if (f.vel.FUN_0022d110() < minLength)
        return 0;

    f.a = FUN_00018a20(f.vel.y);
    hulk_freg fz = AbsF(f.vel.y);
    hulk_freg diff = fz - 1.0f;
    if (!(AbsF(diff) <= 1e-5f)) {
        f.tmp.x = 0.0f;
        f.tmp.y = 1.0f;
        f.tmp.z = 0.0f;
        f.cross.FUN_000111b0(&f.vel, &f.tmp);
        double c = f.cross.z * f.dir.z + f.cross.y * f.dir.y + f.dir.x * f.cross.x;
        if (c < 0.0)
            f.a = -f.a;
    }
    hulk_freg r = FUN_00224fc0(f.a, angleTolerance);
    hulk_freg limit = limitAngle * 0.5f;
    return limit > AbsF(r);
}
} // namespace fn_0004dc60

