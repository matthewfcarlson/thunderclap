// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleLocoStrafe4Track::vfunc_12 @ 0x0005a960
#include "gen/global.h"

struct Settings;
struct Slot_5a960 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5a960 {
    char pad00[0x330];
    Slot_5a960* primary;
    Slot_5a960* secondary;
};
struct Context_5a960 {
    Fighter_5a960* FUN_00059a30();
};
struct Owner_5a960 {
    Context_5a960* FUN_000592a0();
};

struct CGrappleLocoStrafe4Action_nv_5a960 {
    void* FUN_0001dc40(CGrappleLocoStrafe4Track* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

int CGrappleLocoStrafe4Track::vfunc_12(int __p0) { Owner_5a960 * owner = (Owner_5a960 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5a960* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return (int)(0);
    Fighter_5a960* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5a960* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    CGrappleLocoStrafe4Action* c = static_cast<CGrappleLocoStrafe4Action*>(FUN_0008d690(0x28));
    if (c == 0)
        return (int)(0);
    return (int)(((CGrappleLocoStrafe4Action_nv_5a960*)(c))->FUN_0001dc40(this, settings));
}
