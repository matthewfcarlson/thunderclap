// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049340..0x00049450 (kind game, layer game, confidence medium), dominant class CSmartPropWeaponTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4a687b6 {
#define TREE_TU_END }
namespace fn_f4a687b6 {} using namespace fn_f4a687b6;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4a687b6 {
extern int* gTable_49360;
class CCondition_49360 {
  public:
    virtual int vfunc_0(int);
};
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
};
struct Anchor_493b0 {
    Player_493b0 *FUN_00059a30();
};
struct Owner_493b0 {
};


// 0x00049340 FUN_00049340 (19 B): matches/0x00049340.cpp
// sym: ?FUN_00049340@fn_f4a687b6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049340() {
    FUN_00234810(((char*)&DAT_004dc4b0), ((char*)&DAT_004dc4b4));
}

} // namespace fn_f4a687b6

// 0x00049360 CSmartPropWeaponTypeCondition::vfunc_0 (16 B): matches/0x00049360.cpp
// sym: ?vfunc_0@CSmartPropWeaponTypeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropWeaponTypeCondition::vfunc_0(int index) {
    int* p = gTable_49360;
    return p[index];
}


// 0x000493b0 CSmartPropWeaponTypeCondition::vfunc_7 (155 B): equivalent/0x000493b0.cpp
// sym: ?vfunc_7@CSmartPropWeaponTypeCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// CSmartPropWeaponTypeCondition::vfunc_7 @ 0x000493b0
// CSmartPropWeaponTypeCondition::vfunc_7: does the held weapon's type match
bool CSmartPropWeaponTypeCondition::vfunc_7(void* __p0) { Owner_493b0 * owner = (Owner_493b0 *)__p0;

    Player_493b0 *p = ((Anchor_493b0 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    if (this->f_10 == -1) {
        if (!p->FUN_00035f20())
            return (bool)(0);
        for (int i = 0; i < 8; i++) {
            Item_493b0 *it = ((Item_493b0 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)i));
            if (it != 0)
                return (bool)(it->weapon->FUN_001d5e80(it->id) == this->f_0c);
        }
        return (bool)(0);
    }
    Item_493b0 *it = ((Item_493b0 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)(this->f_10)));
    if (it == 0)
        return (bool)(0);
    return (bool)(it->weapon->FUN_001d5e80(it->id) == this->f_0c);
}

