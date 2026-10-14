// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CSmartPropTypeCondition::vfunc_7 @ 0x000494c0
struct Pad;

struct Item {
    char pad00[8];
    struct Holder *holder;  // 0x8
    int kind;               // 0xc
};

struct Holder {
    int FUN_001d64a0();
};

struct Pad {
    Item *FUN_001d72e0();
};

struct Player {
    char pad00[0x3a4];
    Item *fallbackItem;     // 0x3a4
    Pad *FUN_00035ef0(int index);
};

struct PlayerRef {
    Player *FUN_00059a30();
};

struct Owner {
    PlayerRef *FUN_000592a0();
};

class CSmartPropTypeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Owner *owner);
    char pad04[8];
    int mode;               // 0xc
    int wanted;             // 0x10
};

bool CSmartPropTypeCondition::vfunc_7(Owner *owner)
{
    Player *player = owner->FUN_000592a0()->FUN_00059a30();

    Item *item = 0;
    if (player->FUN_00035ef0(0) != 0)
        item = player->FUN_00035ef0(0)->FUN_001d72e0();
    if (item == 0)
        item = player->fallbackItem;

    int current = 0;
    if (item != 0 && item->kind == 5)
        current = item->holder->FUN_001d64a0();

    switch (mode) {
    case 0:
        return wanted == current;
    case 1:
        return wanted != current;
    }
    return false;
}
