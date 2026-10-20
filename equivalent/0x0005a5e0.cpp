// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 17/18, incomplete)
// CGrappleDrainHealthTrack::vfunc_12 @ 0x0005a5e0
// CGrappleDrainHealthTrack::vfunc_12: spawn the drain effect for the grappled opponent
#include "compat/ptr.h"
#include "gen/global.h"

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
    Anchor_5a5e0 *FUN_000592a0();
};

void *__cdecl FUN_0008d690(unsigned int size);

int CGrappleDrainHealthTrack::vfunc_12(int __p0) { Owner_5a5e0 * owner = (Owner_5a5e0 *)__p0;

    float duration = vfunc_7();
    if (duration <= 0.0f)
        return (int)(0);
    if (owner == 0)
        return (int)(0);
    Anchor_5a5e0 *anchor = owner->FUN_000592a0();
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
