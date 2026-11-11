// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005b670 CGrappleSmartPropDropTrack::vfunc_12 (105 B): equivalent/0x0005b670.cpp [isolated: compile error C2440: 'static_cast' : cannot convert from 'fn_f63372f2::R_5aad0 *' to 'CSmartPropDropAction *'; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleSmartPropDropTrack@@UAEHH@Z @a6257b9b33b9 @w9d4d96e89657
// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 15/16, incomplete)
// CGrappleSmartPropDropTrack::vfunc_12 @ 0x0005b670
#include "gen/global.h"

struct Settings;
struct Slot_5b670 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5b670 {
    char pad00[0x330];
    Slot_5b670* primary;
    Slot_5b670* secondary;
};
struct Context_5b670 {
    Fighter_5b670* FUN_00059a30();
};
struct Owner_5b670 {
    Context_5b670* FUN_000592a0();
};

struct CSmartPropDropAction_nv_5b670 {
    void* FUN_0001f360(CGrappleSmartPropDropTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

hulk_intptr CGrappleSmartPropDropTrack::vfunc_12(hulk_intptr __p0) { Owner_5b670 * owner = (Owner_5b670 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5b670* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return (int)(0);
    Fighter_5b670* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5b670* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    CSmartPropDropAction* c = static_cast<CSmartPropDropAction*>(FUN_0008d690(0x24));
    if (c == 0)
        return (int)(0);
    return (hulk_intptr)(((CSmartPropDropAction_nv_5b670*)(((CSmartPropDropAction*)(c))))->FUN_0001f360(this, settings));
}

