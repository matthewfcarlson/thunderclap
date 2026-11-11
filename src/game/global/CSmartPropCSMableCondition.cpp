// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004cb70..0x0004cde0 (kind game, layer game, confidence medium), dominant class CSmartPropCSMableCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f5d3a323 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5d3a323 {} using namespace fn_f5d3a323;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5d3a323 {
class CCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class CSmartPropGrabbableNameCondition : public CCondition {
  public:
    char pad[12];
    CSmartPropGrabbableNameCondition* vfunc_5(int);
};
class CSmartPropCSMableCondition_4cb70 {
  public:
    void Fna_0027af50();
    void Fnb_002345b0();
};
void thunk_FUN_00267090(void*);
extern void* hulk_at_003f6d50[];
class CCondition_4cbb0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropCSMableCondition : public CCondition_4cbb0 {
  public:
    CSmartPropCSMableCondition* vfunc_5(signed char flags);
};


// 0x0004cb70 CSmartPropGrabbableNameCondition::vfunc_5 (52 B): matches/0x0004cb70.cpp
// sym: ?vfunc_5@CSmartPropGrabbableNameCondition@fn_f5d3a323@@QAEPAV12@H@Z
// Same code shape as 0x0004c020 (propagated; names are from that function)
CSmartPropGrabbableNameCondition* CSmartPropGrabbableNameCondition::vfunc_5(int p) {
    CSmartPropGrabbableNameCondition* s = this;
    *(void (**)())s = &vt_name;
    ((CSmartPropCSMableCondition_4cb70*)((char*)s + 0x10))->Fna_0027af50();
    *(void (**)())s = &vt_cond;
    ((CSmartPropCSMableCondition_4cb70*)s)->Fnb_002345b0();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}


// 0x0004cbb0 CSmartPropCSMableCondition::vfunc_5 (36 B): matches/0x0004cbb0.cpp
// sym: ?vfunc_5@CSmartPropCSMableCondition@fn_f5d3a323@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropCSMableCondition* CSmartPropCSMableCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f5d3a323

// 0x0004cbe0 CSmartPropCSMableCondition::vfunc_7 (489 B): equivalent/0x0004cbe0.cpp [wrapped: conflict: CSmartPropCSMableCondition]
// sym: ?vfunc_7@CSmartPropCSMableCondition@fn_0004cbe0@@UAEDPAX@Z
namespace fn_0004cbe0 {
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 19/19)
// CSmartPropCSMableCondition::vfunc_7 @ 0x0004cbe0

struct V3 {
    float x, y, z;
};

struct Mat {
    float m[16];
    void FUN_0022c3b0(const V3 *in, V3 *out);
};


hulk_freg __cdecl FUN_00224ea0(float a, float b);
hulk_freg __cdecl FUN_00224fc0(float a, float b);

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat *v15();
    char pad4[0x40];
    int FUN_001d64a0();
    V3 *FUN_001d6b40();
};

struct Link {
    char pad0[8];
    Node *node;
    int type;
};

struct Fighter {
    void FUN_00059a50(V3 *out);
};

struct Stats {
    char pad0[0x3a4];
    Link *link;
};

Fighter *__fastcall FUN_000592a0(void *owner);
extern "C" Stats *__fastcall FUN_00059a30(Fighter *f);

struct Frame {
    float y;
    V3 w;
    V3 l;
};

class CSmartPropCSMableCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char vfunc_7(void *owner);
    char pad4[8];
    int wantType;
};

char CSmartPropCSMableCondition::vfunc_7(void *owner)
{
    Frame f;
    Fighter *fighter = FUN_000592a0(owner);
    Link *link = FUN_00059a30(fighter)->link;
    if (!link)
        return 0;
    if (link->type != 5)
        return 0;
    Node *node = link->node;
    if (!node)
        return 0;
    int k = node->FUN_001d64a0();
    if (k != wantType)
        return 0;
    switch (k) {
    case 8:
    case 9:
        return 1;
    case 10:
    case 12:
        node->v15()->FUN_0022c3b0(((V3*)&DAT_0048fa24), &f.l);
        f.y = FUN_00224ea0(f.l.x, f.l.z);
        if (k == 10)
            f.y = f.y + 1.57079637f;
        fighter->FUN_00059a50(&f.w);
        {
            V3 *p = node->FUN_001d6b40();
            f.w.x = f.w.x - p->x;
            f.w.y = f.w.y - p->y;
            f.w.z = f.w.z - p->z;
        }
        {
            float a = FUN_00224ea0(f.w.x, f.w.z);
            float d = FUN_00224fc0(f.y, a);
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = d;
            bits.u &= 0x7fffffff;
            if (!(bits.f < 0.785398185f))
                return 0;
        }
        return 1;
    }
    return 0;
}
} // namespace fn_0004cbe0

