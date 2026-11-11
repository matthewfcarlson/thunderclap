// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a590..0x0005a680 (kind game, layer game, confidence medium), dominant class CGrappleDrainHealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f483e0b5 {
#define TREE_TU_END }
namespace fn_f483e0b5 {} using namespace fn_f483e0b5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f483e0b5 {
struct A_5a590 {
};
struct B_5a590 {
    void* second_00059a30();
};
struct Data_5a590 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct Cfg;
struct Effect_5a5e0 {
    Effect_5a5e0 *FUN_0001db40(Cfg *cfg, float rate);
};
struct Opponent {
    char pad00[0x104];
    Cfg *cfg;
};
struct Fighter_5a5e0 {
    char pad00[0x330];
    Opponent *a;
    Opponent *b;
};
struct Player_5a5e0 {
    Fighter_5a5e0 *FUN_00059a30();
};
struct Anchor_5a5e0 {
    Fighter_5a5e0 *FUN_00059a30();
};
struct Owner_5a5e0 {
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

} // namespace fn_f483e0b5

// 0x0005a590 CGrappleDrainHealthTrack::vfunc_11 (70 B): matches/0x0005a590.cpp
// sym: ?vfunc_11@CGrappleDrainHealthTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleDrainHealthTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5a590*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5a590*)a)->second_00059a30();
            if (b) {
                Data_5a590* d = (Data_5a590*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005a5e0 CGrappleDrainHealthTrack::vfunc_12 (155 B): equivalent/0x0005a5e0.cpp
// sym: ?vfunc_12@CGrappleDrainHealthTrack@@UAEHH@Z @b57a254ff63b @w687741c4a523
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 17/18, incomplete)
// CGrappleDrainHealthTrack::vfunc_12 @ 0x0005a5e0
// CGrappleDrainHealthTrack::vfunc_12: spawn the drain effect for the grappled opponent
hulk_intptr CGrappleDrainHealthTrack::vfunc_12(hulk_intptr __p0) { Owner_5a5e0 * owner = (Owner_5a5e0 *)__p0;

    float duration = vfunc_7();
    if (duration <= 0.0f)
        return (int)(0);
    if (owner == 0)
        return (int)(0);
    Anchor_5a5e0 *anchor = ((Anchor_5a5e0 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    if (anchor == 0)
        return (int)(0);
    Fighter_5a5e0 *fighter = anchor->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Opponent *opp = fighter->b;
    if (opp == 0)
        opp = fighter->a;
    if (opp == 0)
        return (int)(0);
    Cfg *cfg = opp->cfg;
    if (cfg == 0)
        return (int)(0);
    float r = this->f_14;
    Effect_5a5e0 *fx = (Effect_5a5e0 *)FUN_0008d690(0x24);
    if (fx == 0)
        return (int)(0);
    return (hulk_intptr)(fx->FUN_0001db40(cfg, r / duration));
}

