// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 15/16, incomplete)
// CGrappleSmartPropDropTrack::vfunc_12 @ 0x0005b670
#include "compat/ptr.h"
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

int CGrappleSmartPropDropTrack::vfunc_12(int __p0) { Owner_5b670 * owner = (Owner_5b670 *)__p0;

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
    return (hulk_intptr)(((CSmartPropDropAction_nv_5b670*)(c))->FUN_0001f360(this, settings));
}
