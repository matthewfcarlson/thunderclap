// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004be00..0x0004bf40 (kind game, layer game, confidence medium), dominant class CCollisionDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f777b6f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f777b6f1 {} using namespace fn_f777b6f1;
namespace fn_f777b6f1 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f777b6f1 { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f777b6f1 {
extern void* hulk_at_003f6d50[];
class CCondition_4be00 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCharacterSizeCondition : public CCondition_4be00 {
  public:
    CCharacterSizeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4be30_vftable[];
class CCondition_4be30 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionHitLocationCondition : public CCondition_4be30 {
  public:
    CCollisionHitLocationCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4be60_vftable[];
class CCondition_4be60 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionDirectionCondition : public CCondition_4be60 {
  public:
    CCollisionDirectionCondition* vfunc_5(signed char flags);
};


// 0x0004be00 CCharacterSizeCondition::vfunc_5 (36 B): matches/0x0004be00.cpp
// sym: ?vfunc_5@CCharacterSizeCondition@fn_f777b6f1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCharacterSizeCondition* CCharacterSizeCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004be30 CCollisionHitLocationCondition::vfunc_5 (36 B): matches/0x0004be30.cpp
// sym: ?vfunc_5@CCollisionHitLocationCondition@fn_f777b6f1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionHitLocationCondition* CCollisionHitLocationCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004be60 CCollisionDirectionCondition::vfunc_5 (36 B): matches/0x0004be60.cpp
// sym: ?vfunc_5@CCollisionDirectionCondition@fn_f777b6f1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionDirectionCondition* CCollisionDirectionCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f777b6f1

// 0x0004be90 CCollisionDirectionCondition::vfunc_7 (167 B): equivalent/0x0004be90.cpp [wrapped: conflict: CCollisionDirectionCondition]
// sym: ?vfunc_7@CCollisionDirectionCondition@fn_0004be90@@UAE_NPAUContext@2@@Z @74520406a8a0 @wad8008d479d1
namespace fn_0004be90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CCollisionDirectionCondition::vfunc_7 @ 0x0004be90
struct Actor_4be90 { hulk_freg FUN_000354c0(); };
struct Context2_4be90 { Actor_4be90* FUN_00059a30(); };
struct Collision_4be90 { char pad[0x18]; float x; float y; float z; };
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual Collision_4be90* v3(); Context2_4be90* FUN_000592a0(); };
hulk_freg __cdecl FUN_00224ea0(float,float);
hulk_freg __cdecl FUN_00224fc0(float,float);
struct CCollisionDirectionCondition {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual bool vfunc_7(Context*);
 char pad[8]; float offset; float range;
};
bool CCollisionDirectionCondition::vfunc_7(Context* context) {
 Actor_4be90* actor = context->FUN_000592a0()->FUN_00059a30();
 Collision_4be90* collision = context->v3();
 if (!collision) return false;
 actor->FUN_000354c0();
 float direction = FUN_00224ea0(collision->x,collision->z);
 float heading = actor->FUN_000354c0() + offset;
 float delta = FUN_00224fc0(direction,heading);
 union { float f; unsigned int u; } absolute;
 absolute.f=delta; absolute.u &= 0x7fffffff;
 return range*0.5f > absolute.f;
}
} // namespace fn_0004be90

