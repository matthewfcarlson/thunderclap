// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00044c60..0x00045820 (kind game, layer game, confidence medium), dominant class pure3d::NonCopyable
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd48bef5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd48bef5 {} using namespace fn_fd48bef5;
namespace fn_fd48bef5 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd48bef5 {
struct Entry {
    int a, b, c, d, e, f;
};
struct Npc {
    char pad0[0x1ca8];
    int v1ca8;
    int v1cac;
    int v1cb0;
    int v1cb4;
    int v1cb8;
    int v1cbc;
    int v1cc0;
    int v1cc4;
    int v1cc8;
    int v1ccc;
    int v1cd0;
    int v1cd4;
    int v1cd8;
    int v1cdc;
    int v1ce0;
    int v1ce4;
    int v1ce8;
    char b1cec, b1ced, b1cee, b1cef;
    int v1cf0;
    char pad1cf4[0x1d40 - 0x1cf4];
    char b1d40;
};
struct ModeB_452e0 {
};
} // namespace fn_fd48bef5
struct World {
    char pad0[0x20];
    ModeB_452e0 *modeB;
};
namespace fn_fd48bef5 {
extern "C" int FUN_00096600(const char *a, const char *b);
class C2_45670 {
  public:
    int Get_0008a2b0();
};
class C1_45670 {
  public:
};
class Mgr_45670 {
  public:
    char pad[0x54];
    C1_45670* m54;
};
extern Mgr_45670* hulk_at_004dd700;
namespace pure3d {
class NonCopyable_45800 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_45800* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_45800*);


// 0x00044c60 FUN_00044c60 (80 B): matches/0x00044c60.cpp
// sym: _FUN_00044c60
// data: gEntries = DAT_004dc360
extern "C" void FUN_00044c60(int index, int a, int b, int c, int d, int e, int f) {
    if (index >= 0 && index < 6) {
        ((Entry*)&DAT_004dc360)[index].a = a;
        ((Entry*)&DAT_004dc360)[index].b = b;
        ((Entry*)&DAT_004dc360)[index].c = c;
        ((Entry*)&DAT_004dc360)[index].d = d;
        ((Entry*)&DAT_004dc360)[index].e = e;
        ((Entry*)&DAT_004dc360)[index].f = f;
    }
}

} // namespace fn_fd48bef5

