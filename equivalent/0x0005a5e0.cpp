// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 17/18, incomplete)
// CGrappleDrainHealthTrack::vfunc_12 @ 0x0005a5e0
// CGrappleDrainHealthTrack::vfunc_12: spawn the drain effect for the grappled opponent
struct Cfg;

struct Effect {
    Effect *FUN_0001db40(Cfg *cfg, float rate);
};

struct Opponent {
    char pad00[0x104];
    Cfg *cfg;
};

struct Fighter {
    char pad00[0x330];
    Opponent *a;
    Opponent *b;
};

struct Player {
    Fighter *FUN_00059a30();
};

struct Anchor {
    Fighter *FUN_00059a30();
};

struct Owner {
    Anchor *FUN_000592a0();
};

void *__cdecl FUN_0008d690(unsigned int size);

class CGrappleDrainHealthTrack {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Duration();
    char pad04[0x10];
    float rate;

    Effect *FUN_0005a5e0(Owner *owner);
};

Effect *CGrappleDrainHealthTrack::FUN_0005a5e0(Owner *owner)
{
    float duration = Duration();
    if (duration <= 0.0f)
        return 0;
    if (owner == 0)
        return 0;
    Anchor *anchor = owner->FUN_000592a0();
    if (anchor == 0)
        return 0;
    Fighter *fighter = anchor->FUN_00059a30();
    if (fighter == 0)
        return 0;
    Opponent *opp = fighter->b;
    if (opp == 0)
        opp = fighter->a;
    if (opp == 0)
        return 0;
    Cfg *cfg = opp->cfg;
    if (cfg == 0)
        return 0;
    float r = rate;
    Effect *fx = (Effect *)FUN_0008d690(0x24);
    if (fx == 0)
        return 0;
    return fx->FUN_0001db40(cfg, r / duration);
}
