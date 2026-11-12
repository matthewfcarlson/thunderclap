// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c660..0x0004c940 (kind game, layer game, confidence medium), dominant class CSmartPropAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff756602 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff756602 {} using namespace fn_ff756602;
namespace fn_ff756602 { extern "C" char DAT_003f6d50[], DAT_003f719c[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff756602 {
extern void* hulk_at_003f6d50[];
class CCondition_4c660 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropAttachedCondition : public CCondition_4c660 {
  public:
    CSmartPropAttachedCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4c690_vftable[];
class CCondition_4c690 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropWeaponizableTypeCondition : public CCondition_4c690 {
  public:
    CSmartPropWeaponizableTypeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4c6c0_vftable[];
class CCondition_4c6c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropWeaponTypeCondition : public CCondition_4c6c0 {
  public:
    CSmartPropWeaponTypeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4c6f0_vftable[];
class CCondition_4c6f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropTypeCondition : public CCondition_4c6f0 {
  public:
    CSmartPropTypeCondition* vfunc_5(signed char flags);
};
struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int condition_vftable_4c720;
extern void* CCondition_4c760_vftable[];
class CCondition_4c760 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropAngleCondition : public CCondition_4c760 {
  public:
    CSmartPropAngleCondition* vfunc_5(signed char flags);
};


// 0x0004c660 CSmartPropAttachedCondition::vfunc_5 (36 B): matches/0x0004c660.cpp
// sym: ?vfunc_5@CSmartPropAttachedCondition@fn_ff756602@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropAttachedCondition* CSmartPropAttachedCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004c690 CSmartPropWeaponizableTypeCondition::vfunc_5 (36 B): matches/0x0004c690.cpp
// sym: ?vfunc_5@CSmartPropWeaponizableTypeCondition@fn_ff756602@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropWeaponizableTypeCondition* CSmartPropWeaponizableTypeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004c6c0 CSmartPropWeaponTypeCondition::vfunc_5 (36 B): matches/0x0004c6c0.cpp
// sym: ?vfunc_5@CSmartPropWeaponTypeCondition@fn_ff756602@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropWeaponTypeCondition* CSmartPropWeaponTypeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004c6f0 CSmartPropTypeCondition::vfunc_5 (36 B): matches/0x0004c6f0.cpp
// sym: ?vfunc_5@CSmartPropTypeCondition@fn_ff756602@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropTypeCondition* CSmartPropTypeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004c720 CSmartPropNameCondition::vfunc_5 (52 B): matches/0x0004c720.cpp
// sym: ?CSmartPropNameCondition_vfunc_5@fn_ff756602@@YIPAUCSmartPropNameCondition@1@PAU21@PAXE@Z
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = ((int*)DAT_003f719c);
    FUN_0027af50((char*)p + 0x18);
    p->vptr = ((int*)DAT_003f6d50);
    FUN_002345b0(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}


// 0x0004c760 CSmartPropAngleCondition::vfunc_5 (36 B): matches/0x0004c760.cpp
// sym: ?vfunc_5@CSmartPropAngleCondition@fn_ff756602@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropAngleCondition* CSmartPropAngleCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_ff756602

// 0x0004c790 FUN_0004c790 (38 B): matches/0x0004c790.cpp
// sym: ?FUN_0004c790@Thing_4c790@owners@@QAE_NM@Z
// data: scale = DAT_003f32b8
bool owners::Thing_4c790::FUN_0004c790(float x) {
    angle = FUN_0004af40(0.0f, 360.0f, x) * DAT_003f32b8;
    return true;
}


// 0x0004c7c0 CSmartPropAngleCondition::vfunc_7 (378 B): equivalent/0x0004c7c0.cpp [wrapped: conflict: CSmartPropAngleCondition]
// sym: ?vfunc_7@CSmartPropAngleCondition@fn_0004c7c0@@UAE_NPAX@Z @1c2034fb16bf @we6289f70d944
namespace fn_0004c7c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 10/10)
// CSmartPropAngleCondition::vfunc_7 @ 0x0004c7c0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fabs(double);
#endif


struct Vec3_4c7c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat3 {
    void FUN_0022c3b0(float* in, Vec3_4c7c0* out);
};

struct Sub_4c7c0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Mat3* v15();
    Vec3_4c7c0* FUN_001d6b40();
};

struct Entity {
    int f00;
    int f04;
    Sub_4c7c0* sub;
    int kind;
};

struct Holder_4c7c0 {
    Entity* FUN_001d72e0();
};

struct Fighter_4c7c0 {
    bool FUN_00059a50(Vec3_4c7c0* out);
};

struct Stats_4c7c0 {
    char pad00[0x3a4];
    Entity* defaultEntity;
    Holder_4c7c0* FUN_00035ef0(int index);
};

Fighter_4c7c0* __fastcall FUN_000592a0(void* owner);
extern "C" Stats_4c7c0* __fastcall FUN_00059a30(Fighter_4c7c0* f);
hulk_freg FUN_00224ea0(float x, float z);
hulk_freg FUN_00224fc0(float a, float b);

class CSmartPropAngleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(void* owner);
    int pad04[2];
    float offset;
    float range;
};

bool CSmartPropAngleCondition::vfunc_7(void* owner)
{
    Fighter_4c7c0* fighter = FUN_000592a0(owner);
    Stats_4c7c0* stats = FUN_00059a30(fighter);
    Entity* e = 0;
    if (stats->FUN_00035ef0(0)) {
        e = stats->FUN_00035ef0(0)->FUN_001d72e0();
    }
    if (!e) {
        e = stats->defaultEntity;
        if (!e)
            return false;
    }
    if (e->kind != 5)
        return false;
    Sub_4c7c0* sub = e->sub;
    struct Frame { Vec3_4c7c0 d; Vec3_4c7c0 v; Vec3_4c7c0 q; Vec3_4c7c0 w; } f;
    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    fighter->FUN_00059a50(&f.v);
    Vec3_4c7c0* p = sub->FUN_001d6b40();
    f.q = *p;
    f.d.x = f.v.x - f.q.x;
    f.d.y = f.v.y - f.q.y;
    f.d.z = f.v.z - f.q.z;
    f.d.FUN_0022d110();
    float a1 = FUN_00224ea0(f.d.x, f.d.z);
    sub->v15()->FUN_0022c3b0(DAT_0048fa24, &f.w);
    float a2 = FUN_00224ea0(f.w.x, f.w.z) + offset;
    float r = FUN_00224fc0(a1, a2);
    return range * 0.5f > (float)fabs(r);
}
} // namespace fn_0004c7c0