// 0x00044cb0 FUN_00044cb0 (1581 B): equivalent/0x00044cb0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_00044cb0@fn_00044cb0@@YAXPBD0M@Z @784e101a4592 @wa79313162ef8
namespace fn_00044cb0 {
// STATUS: equivalent (tools/equiv.py level 3: 12141 inputs, branch coverage 120/120)
// FUN_00044cb0 @ 0x00044cb0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char *, const char *);
#endif

int FUN_00096600(const char *a, const char *b);

struct Agent {
    char pad0[0x32c];
    float fDesiredMinEngage;
    float fDesiredMaxEngage;
    float fAbsoluteMinEngage;
    float fAbsoluteMaxEngage;
    float fMaxAttack;
    float fHearingRadius;
    float fNoisiness;
    float fSightRadius;
    float fSightFOV;
    char pad350[0xc];
    float fDodgingSkill;
    float fMinAttackPeriod;
    float fMinTauntPeriod;
    float fMinAttackPause;
    float fMaxAttackPause;
    float fTargetPerceptionLag;
    float fChasePersistenceTime;
    float fSuspiciousTime;
    char fNoGolem;
    char fFightingNPCMode;
    char fSuckInProp;
    char fGroupManaged;
    char pad380[0x4];
    char fIgnoreFriendlyFire;
    char pad385[0x3];
    float fSpeedSleepwalking;
    char fRangedAgent;
    char fHand2HandAgent;
    char fChaseAgent;
    char fPathGraphAgent;
    char fOccupationAgent;
    char pad391[0x1f];
    char nameB[0x40];
    char nameA[0x40];
    char pad430[0x8];
    float fAvoidTolerance;
    float fAvoidRadius;
    char pad440[0x20];
    float fPatrolPathBreakOffHealth;
    float fPatrolPathBreakOffDistance;
    float fPatrolPathBreakOffReset;
};

struct AgentList {
    char pad0[0xc];
    int count;
    Agent **items;
};

struct Middle {
    char pad0[4];
    AgentList *agents;
};

struct Root {
    char pad0[0x20];
    Middle *middle;
};


#define DAT_004dd700 (*(Root * *)&::DAT_004dd700)


// equiv-dead: +0x57 taken, +0x5b taken: the inlined bounds check of items[i] runs with 0 <= i < count (i starts at 0, count is re-read into eax just before the loop compare, nothing changes it before the check)
// Applies one tuning property (key, value) to every agent whose name matches the category.
void FUN_00044cb0(const char *category, const char *key, float value)
{
    if (!category || !*category)
        return;
    if (!key || !*key)
        return;
    AgentList *list = DAT_004dd700->middle->agents;
    for (int i = 0; i < list->count; i++) {
        Agent *a = (i >= 0 && i < list->count) ? list->items[i] : 0;
        if (strcmp(a->nameA, category) != 0 && strcmp(a->nameB, category) != 0)
            continue;
        if (FUN_00096600(key, "DesiredMinEngage") == 0)
            a->fDesiredMinEngage = value;
        else if (FUN_00096600(key, "DesiredMaxEngage") == 0)
            a->fDesiredMaxEngage = value;
        else if (FUN_00096600(key, "AbsoluteMinEngage") == 0)
            a->fAbsoluteMinEngage = value;
        else if (FUN_00096600(key, "AbsoluteMaxEngage") == 0)
            a->fAbsoluteMaxEngage = value;
        else if (FUN_00096600(key, "MaxAttack") == 0)
            a->fMaxAttack = value;
        else if (FUN_00096600(key, "HearingRadius") == 0)
            a->fHearingRadius = value;
        else if (FUN_00096600(key, "Noisiness") == 0)
            a->fNoisiness = value;
        else if (FUN_00096600(key, "SightRadius") == 0)
            a->fSightRadius = value;
        else if (FUN_00096600(key, "AvoidTolerance") == 0)
            a->fAvoidTolerance = value;
        else if (FUN_00096600(key, "AvoidRadius") == 0)
            a->fAvoidRadius = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffHealth") == 0)
            a->fPatrolPathBreakOffHealth = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffDistance") == 0)
            a->fPatrolPathBreakOffDistance = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffReset") == 0)
            a->fPatrolPathBreakOffReset = value;
        else if (FUN_00096600(key, "SightFOV") == 0)
            a->fSightFOV = value;
        else if (FUN_00096600(key, "DodgingSkill") == 0)
            a->fDodgingSkill = value;
        else if (FUN_00096600(key, "MinAttackPeriod") == 0)
            a->fMinAttackPeriod = value;
        else if (FUN_00096600(key, "MinTauntPeriod") == 0)
            a->fMinTauntPeriod = value;
        else if (FUN_00096600(key, "MinAttackPause") == 0)
            a->fMinAttackPause = value;
        else if (FUN_00096600(key, "MaxAttackPause") == 0)
            a->fMaxAttackPause = value;
        else if (FUN_00096600(key, "TargetPerceptionLag") == 0)
            a->fTargetPerceptionLag = value;
        else if (FUN_00096600(key, "ChasePersistenceTime") == 0)
            a->fChasePersistenceTime = value;
        else if (FUN_00096600(key, "SuspiciousTime") == 0)
            a->fSuspiciousTime = value;
        else if (FUN_00096600(key, "NoGolem") == 0)
            a->fNoGolem = !(value <= 0.0f);
        else if (FUN_00096600(key, "FightingNPCMode") == 0)
            a->fFightingNPCMode = !(value <= 0.0f);
        else if (FUN_00096600(key, "SuckInProp") == 0)
            a->fSuckInProp = !(value <= 0.0f);
        else if (FUN_00096600(key, "GroupManaged") == 0)
            a->fGroupManaged = !(value <= 0.0f);
        else if (FUN_00096600(key, "IgnoreFriendlyFire") == 0)
            a->fIgnoreFriendlyFire = !(value <= 0.0f);
        else if (FUN_00096600(key, "SpeedSleepwalking") == 0)
            a->fSpeedSleepwalking = value;
        else if (FUN_00096600(key, "OccupationAgent") == 0)
            a->fOccupationAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "Hand2HandAgent") == 0)
            a->fHand2HandAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "RangedAgent") == 0)
            a->fRangedAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "PathGraphAgent") == 0)
            a->fPathGraphAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "ChaseAgent") == 0)
            a->fChaseAgent = !(value <= 0.0f);
    }
}
} // namespace fn_00044cb0
#undef DAT_004dd700

