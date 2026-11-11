// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017020..0x00017370 (kind game, layer game, confidence high), dominant class CJumpAttackAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffcfe266 {
#define TREE_TU_END }
namespace fn_ffcfe266 {} using namespace fn_ffcfe266;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffcfe266 {
struct Manager_17020 {
    void Fnf_00099d00(void* g, void* b, int v);
};
struct Global_17020 {
    char pad[8];
    Manager_17020* manager;
};
extern Global_17020* hulk_at_004dd700;
struct H1 {
    void* Fnf_000592a0();
};
struct H2_17020 {
    void* Fnf_00059a30();
};
struct X_17020 {
    char pad[0x14];
    int value;
};
struct V3_17050 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct NameField_17050 {
};
struct TrackerSub_17050;
struct Sub18_17050 {
    void FUN_00221be0(TrackerSub_17050 *sub);
    void FUN_00221d20(float a);
};
class JointDriver_17050 {
public:
    virtual void v0();
    char pad4[4];
    NameField_17050 name;
    char pad1[0x18 - 0x9];
    Sub18_17050 s18;
    char pad2[0x70 - 0x19];
    JointDriver_17050 *FUN_002248f0(int a);
};
struct Aimed_17050 {
};
struct TrackerSub_17050 {
    Aimed_17050 *FUN_00221c40();
};
struct Tracker_17050 {
    char pad0[0x10];
    TrackerSub_17050 sub;
    void FUN_00222890(JointDriver_17050 *o, float a, float b, float c, float d, float e, float f);
};
struct Target_17050 {
};
struct Player_17050 {
    char pad0[0x328];
    Target_17050 *target;
    void FUN_000350c0(V3_17050 *out);
    void FUN_0003a520(V3_17050 *out, V3_17050 *dir, int a, int b);
    void FUN_000400e0(V3_17050 *out, V3_17050 *dir, int a, int b, unsigned flags);
};
struct Mgr_17050 {
    Player_17050 *FUN_00059a30();
    Tracker_17050 *FUN_00059a40();
};
struct Holder_17050 {
};
struct Cfg_17050 {
    char pad0[0x14];
    V3_17050 f14;
    int f20;
    int f24;
    char pad28[4];
    float f2c;
    float f30;
    float f34;
};
void *FUN_00263ea0(unsigned int);
extern "C" void __cdecl FUN_00096a90(Target_17050 *t, V3_17050 *v);
hulk_freg __cdecl FUN_00224ea0(float a, float b);
struct R_17340 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_17340* __fastcall FUN_00059a40(void*);

} // namespace fn_ffcfe266

// 0x00017020 CCameraHintAction::vfunc_8 (46 B): matches/0x00017020.cpp
// sym: ?vfunc_8@CCameraHintAction@@UAE_NH@Z
bool CCameraHintAction::vfunc_8(int ) {
    void* b = ((H2_17020*)(*(H1 * *)&this->f_1c)->Fnf_000592a0())->Fnf_00059a30();
    hulk_at_004dd700->manager->Fnf_00099d00(hulk_at_004dd700, b, (*(X_17020 * *)&this->f_20)->value);
    return true;
}


