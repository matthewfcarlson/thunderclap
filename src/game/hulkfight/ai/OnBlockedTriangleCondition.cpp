// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d930..0x0010db80 (kind game, layer game, confidence medium), dominant class hulkfight::ai::OnBlockedTriangleCondition
#include "tree_prelude.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb44886a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb44886a {} using namespace fn_fb44886a;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fb44886a {
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
struct Fighter_10d930 {
    char pad00[0x1d40];
    char flag;            // 0x1d40
};
struct Body_10d930 {
    Fighter_10d930* FUN_00059a30();
};
class Target_10d930 {
public:
    Body_10d930* FUN_000592a0();
};
namespace hulkfight { namespace ai {
class FightingOtherNPCCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(void* a1, Target_10d930* target, void* a3);

    char pad04[8];
    unsigned int mode;     // 0x0c
};
} }
struct Vec3_10d9c0 {
    float x, y, z;
};
struct Body_10d9c0 {
    char pad00[0x40];
    Vec3_10d9c0 pos;
};
struct Locator {
    char FUN_00059a50(Vec3_10d9c0 *out);
};
struct Res_10d9c0 {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body_10d9c0 *body;
};
struct Resolver_10d9c0 {
    Res_10d9c0 *FUN_00059a30();
};
struct Target_10d9c0 {
};
struct Hit_10d9c0 {
    char pad00[0x16];
    unsigned short info;
};
struct Slot_10d9c0 {
};
struct Mgr_10d9c0 {
    void FUN_001dcf60(int a);
};
} // namespace fn_fb44886a
struct World {
    char pad00[0xc];
    Mgr_10d9c0 *mgr;
    char pad10[0x20 - 0x10];
    Slot_10d9c0 *slot;
};
namespace fn_fb44886a {
extern "C" char __cdecl FUN_00202560(Vec3_10d9c0 *from, float dist, int flag, Vec3_10d9c0 *outA, Vec3_10d9c0 *outB, int p6, int p7, Hit_10d9c0 **outHit);
class OnBlockedTriangleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, void *obj, int c);
    char pad04[8];
    int op;
    char useBody;
    char pad11[3];
    unsigned short value;
};


// 0x0010d930 hulkfight::ai::FightingOtherNPCCondition::vfunc_6 (106 B): equivalent/0x0010d930.cpp
// sym: ?vfunc_6@FightingOtherNPCCondition@ai@hulkfight@fn_fb44886a@@UAEDPAXPAVTarget_10d930@4@0@Z @2ae62f6e879f @wf22bf9e480ea
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// hulkfight::ai::FightingOtherNPCCondition::vfunc_6 @ 0x0010d930
char hulkfight::ai::FightingOtherNPCCondition::vfunc_6(void* a1, Target_10d930* target, void* a3)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Fighter_10d930* fighter = target->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return 0;
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
        return fighter->flag;
    case 3:
        return fighter->flag == 0;
    }
    return 0;
}


// 0x0010d9c0 hulkfight::ai::OnBlockedTriangleCondition::vfunc_6 (417 B): equivalent/0x0010d9c0.cpp
// sym: ?vfunc_6@OnBlockedTriangleCondition@fn_fb44886a@@UAEDHPAXH@Z @6eefd52ba9f5 @w20cd0835429a
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 24/24)
// hulkfight::ai::OnBlockedTriangleCondition::vfunc_6 @ 0x0010d9c0
char OnBlockedTriangleCondition::vfunc_6(int a, void *obj, int c)
{
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res_10d9c0 *r = ((Resolver_10d9c0 *)((owners::Object_592a0 *)(((Target_10d9c0 *)obj)))->FUN_000592a0())->FUN_00059a30();
    if (!r)
        return 0;
    Vec3_10d9c0 pos;
    if (!useBody) {
        r->loc->FUN_00059a50(&pos);
    } else {
        Body_10d9c0 *body = r->body;
        if (!body)
            return 0;
        pos = body->pos;
    }
    Hit_10d9c0 *hit = 0;
    ((owners::C_25260 *)(DAT_004dd700->slot))->FUN_00025260(0, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(0);
    pos.y = pos.y + 5.0f;
    Vec3_10d9c0 outB;
    Vec3_10d9c0 outA;
    char found = FUN_00202560(&pos, 20.0f, 1, &outA, &outB, 0, 0, &hit);
    ((owners::C_25260 *)(DAT_004dd700->slot))->FUN_00025260(1, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(1);
    if (!found || !hit)
        return 1;
    unsigned short got = (unsigned short)(hit->info >> 13);
    unsigned short want = value;
    switch (op) {
    case 0: return got < want;
    case 1: return got <= want;
    case 2: return got == want;
    case 3: return got != want;
    case 4: return got >= want;
    case 5: return got > want;
    }
    return 0;
}

} // namespace fn_fb44886a
