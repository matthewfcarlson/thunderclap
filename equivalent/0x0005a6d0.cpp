// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleKeyPoseTrack::vfunc_12 @ 0x0005a6d0
#include "gen/global.h"

struct Settings;
struct Slot_5a6d0 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5a6d0 {
    char pad00[0x330];
    Slot_5a6d0* primary;
    Slot_5a6d0* secondary;
};
struct Context_5a6d0 {
    Fighter_5a6d0* FUN_00059a30();
};
struct Owner_5a6d0 {
    Context_5a6d0* FUN_000592a0();
};

struct Created_5a6d0 {
    void* FUN_0001d100(CGrappleKeyPoseTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

int CGrappleKeyPoseTrack::vfunc_12(int __p0) { Owner_5a6d0 * owner = (Owner_5a6d0 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5a6d0* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return (int)(0);
    Fighter_5a6d0* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5a6d0* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    Created_5a6d0* c = static_cast<Created_5a6d0*>(FUN_0008d690(0x30));
    if (c == 0)
        return (int)(0);
    return (int)(c->FUN_0001d100(this, settings));
}
