// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// CSmartPropWeaponizableTypeCondition::vfunc_7 @ 0x000492a0
// CSmartPropWeaponizableTypeCondition::vfunc_7: does the held weapon's type match
struct Weapon {
    int FUN_001d5dd0(int id);
};

struct Item {
    char pad00[0x40];
    int id;
    char pad44[0xec - 0x44];
    Weapon *weapon;
};

struct Player {
    char FUN_00035f20();
    Item *FUN_00035ef0(int slot);
};

struct Anchor {
    Player *FUN_00059a30();
};

struct Owner {
    Anchor *FUN_000592a0();
};

class CSmartPropWeaponizableTypeCondition {
public:
    int pad00;
    int pad04;
    int pad08;
    int wantedType;
    int slot;

    char Check(Owner *owner);
};

char CSmartPropWeaponizableTypeCondition::Check(Owner *owner)
{
    Player *p = owner->FUN_000592a0()->FUN_00059a30();
    if (slot == -1) {
        if (!p->FUN_00035f20())
            return 0;
        for (int i = 0; i < 8; i++) {
            Item *it = p->FUN_00035ef0(i);
            if (it != 0)
                return it->weapon->FUN_001d5dd0(it->id) == wantedType;
        }
        return 0;
    }
    Item *it = p->FUN_00035ef0(slot);
    if (it == 0)
        return 0;
    return it->weapon->FUN_001d5dd0(it->id) == wantedType;
}
