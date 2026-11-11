// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c940..0x0004cb70 (kind game, layer game, confidence medium), dominant class CSmartPropDistanceCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f082f618 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f082f618 {} using namespace fn_f082f618;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f082f618 {
struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int hulk_at_003f6d50;
struct V3_4c980 { float x, y, z; };
class Context { public: char pad[4]; };
struct Tgt_4c980 {
    char pad[0x40];
    V3_4c980 pos;
};
struct Ent_4c980 {
    Tgt_4c980* FUN_001d72e0();
};
struct Elem_4c980 {
    char data[64];
    void FUN_0022c2b0(const V3_4c980* in, V3_4c980* out);
};
struct Mgr_4c980 {
    char pad[0x1c];
    Elem_4c980* elems;
    unsigned int FUN_002843a0(int a, int b);
};
struct Owner_4c980 {
    char pad0[0x120];
    Mgr_4c980* mgr;
    char pad1[0x3a4 - 0x124];
    Tgt_4c980* fallback;
    Ent_4c980* FUN_00035ef0(int a);
    void FUN_00035630(const V3_4c980* in, V3_4c980* out);
};
Context* __fastcall FUN_000592a0(void* obj);
extern "C" Owner_4c980* __fastcall FUN_00059a30(Context* ctx);
class CSmartPropDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(void* params);
    char pad04[8];
    unsigned int mode;
    float threshold;
    char pad14[4];
    int f18;
    int f1c;
    V3_4c980 offset;
};


// 0x0004c940 CSmartPropDistanceCondition::vfunc_5 (52 B): matches/0x0004c940.cpp
// sym: ?CSmartPropNameCondition_vfunc_5@fn_f082f618@@YIPAUCSmartPropNameCondition@1@PAU21@PAXE@Z
// Same code shape as 0x0004c720 (propagated; names are from that function)
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = &smart_vftable;
    FUN_0027af50((char*)p + 0x18);
    p->vptr = &hulk_at_003f6d50;
    FUN_002345b0(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}


// 0x0004c980 CSmartPropDistanceCondition::vfunc_7 (471 B): equivalent/0x0004c980.cpp
// sym: ?vfunc_7@CSmartPropDistanceCondition@fn_f082f618@@UAEDPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 24/24)
// CSmartPropDistanceCondition::vfunc_7 @ 0x0004c980
char CSmartPropDistanceCondition::vfunc_7(void* params)
{
    Owner_4c980* owner = FUN_00059a30(FUN_000592a0(params));
    Tgt_4c980* tgt;
    if (owner->FUN_00035ef0(0) != 0 && (tgt = owner->FUN_00035ef0(0)->FUN_001d72e0()) != 0) {
    } else {
        tgt = owner->fallback;
        if (tgt == 0)
            return 0;
    }
    V3_4c980 t = tgt->pos;
    V3_4c980 out;
    out.x = 0.0f;
    out.y = 0.0f;
    out.z = 0.0f;
    if ((f18 | f1c) != 0) {
        owner->FUN_00035630(&offset, &out);
    } else {
        unsigned int idx = owner->mgr->FUN_002843a0(0, 0);
        if (idx == 0xffff)
            return 0;
        owner->mgr->elems[idx].FUN_0022c2b0(&offset, &out);
    }
    float dx = out.x - t.x;
    float dy = out.y - t.y;
    float dz = out.z - t.z;
    float dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    switch (mode) {
    case 0: return dist < threshold;
    case 1: return dist <= threshold;
    case 2: return (char)FUN_00018960(dist, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(dist, threshold, 1e-5f) == 0;
    case 4: return dist >= threshold;
    case 5: return dist > threshold;
    }
    return 0;
}

} // namespace fn_f082f618