namespace fn_fd48bef5 {

// 0x000452e0 FUN_000452e0 (912 B): equivalent/0x000452e0.cpp
// sym: _FUN_000452e0 @9d5eefae4e7f @w978c8a1367e2
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 66/66)
// FUN_000452e0 @ 0x000452e0
extern "C" hulk_intptr FUN_000452e0(const char *id, const char *name, int value)
{
    int r = 0;
    if (id == 0 || *id == 0) return (hulk_intptr)id;
    if (name == 0 || *name == 0) return (hulk_intptr)id;
    Npc *npc = ((Npc *)((owners::Obj_259f0 *)(DAT_004dd700->modeB))->FUN_000259f0((hulk_intptr)id));
    if (npc == 0) return 0;
    if ((r = FUN_00096600(name, "DesiredMinEngage")) == 0) {
        npc->v1ca8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "DesiredMaxEngage")) == 0) {
        npc->v1cac = value;
        return value;
    } else if ((r = FUN_00096600(name, "AbsoluteMinEngage")) == 0) {
        npc->v1cb0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "AbsoluteMaxEngage")) == 0) {
        npc->v1cb4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MaxAttack")) == 0) {
        npc->v1cb8 = value;
        return value;
    } else if ((r = FUN_00096600(name, "HearingRadius")) == 0) {
        npc->v1cbc = value;
        return r;
    } else if ((r = FUN_00096600(name, "Noisiness")) == 0) {
        npc->v1cc0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "SightRadius")) == 0) {
        npc->v1cc4 = value;
        return value;
    } else if ((r = FUN_00096600(name, "SightFOV")) == 0) {
        npc->v1cc8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "DodgingSkill")) == 0) {
        npc->v1ccc = value;
        return r;
    } else if ((r = FUN_00096600(name, "MinAttackPeriod")) == 0) {
        npc->v1cd0 = value;
        return value;
    } else if ((r = FUN_00096600(name, "MinTauntPeriod")) == 0) {
        npc->v1cd4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MinAttackPause")) == 0) {
        npc->v1cd8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MaxAttackPause")) == 0) {
        npc->v1cdc = value;
        return value;
    } else if ((r = FUN_00096600(name, "TargetPerceptionLag")) == 0) {
        npc->v1ce0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "ChasePersistenceTime")) == 0) {
        npc->v1ce4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "SuspiciousTime")) == 0) {
        npc->v1ce8 = value;
        return value;
    } else if ((r = FUN_00096600(name, "NoGolem")) == 0) {
        npc->b1cec = !(*(float *)&value <= 0.0f);
        return npc->b1cec;
    } else if ((r = FUN_00096600(name, "FightingNPCMode")) == 0) {
        npc->b1d40 = !(*(float *)&value <= 0.0f);
        return npc->b1d40;
    } else if ((r = FUN_00096600(name, "SuckInProp")) == 0) {
        npc->b1ced = !(*(float *)&value <= 0.0f);
        return npc->b1ced;
    } else if ((r = FUN_00096600(name, "GroupManaged")) == 0) {
        npc->b1cee = !(*(float *)&value <= 0.0f);
        return npc->b1cee;
    } else if ((r = FUN_00096600(name, "IgnoreFriendlyFire")) == 0) {
        npc->b1cef = !(*(float *)&value <= 0.0f);
        return npc->b1cef;
    } else if ((r = FUN_00096600(name, "SpeedSleepwalking")) == 0) {
        npc->v1cf0 = value;
        return r;
    }
    return r;
}

} // namespace fn_fd48bef5

// 0x00045670 FUN_00045670 (107 B): matches/0x00045670.cpp
// sym: ?FUN_00045670@Obj_45670@owners@@QAEMXZ
float owners::Obj_45670::FUN_00045670() {
    float r = DAT_003f32dc;
    Mgr_45670* m = hulk_at_004dd700;
    if (m && m->m54) {
        C2_45670* s = ((C2_45670 *)((owners::C_86310 *)(m->m54))->FUN_00086310());
        if (s) {
            int k = ((C2_45670 *)((owners::C_86310 *)(m->m54))->FUN_00086310())->Get_0008a2b0();
            switch (k) {
            case 0:
                r = f314;
                break;
            case 1:
                r = f318;
                break;
            case 2:
                r = f31c;
                break;
            default:
                r = f318;
                break;
            }
        }
    }
    return r;
}


// 0x000456e0 FUN_000456e0 (8 B): matches/0x000456e0.cpp
// sym: ?FUN_000456e0@Obj_456e0@owners@@QAEEXZ
unsigned char owners::Obj_456e0::FUN_000456e0() {
    return value == 4;
}

namespace fn_fd48bef5 {

// 0x00045800 pure3d::NonCopyable::vfunc_2 (31 B): matches/0x00045800.cpp
// sym: ?f2@NonCopyable_45800@pure3d@fn_fd48bef5@@UAEPAV123@E@Z
pure3d::NonCopyable_45800* pure3d::NonCopyable_45800::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fd48bef5
