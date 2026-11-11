// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000151a0..0x00015330 (kind game, layer game, confidence medium), dominant class CDrainHealthAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7a61a1c {
#define TREE_TU_END }
namespace fn_f7a61a1c {} using namespace fn_f7a61a1c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7a61a1c {
struct Owner_151a0;
struct Actor_151a0;
struct Context_151a0;
struct Effect_151a0;
struct Name_151a0 {  };
struct Value_151a0 { hulk_freg FUN_002220d0(); void FUN_00221d20(float); };
struct Effect_151a0 { virtual void vfunc_0(); char pad4[4]; Name_151a0 name; char pad9[11]; int mode; Value_151a0 value; Effect_151a0* FUN_002248f0(int); };
struct Actor_151a0 { char pad[16]; Value_151a0 value; void FUN_00222890(Effect_151a0*,float,unsigned int,float,unsigned int,unsigned int,float); };
struct Context_151a0 { Actor_151a0* FUN_00059a40(); };
struct Owner_151a0 {  };
struct Params_151a0 { char pad[44]; unsigned int a,b,c; };
void* __cdecl FUN_00263ea0(unsigned int);
struct R_15270 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_15270* __fastcall FUN_00059a40(void*);

} // namespace fn_f7a61a1c

// 0x000151a0 CAutoTargetAction::vfunc_6 (195 B): equivalent/0x000151a0.cpp
// sym: ?vfunc_6@CAutoTargetAction@@UAE_NH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 4/4)
// CAutoTargetAction::vfunc_6 @ 0x000151a0
bool CAutoTargetAction::vfunc_6(int ) { Actor_151a0* actor=((Context_151a0 *)((owners::Object_592a0 *)((*(Owner_151a0 * *)&this->f_1c)))->FUN_000592a0())->FUN_00059a40(); if(!actor) return false; unsigned int a=(*(Params_151a0 * *)&this->f_20)->a,b=(*(Params_151a0 * *)&this->f_20)->b,c=(*(Params_151a0 * *)&this->f_20)->c; Effect_151a0* e=(Effect_151a0*)FUN_00263ea0(112); if(e) e=e->FUN_002248f0(0); (*(Effect_151a0 * *)&this->f_24)=e; ((owners::Target_27b040 *)&(e->name))->FUN_0027b040((hulk_uintptr)"autoTarget"); (*(Effect_151a0 * *)&this->f_24)->vfunc_0(); float v=actor->value.FUN_002220d0(); (*(Effect_151a0 * *)&this->f_24)->value.FUN_00221d20(v); (*(Effect_151a0 * *)&this->f_24)->mode=2; actor->FUN_00222890((*(Effect_151a0 * *)&this->f_24),-1.0f,a,1.0f,b,c,-1.0f); return true; }


// 0x00015270 CAutoTargetAction::vfunc_4 (37 B): matches/0x00015270.cpp
// sym: ?vfunc_4@CAutoTargetAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CAutoTargetAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_15270* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}


// 0x000152a0 CDrainHealthAction::vfunc_7 (142 B): equivalent/0x000152a0.cpp [wrapped: conflict: CDrainHealthAction]
// sym: ?vfunc_7@CDrainHealthAction@fn_000152a0@@UAE_NTDtArg@2@@Z
namespace fn_000152a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// CDrainHealthAction::vfunc_7 @ 0x000152a0
// The float argument word: its low byte is reused as a flag local, the upper bytes stay stale.
union DtArg {
    float f;
    unsigned char flag;
    unsigned int word;
};

struct Link_152a0 {
    char pad00[0x12c];
    int id;                  // 0x12c
};

struct Fighter_152a0 {
    char pad00[0x12c];
    int id;                  // 0x12c
    char pad130[0x204];
    Link_152a0 *link334;           // 0x334
    Link_152a0 *link338;           // 0x338
    void FUN_00043350(float amount, int source, int zero0, float one, int zero1, unsigned int flagWord);
};

struct Attacker_152a0 {
    char pad00[0x4c];
    int sourceId;            // 0x4c
    char pad50[0x41];
    unsigned char flag91;    // 0x91
};

struct Context {
    Fighter_152a0 *FUN_00059a30();
};

class Combatant {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Attacker_152a0 *GetAttacker();     // slot 3
    Context *FUN_000592a0();
};

class CDrainHealthAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual bool vfunc_7(DtArg dt);
    char pad04[0x18];
    Combatant *combatant;    // 0x1c
    float rate;              // 0x20
};

bool CDrainHealthAction::vfunc_7(DtArg dt) {
    float amount = dt.f * rate;
    Fighter_152a0 *fighter = combatant->FUN_000592a0()->FUN_00059a30();
    int source = 0;
    dt.flag = 0;
    Link_152a0 *link = fighter->link338;
    if (link == 0)
        link = fighter->link334;
    if (link != 0) {
        source = link->id;
    } else {
        Attacker_152a0 *attacker = combatant->GetAttacker();
        if (attacker != 0) {
            source = attacker->sourceId;
            if (source == fighter->id)
                source = 0;
            dt.flag = attacker->flag91;
        }
    }
    fighter->FUN_00043350(amount, source, 0, 1.0f, 0, dt.word);
    return true;
}
} // namespace fn_000152a0

