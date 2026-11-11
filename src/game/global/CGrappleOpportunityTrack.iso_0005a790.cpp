// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005a790 CGrappleAutoTargetTrack::vfunc_12 (105 B): equivalent/0x0005a790.cpp [isolated: compile error C2440: 'static_cast' : cannot convert from 'fn_f63372f2::R_5aad0 *' to 'CAutoTargetAction *'; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleAutoTargetTrack@@UAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 15/16, incomplete)
// CGrappleAutoTargetTrack::vfunc_12 @ 0x0005a790
#include "gen/global.h"

struct Settings;
struct Slot_5a790 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5a790 {
    char pad00[0x330];
    Slot_5a790* primary;
    Slot_5a790* secondary;
};
struct Context_5a790 {
    Fighter_5a790* FUN_00059a30();
};
struct Owner_5a790 {
    Context_5a790* FUN_000592a0();
};

struct CAutoTargetAction_nv_5a790 {
    void* FUN_0001d4c0(CGrappleAutoTargetTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

hulk_intptr CGrappleAutoTargetTrack::vfunc_12(hulk_intptr __p0) { Owner_5a790 * owner = (Owner_5a790 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5a790* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return (int)(0);
    Fighter_5a790* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5a790* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    CAutoTargetAction* c = static_cast<CAutoTargetAction*>(FUN_0008d690(0x30));
    if (c == 0)
        return (int)(0);
    return (hulk_intptr)(((CAutoTargetAction_nv_5a790*)(((CAutoTargetAction*)(c))))->FUN_0001d4c0(this, settings));
}

