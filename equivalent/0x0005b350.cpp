// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleUninterruptibleTrack::vfunc_12 @ 0x0005b350
void *FUN_0008d690(unsigned int size);

struct Weapon;
struct Fighter {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body {
    char pad0[0x330];
    Fighter *primary;
    Fighter *secondary;
};
struct Link2 {
    Body *FUN_00059a30();
};
struct Link1 {
    Link2 *FUN_000592a0();
};
struct Effect {
    void *FUN_00020020(Weapon *weapon, int value);
};

class CGrappleUninterruptibleTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void *vfunc_12(Link1 *owner);
    char pad04[16];
    int f14;
};

void *CGrappleUninterruptibleTrack::vfunc_12(Link1 *owner)
{
    if (owner == 0)
        return 0;
    Link2 *l2 = owner->FUN_000592a0();
    if (l2 == 0)
        return 0;
    Body *body = l2->FUN_00059a30();
    if (body == 0)
        return 0;
    Fighter *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return 0;
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return 0;
    Effect *effect = (Effect *)FUN_0008d690(0x24);
    if (effect == 0)
        return 0;
    return effect->FUN_00020020(weapon, f14);
}
