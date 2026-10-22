// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleUninterruptibleTrack::vfunc_12 @ 0x0005b350
void *FUN_0008d690(unsigned int size);

struct Weapon;
struct Fighter_5b350 {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body_5b350 {
    char pad0[0x330];
    Fighter_5b350 *primary;
    Fighter_5b350 *secondary;
};
struct Link2_5b350 {
    Body_5b350 *FUN_00059a30();
};
struct Link1_5b350 {
    Link2_5b350 *FUN_000592a0();
};
struct CUninterruptibleAction_5b350 {
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
    virtual void *vfunc_12(Link1_5b350 *owner);
    char pad04[16];
    int f14;
};

void *CGrappleUninterruptibleTrack::vfunc_12(Link1_5b350 *owner)
{
    if (owner == 0)
        return 0;
    Link2_5b350 *l2 = owner->FUN_000592a0();
    if (l2 == 0)
        return 0;
    Body_5b350 *body = l2->FUN_00059a30();
    if (body == 0)
        return 0;
    Fighter_5b350 *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return 0;
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return 0;
    CUninterruptibleAction_5b350 *effect = (CUninterruptibleAction_5b350 *)FUN_0008d690(0x24);
    if (effect == 0)
        return 0;
    return effect->FUN_00020020(weapon, f14);
}
