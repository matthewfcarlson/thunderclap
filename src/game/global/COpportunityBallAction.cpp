// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001adb0..0x0001b080 (kind game, layer game, confidence medium), dominant class COpportunityBallAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8ca2d43 {
#define TREE_TU_END }
namespace fn_f8ca2d43 {} using namespace fn_f8ca2d43;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8ca2d43 {
extern "C" char DAT_003f34a0[];
class Obj_1adb0 {
  public:
    virtual void f();
    virtual void g();
};
class CAction_1adb0 {
  public:
    CAction_1adb0();
    virtual void f();
    char pad[0x18];
    Obj_1adb0* mObj;
    int m20;
    int m24;
    char pad2[0x2c];
    int m54;
    int m58;
};
class COpportunityBallAction_1adb0 : public CAction_1adb0 {
  public:
    COpportunityBallAction_1adb0(int, Obj_1adb0*, int);
};
extern void* hulk_at_003f3390[];
class Ref_1ae10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1ae10 {
  public:
    void* vptr;
};
class CAction_1ae10 : public Action_1ae10 {
  public:
    char pad[24];
    Ref_1ae10* m;
    ~CAction_1ae10();
};
} // namespace fn_f8ca2d43
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" float fabsf(float);
#endif
namespace fn_f8ca2d43 {
struct Vec3_1ae40 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mat_1ae40 {
    float m[16];
};
struct Skeleton_1ae40 {
    char pad0[0x1c];
    Mat_1ae40* matrices;
};
struct Body_1ae40 {
    char pad0[0x64];
    Skeleton_1ae40* skeleton;
};
struct Handle_1ae40 {
    char pad[4];
};
struct Config_1ae40 {
    char pad0[0x20];
    Vec3_1ae40 target;
    float range;
    int maxSteps;
};
Handle_1ae40* __fastcall FUN_000592a0(void* owner);
extern "C" Body_1ae40* __fastcall FUN_00059a40(Handle_1ae40* h);
union Scratch_1ae40 {
    float f;
    unsigned int bits;
    int i;
};
struct Frame_1ae40 {
    Scratch_1ae40 s;
    float len;
    float lim;
    Vec3_1ae40 dir;
    Vec3_1ae40 delta;
    Vec3_1ae40 cursor;
    Vec3_1ae40 out;
};
struct COpportunityBallAction_nv_1ae40 {
    void FUN_000145b0(Vec3_1ae40* a, Vec3_1ae40* b, float c);
};


// 0x0001adb0 FUN_0001adb0 (92 B): matches/0x0001adb0.cpp
// sym: ??0COpportunityBallAction_1adb0@fn_f8ca2d43@@QAE@HPAVObj_1adb0@1@H@Z
COpportunityBallAction_1adb0::COpportunityBallAction_1adb0(int p2, Obj_1adb0* p3, int p4) : CAction_1adb0() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f3390);
    mObj = 0;
    if (p3)
        p3->f();
    if (mObj)
        mObj->g();
    mObj = p3;
    m24 = p4;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f34a0);
    m54 = 0;
    m58 = 0;
    m20 = p2;
}


// 0x0001ae10 FUN_0001ae10 (36 B): matches/0x0001ae10.cpp
// sym: ??1CAction_1ae10@fn_f8ca2d43@@QAE@XZ
CAction_1ae10::~CAction_1ae10() {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1ae10 *)this)->FUN_002326a0();
}

} // namespace fn_f8ca2d43

// 0x0001ae40 COpportunityBallAction::vfunc_8 (566 B): equivalent/0x0001ae40.cpp
// sym: ?vfunc_8@COpportunityBallAction@@UAE_NH@Z
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/24, incomplete)
// COpportunityBallAction::vfunc_8 @ 0x0001ae40
bool COpportunityBallAction::vfunc_8(int arg) {
    Frame_1ae40 f;

    Body_1ae40* body = FUN_00059a40(FUN_000592a0((*(void * *)&this->f_1c)));
    f.cursor = (*(Config_1ae40 * *)&this->f_20)->target;
    ((owners::Mat_22c2b0 *)&(body->skeleton->matrices[this->f_24]))->FUN_0022c2b0((float *)(const Vec3_1ae40 *)(&f.cursor), (float *)(Vec3_1ae40 *)(&f.out));

    f.dir.x = f.out.x - (*(Vec3_1ae40 *)&this->f_28).x;
    f.dir.y = f.out.y - (*(Vec3_1ae40 *)&this->f_28).y;
    f.dir.z = f.out.z - (*(Vec3_1ae40 *)&this->f_28).z;
    f.len = f.dir.FUN_0022d110();
    f.lim = (*(Config_1ae40 * *)&this->f_20)->range + (*(Config_1ae40 * *)&this->f_20)->range;

    f.s.f = f.lim;
    f.s.bits &= 0x7fffffff;
    if (f.len < f.lim || f.s.f <= 1e-05f) {
        ((COpportunityBallAction_nv_1ae40*)this)->FUN_000145b0(&f.out, &f.dir, f.len);
    } else {
        double ratio = f.len / f.lim;
        int n = (int)ratio;
        if (ratio - (float)n > 0.0f)
            n++;
        if (n > 0x40)
            n = 0x40;
        f.s.f = f.len / (float)n;
        f.cursor = (*(Vec3_1ae40 *)&this->f_28);
        f.delta.x = f.dir.x * f.s.f;
        f.delta.y = f.dir.y * f.s.f;
        f.delta.z = f.dir.z * f.s.f;
        for (int i = 0; i < n; i++) {
            f.cursor.x = f.cursor.x + f.delta.x;
            f.cursor.y = f.cursor.y + f.delta.y;
            f.cursor.z = f.cursor.z + f.delta.z;
            ((COpportunityBallAction_nv_1ae40*)this)->FUN_000145b0(&f.cursor, &f.dir, f.s.f);
            if ((*(Config_1ae40 * *)&this->f_20)->maxSteps > 0 && this->f_58 >= (*(Config_1ae40 * *)&this->f_20)->maxSteps)
                break;
        }
    }
    (*(Vec3_1ae40 *)&this->f_28) = f.out;
    return !((*(Config_1ae40 * *)&this->f_20)->maxSteps > 0 && this->f_58 >= (*(Config_1ae40 * *)&this->f_20)->maxSteps);
}

