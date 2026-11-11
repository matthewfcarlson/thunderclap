// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000190a0..0x00019380 (kind game, layer game, confidence medium), dominant class CDropAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f63f1981 {
#define TREE_TU_END }
namespace fn_f63f1981 {} using namespace fn_f63f1981;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f63f1981 {
extern "C" char DAT_003f3438[];
class Ref_190a0 {
  public:
    virtual void Add();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    char pad[24];
    Ref_190a0* mRef;
    int x;
};
class CDropAction : public CAction {
  public:
    virtual void D0();
    virtual void D1();
    Ref_190a0* mOther;
    int a;
    int b;
    CDropAction(int, Ref_190a0*);
};
class RefObj_19100 {
  public:
    virtual void v0();
    virtual void Release();
};
struct Tidier {
};
class CDropAction_19100 {
  public:
    char pad[0x1c];
    RefObj_19100* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_19100* volatile mB; // 0x24
    void Shutdown();
};


// 0x000190a0 FUN_000190a0 (85 B): matches/0x000190a0.cpp
// sym: ??0CDropAction@fn_f63f1981@@QAE@HPAVRef_190a0@1@@Z
CDropAction::CDropAction(int v, Ref_190a0* r) : CAction() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3390);
    mRef = 0;
    if (r)
        r->Add();
    if (mRef)
        mRef->Release();
    mRef = r;
    x = v;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3438);
    mOther = 0;
    b = 0;
}


// 0x00019100 FUN_00019100 (61 B): matches/0x00019100.cpp
// sym: ?Shutdown@CDropAction_19100@fn_f63f1981@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CDropAction_19100::Shutdown() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_19100* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_19100* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((fight::Action *)(((Tidier*)this)))->FUN_002326a0();
}

} // namespace fn_f63f1981

// 0x00019140 CDropAction::vfunc_7 (565 B): equivalent/0x00019140.cpp [wrapped: conflict: CDropAction]
// sym: ?vfunc_7@CDropAction@fn_00019140@@UAE_NM@Z
namespace fn_00019140 {
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/22)
// CDropAction::vfunc_7 @ 0x00019140
struct Vec3_19140 {
    float x, y, z;
};

union FloatBits_19140 {
    float f;
    unsigned int u;
};

hulk_freg __cdecl FUN_00224ea0(float x, float z);
hulk_freg __cdecl FUN_00224fc0(float from, float to);

static inline float AbsBits(float v)
{
    FloatBits_19140 bits;
    bits.f = v;
    bits.u &= 0x7fffffff;
    return bits.f;
}

struct Fighter_19140 {
    char pad00[0x2064];
    float velX;
    char pad2068[4];
    float velZ;
    float timer;
    void FUN_000359c0(int mode);
};

struct Anchor_19140 {
    Fighter_19140 *FUN_00059a30();
    void FUN_00059a50(Vec3_19140 *out);
};

struct Owner_19140 {
    Anchor_19140 *FUN_000592a0();
};

struct DropParams {
    char pad00[0x14];
    float angleOffset;
    float followRate;
    float turnRate;
    char pad20[0x28 - 0x20];
    float fallRate;
    float maxFall;
};

struct Transform_19140 {
    hulk_freg FUN_002220d0();
    void FUN_00221d20(float angle);
    void FUN_0022be40(Vec3_19140 *pos);
};

struct DropTarget {
    char pad00[0x18];
    Transform_19140 xform;
};

class CDropAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x1c - 4];
    Owner_19140 *owner;
    DropParams *params;
    DropTarget *target;
    float angle;
    float fall;
};

bool CDropAction::vfunc_7(float dt)
{
    if (target == 0) {
        return false;
    }
    Anchor_19140 *anchor = owner->FUN_000592a0();
    Fighter_19140 *fighter = anchor->FUN_00059a30();
    fighter->FUN_000359c0(3);

    if (fighter->timer > 0.0f) {
        float cur = angle;
        float ang = FUN_00224ea0(fighter->velX, fighter->velZ);
        if (params->turnRate < 0.0f) {
            angle = ang;
        } else {
            float diff = FUN_00224fc0(cur, ang);
            float step = dt * params->turnRate;
            if (AbsBits(diff) <= step) {
                angle = ang;
            } else if (diff < 0.0f) {
                angle = cur - step;
            } else {
                angle = step + cur;
            }
        }
    }

    float r = target->xform.FUN_002220d0();
    float want = params->angleOffset + angle;
    if (params->followRate < 0.0f) {
        r = want;
    } else {
        float diff = FUN_00224fc0(r, want);
        float step = dt * params->followRate;
        if (AbsBits(diff) <= step) {
            r = want;
        } else if (diff < 0.0f) {
            r = r - step;
        } else {
            r = step + r;
        }
    }
    target->xform.FUN_00221d20(r);

    double fallNow = fall - dt * params->fallRate;
    fall = (float)fallNow;
    float limit = params->maxFall;
    if (limit <= 0.0f || limit > 200.0f) {
        limit = 200.0f;
    }
    limit = -limit;
    if (fallNow < limit) {
        fall = limit;
    }

    Vec3_19140 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    anchor->FUN_00059a50(&pos);
    pos.y = dt * fall + pos.y;
    target->xform.FUN_0022be40(&pos);
    return true;
}
} // namespace fn_00019140