// 0x00017050 CJumpAttackAction::vfunc_6 (535 B): equivalent/0x00017050.cpp
// sym: ?vfunc_6@CJumpAttackAction@@UAE_NH@Z @620fd97defc6 @wc2bd1a6cb40b
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// CJumpAttackAction::vfunc_6 @ 0x00017050
bool CJumpAttackAction::vfunc_6(int arg) {
    struct Frame {
        float c[3];
        V3_17050 w;
        V3_17050 l;
    } fr;
    Mgr_17050 *mgr = ((Mgr_17050 *)((owners::Object_592a0 *)((*(Holder_17050 * *)&this->f_1c)))->FUN_000592a0());
    Player_17050 *pl = mgr->FUN_00059a30();
    Tracker_17050 *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg_17050 *c0 = (*(Cfg_17050 * *)&this->f_20);
    fr.c[2] = c0->f2c;
    fr.c[1] = c0->f30;
    fr.c[0] = c0->f34;
    void *mem = FUN_00263ea0(0x70);
    JointDriver_17050 *o = 0;
    if (mem)
        o = ((JointDriver_17050 *)mem)->FUN_002248f0(0);
    (*(JointDriver_17050 * *)&this->f_24) = o;
    ((owners::Target_27b040 *)&(o->name))->FUN_0027b040((hulk_uintptr)"jumpAttack");
    (*(JointDriver_17050 * *)&this->f_24)->v0();
    TrackerSub_17050 *sub = &tr->sub;
    (*(JointDriver_17050 * *)&this->f_24)->s18.FUN_00221be0(sub);
    tr->FUN_00222890((*(JointDriver_17050 * *)&this->f_24), -1.0f, fr.c[2], 1.0f, fr.c[1], fr.c[0], -1.0f);

    fr.l = (*(Cfg_17050 * *)&this->f_20)->f14;
    ((owners::M_22c3b0 *)(sub->FUN_00221c40()))->FUN_0022c3b0((float *)(V3_17050 *)(&fr.l), (float *)(V3_17050 *)(&(*(V3_17050 *)&this->f_28)));
    (*(V3_17050 *)&this->f_28).FUN_0022d110();

    fr.w.x = 0.0f;
    fr.w.y = 0.0f;
    fr.w.z = 0.0f;
    pl->FUN_000350c0(&fr.w);
    if (pl->target != 0)
        pl->FUN_0003a520(&fr.w, &(*(V3_17050 *)&this->f_28), (*(Cfg_17050 * *)&this->f_20)->f20, (*(Cfg_17050 * *)&this->f_20)->f24);
    else
        pl->FUN_000400e0(&fr.w, &(*(V3_17050 *)&this->f_28), (*(Cfg_17050 * *)&this->f_20)->f20, (*(Cfg_17050 * *)&this->f_20)->f24, 0x80000000);

    Target_17050 *t = pl->target;
    if (t != 0) {
        FUN_00096a90(t, &(*(V3_17050 *)&this->f_28));
        (*(V3_17050 *)&this->f_28).x = (*(V3_17050 *)&this->f_28).x - fr.w.x;
        (*(V3_17050 *)&this->f_28).y = (*(V3_17050 *)&this->f_28).y - fr.w.y;
        (*(V3_17050 *)&this->f_28).z = (*(V3_17050 *)&this->f_28).z - fr.w.z;
        (*(V3_17050 *)&this->f_28).FUN_0022d110();
    }

    if ((*(V3_17050 *)&this->f_28).y >= -0.1f) {
        fr.l = (*(Cfg_17050 * *)&this->f_20)->f14;
        ((owners::M_22c3b0 *)(sub->FUN_00221c40()))->FUN_0022c3b0((float *)(V3_17050 *)(&fr.l), (float *)(V3_17050 *)(&(*(V3_17050 *)&this->f_28)));
        (*(V3_17050 *)&this->f_28).FUN_0022d110();
        if ((*(V3_17050 *)&this->f_28).y >= -0.1f) {
            (*(V3_17050 *)&this->f_28).y = -0.1f;
            (*(V3_17050 *)&this->f_28).FUN_0022d110();
        }
    }

    float ang = FUN_00224ea0((*(V3_17050 *)&this->f_28).x, (*(V3_17050 *)&this->f_28).z);
    (*(JointDriver_17050 * *)&this->f_24)->s18.FUN_00221d20(ang);
    return true;
}


// 0x00017270 CJumpAttackAction::vfunc_7 (208 B): equivalent/0x00017270.cpp [wrapped: conflict: CJumpAttackAction]
// sym: ?vfunc_7@CJumpAttackAction@fn_00017270@@QAE_NM@Z @192b1500b0ce @w3da1be19b835
namespace fn_00017270 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// CJumpAttackAction::vfunc_7 @ 0x00017270
struct Vec_17270 { float x,y,z; void FUN_0022be40(const Vec_17270*); };
struct Mode_17270 { void FUN_000359c0(int); };
struct Actor_17270 { Mode_17270* FUN_00059a30(); void FUN_00059a50(Vec_17270*); };
struct Owner_17270 { Actor_17270* FUN_000592a0(); };
struct Speed_17270 { char pad[0x28]; float value; };
struct Destination_17270 { char pad[0x18]; Vec_17270 position; };
struct CJumpAttackAction {
 char pad[0x1c]; Owner_17270* owner; Speed_17270* speed; Destination_17270* destination; Vec_17270 velocity;
 bool vfunc_7(float dt);
};
bool CJumpAttackAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor_17270* actor=owner->FUN_000592a0();
 actor->FUN_00059a30()->FUN_000359c0(3);
 Vec_17270 position; position.x=0; position.y=0; position.z=0;
 actor->FUN_00059a50(&position);
 double scale=(double)dt*speed->value;
 volatile float y=(float)(velocity.y*scale); // rounded copies in the original's velocity temporary
 volatile float z=(float)(velocity.z*scale);
 position.x=(float)(position.x+velocity.x*scale);
 position.y+=y; position.z+=z;
 destination->position.FUN_0022be40(&position);
 return true;
}
} // namespace fn_00017270


// 0x00017340 CJumpAttackAction::vfunc_4 (37 B): matches/0x00017340.cpp
// sym: ?vfunc_4@CJumpAttackAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CJumpAttackAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_17340* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}

