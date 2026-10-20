// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 15/16, incomplete)
// CGrappleAutoTargetTrack::vfunc_12 @ 0x0005a790
#include "compat/ptr.h"
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
void* __cdecl FUN_0008d690(hulk_uintptr size);

int CGrappleAutoTargetTrack::vfunc_12(int __p0) { Owner_5a790 * owner = (Owner_5a790 *)__p0;

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
    return (hulk_intptr)(((CAutoTargetAction_nv_5a790*)(c))->FUN_0001d4c0(this, settings));
}
