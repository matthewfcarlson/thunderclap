// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 15/16, incomplete)
// CGrappleSoundTrack::vfunc_12 @ 0x0005b5b0
#include "compat/ptr.h"
#include "gen/global.h"

struct Settings;
struct Slot_5b5b0 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5b5b0 {
    char pad00[0x330];
    Slot_5b5b0* primary;
    Slot_5b5b0* secondary;
};
struct Context_5b5b0 {
    Fighter_5b5b0* FUN_00059a30();
};
struct Owner_5b5b0 {
    Context_5b5b0* FUN_000592a0();
};

struct CSoundAction_nv_5b5b0 {
    void* FUN_0001d190(CGrappleSoundTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

int CGrappleSoundTrack::vfunc_12(int __p0) { Owner_5b5b0 * owner = (Owner_5b5b0 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5b5b0* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return (int)(0);
    Fighter_5b5b0* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5b5b0* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    CSoundAction* c = static_cast<CSoundAction*>(FUN_0008d690(0x24));
    if (c == 0)
        return (int)(0);
    return (hulk_intptr)(((CSoundAction_nv_5b5b0*)(c))->FUN_0001d190(this, settings));
}
