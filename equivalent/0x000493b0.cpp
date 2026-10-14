// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// CSmartPropWeaponTypeCondition::vfunc_7 @ 0x000493b0
// CSmartPropWeaponTypeCondition::vfunc_7: does the held weapon's type match
struct Weapon_493b0 {
    int FUN_001d5e80(int id);
};

struct Item_493b0 {
    char pad00[0x40];
    int id;
    char pad44[0xec - 0x44];
    Weapon_493b0 *weapon;
};

struct Player_493b0 {
    char FUN_00035f20();
    Item_493b0 *FUN_00035ef0(int slot);
};

struct Anchor_493b0 {
    Player_493b0 *FUN_00059a30();
};

struct Owner_493b0 {
    Anchor_493b0 *FUN_000592a0();
};

class CSmartPropWeaponTypeCondition {
public:
    int pad00;
    int pad04;
    int pad08;
    int wantedType;
    int slot;

    char Check(Owner_493b0 *owner);
};

char CSmartPropWeaponTypeCondition::Check(Owner_493b0 *owner)
{
    Player_493b0 *p = owner->FUN_000592a0()->FUN_00059a30();
    if (slot == -1) {
        if (!p->FUN_00035f20())
            return 0;
        for (int i = 0; i < 8; i++) {
            Item_493b0 *it = p->FUN_00035ef0(i);
            if (it != 0)
                return it->weapon->FUN_001d5e80(it->id) == wantedType;
        }
        return 0;
    }
    Item_493b0 *it = p->FUN_00035ef0(slot);
    if (it == 0)
        return 0;
    return it->weapon->FUN_001d5e80(it->id) == wantedType;
}
