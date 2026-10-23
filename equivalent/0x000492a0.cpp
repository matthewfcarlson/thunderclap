// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// CSmartPropWeaponizableTypeCondition::vfunc_7 @ 0x000492a0
// CSmartPropWeaponizableTypeCondition::vfunc_7: does the held weapon's type match
#include "gen/global.h"

struct Weapon_492a0 {
    int FUN_001d5dd0(int id);
};

struct Item_492a0 {
    char pad00[0x40];
    int id;
    char pad44[0xec - 0x44];
    Weapon_492a0 *weapon;
};

struct Player_492a0 {
    char FUN_00035f20();
    Item_492a0 *FUN_00035ef0(int slot);
};

struct Anchor_492a0 {
    Player_492a0 *FUN_00059a30();
};

struct Owner_492a0 {
    Anchor_492a0 *FUN_000592a0();
};

bool CSmartPropWeaponizableTypeCondition::vfunc_7(void* __p0) { Owner_492a0 * owner = (Owner_492a0 *)__p0;

    Player_492a0 *p = owner->FUN_000592a0()->FUN_00059a30();
    if (this->f_10 == -1) {
        if (!p->FUN_00035f20())
            return (bool)(0);
        for (int i = 0; i < 8; i++) {
            Item_492a0 *it = p->FUN_00035ef0(i);
            if (it != 0)
                return (bool)(it->weapon->FUN_001d5dd0(it->id) == this->f_0c);
        }
        return (bool)(0);
    }
    Item_492a0 *it = p->FUN_00035ef0(this->f_10);
    if (it == 0)
        return (bool)(0);
    return (bool)(it->weapon->FUN_001d5dd0(it->id) == this->f_0c);
}
