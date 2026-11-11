// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c1c0..0x0004c2f0 (kind game, layer game, confidence medium), dominant class CCollisionPushbackVelocityCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f746edeb {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f746edeb {} using namespace fn_f746edeb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f746edeb {
extern void* hulk_at_003f6d50[];
class CCondition_4c1c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionPushbackVelocityCondition : public CCondition_4c1c0 {
  public:
    CCollisionPushbackVelocityCondition* vfunc_5(signed char flags);
};


// 0x0004c1c0 CCollisionPushbackVelocityCondition::vfunc_5 (36 B): matches/0x0004c1c0.cpp
// sym: ?vfunc_5@CCollisionPushbackVelocityCondition@fn_f746edeb@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionPushbackVelocityCondition* CCollisionPushbackVelocityCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f746edeb

// 0x0004c1f0 CCollisionPushbackVelocityCondition::vfunc_7 (219 B): equivalent/0x0004c1f0.cpp [wrapped: conflict: CCollisionPushbackVelocityCondition]
// sym: ?vfunc_7@CCollisionPushbackVelocityCondition@fn_0004c1f0@@UAE_NPAUParams@2@@Z
namespace fn_0004c1f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackVelocityCondition::vfunc_7 @ 0x0004c1f0
struct Obj_4c1f0 {
    char pad00[0x28];
    float vx, vy, vz;               // 0x28
};

struct Params {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Obj_4c1f0 *GetObject();       // slot 3
};

extern "C++" __declspec(nothrow) bool FUN_00018960(float a, float b, float eps);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


class CCollisionPushbackVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Params *params);
    char pad04[8];
    unsigned int op;                // 0x0c
    float threshold;                // 0x10
};

bool CCollisionPushbackVelocityCondition::vfunc_7(Params *params)
{
    Obj_4c1f0 *obj = params->GetObject();
    if (!obj)
        return false;
    float speed = (float)sqrt(obj->vx * obj->vx + obj->vy * obj->vy + obj->vz * obj->vz);
    switch (op) {
    case 0:
        return speed < threshold;
    case 1:
        return speed <= threshold;
    case 2:
        return FUN_00018960(speed, threshold, 1.0e-5f);
    case 3:
        return !FUN_00018960(speed, threshold, 1.0e-5f);
    case 4:
        return speed >= threshold;
    case 5:
        return speed > threshold;
    }
    return false;
}
} // namespace fn_0004c1f0

