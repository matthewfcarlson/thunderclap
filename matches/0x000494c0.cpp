// CSmartPropTypeCondition::vfunc_7 @ 0x000494c0
#include "gen/global.h"

struct Pad_494c0;

struct Item_494c0 {
    char pad00[8];
    struct Holder_494c0 *holder;  // 0x8
    int kind;               // 0xc
};

struct Holder_494c0 {
    int FUN_001d64a0();
};

struct Pad_494c0 {
    Item_494c0 *FUN_001d72e0();
};

struct Player_494c0 {
    char pad00[0x3a4];
    Item_494c0 *fallbackItem;     // 0x3a4
    Pad_494c0 *FUN_00035ef0(int index);
};

struct PlayerRef_494c0 {
    Player_494c0 *FUN_00059a30();
};

struct Owner_494c0 {
    PlayerRef_494c0 *FUN_000592a0();
};

bool CSmartPropTypeCondition::vfunc_7(void* __p0) { Owner_494c0 * owner = (Owner_494c0 *)__p0;

    Player_494c0 *player = owner->FUN_000592a0()->FUN_00059a30();

    Item_494c0 *item = 0;
    if (player->FUN_00035ef0(0) != 0)
        item = player->FUN_00035ef0(0)->FUN_001d72e0();
    if (item == 0)
        item = player->fallbackItem;

    int current = 0;
    if (item != 0 && item->kind == 5)
        current = item->holder->FUN_001d64a0();

    switch (this->f_0c) {
    case 0:
        return this->f_10 == current;
    case 1:
        return this->f_10 != current;
    }
    return false;
}
