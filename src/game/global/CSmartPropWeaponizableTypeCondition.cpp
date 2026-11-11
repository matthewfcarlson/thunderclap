// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049230..0x00049340 (kind game, layer game, confidence medium), dominant class CSmartPropWeaponizableTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0adbe6c {
#define TREE_TU_END }
namespace fn_f0adbe6c {} using namespace fn_f0adbe6c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0adbe6c {
extern int* gTable_49250;
class CCondition_49250 {
  public:
    virtual int vfunc_0(int);
};
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
};
struct Anchor_492a0 {
    Player_492a0 *FUN_00059a30();
};
struct Owner_492a0 {
};


// 0x00049230 FUN_00049230 (19 B): matches/0x00049230.cpp
// sym: ?FUN_00049230@fn_f0adbe6c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049230() {
    FUN_00234810(((char*)&DAT_004dc4a8), ((char*)&DAT_004dc4ac));
}

} // namespace fn_f0adbe6c

// 0x00049250 CSmartPropWeaponizableTypeCondition::vfunc_0 (16 B): matches/0x00049250.cpp
// sym: ?vfunc_0@CSmartPropWeaponizableTypeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropWeaponizableTypeCondition::vfunc_0(int index) {
    int* p = gTable_49250;
    return p[index];
}


// 0x000492a0 CSmartPropWeaponizableTypeCondition::vfunc_7 (155 B): equivalent/0x000492a0.cpp
// sym: ?vfunc_7@CSmartPropWeaponizableTypeCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// CSmartPropWeaponizableTypeCondition::vfunc_7 @ 0x000492a0
// CSmartPropWeaponizableTypeCondition::vfunc_7: does the held weapon's type match
bool CSmartPropWeaponizableTypeCondition::vfunc_7(void* __p0) { Owner_492a0 * owner = (Owner_492a0 *)__p0;

    Player_492a0 *p = ((Anchor_492a0 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    if (this->f_10 == -1) {
        if (!p->FUN_00035f20())
            return (bool)(0);
        for (int i = 0; i < 8; i++) {
            Item_492a0 *it = ((Item_492a0 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)i));
            if (it != 0)
                return (bool)(it->weapon->FUN_001d5dd0(it->id) == this->f_0c);
        }
        return (bool)(0);
    }
    Item_492a0 *it = ((Item_492a0 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)(this->f_10)));
    if (it == 0)
        return (bool)(0);
    return (bool)(it->weapon->FUN_001d5dd0(it->id) == this->f_0c);
}

