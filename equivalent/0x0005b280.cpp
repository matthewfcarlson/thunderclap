// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleInvincibleTrack::vfunc_12 @ 0x0005b280
#include "compat/ptr.h"
#include "gen/global.h"

void *FUN_0008d690(unsigned int size);

struct Weapon;
struct Fighter_5b280 {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body_5b280 {
    char pad0[0x330];
    Fighter_5b280 *primary;
    Fighter_5b280 *secondary;
};
struct Link2_5b280 {
    Body_5b280 *FUN_00059a30();
};
struct Link1_5b280 {
    Link2_5b280 *FUN_000592a0();
};
struct CInvincibleAction_5b280 {
    void *FUN_0001f4e0(Weapon *weapon, int value);
};

hulk_intptr CGrappleInvincibleTrack::vfunc_12(hulk_intptr __p0) { Link1_5b280 * owner = (Link1_5b280 *)__p0;

    if (owner == 0)
        return (int)(0);
    Link2_5b280 *l2 = owner->FUN_000592a0();
    if (l2 == 0)
        return (int)(0);
    Body_5b280 *body = l2->FUN_00059a30();
    if (body == 0)
        return (int)(0);
    Fighter_5b280 *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return (int)(0);
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return (int)(0);
    CInvincibleAction_5b280 *effect = (CInvincibleAction_5b280 *)FUN_0008d690(0x24);
    if (effect == 0)
        return (int)(0);
    return (hulk_intptr)(effect->FUN_0001f4e0(weapon, this->f_14));
}
