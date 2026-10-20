// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 26/26)
// FUN_00207410 @ 0x00207410
#include "decls/data/game/global.h"
#include "gen/content.h"

struct Slot_207410 {
    void FUN_00266220(int v);
};

struct Node_207410 {
    char pad0[0x38];
    Slot_207410 *slot;
    void FUN_00204f00();
};

struct LoadInventory_nv_207410 {
    int FUN_00266710();
    int FUN_00266700();
    void FUN_00263e90();
};

class Player_207410 {
public:
    char pad0[0x578];
    Slot_207410 *slots[3];
    int curSlot;
    char pad588[0xaec - 0x588];
    content::LoadInventory *stream;
    char busy;
    char pad_af1;
    char pending;
    char locked;

    int FUN_00203a80();
    Node_207410 *FUN_00204540(int a);
    void FUN_00207130();
    int FUN_00203bb0();
    void FUN_00204720(int v);
    void FUN_002067d0(int v, int w);
    char FUN_00207410();
};

char Player_207410::FUN_00207410()
{
    if (!stream)
        return 0;
    if (((LoadInventory_nv_207410*)(stream))->FUN_00266710() != 3)
        return 0;

    unsigned char flag;
    if (pending)
        flag = DAT_004c91d8[1];
    else
        flag = locked ? 0 : DAT_004c91d8[0];

    int id = FUN_00203a80();

    if (busy) {
        ((LoadInventory_nv_207410*)(stream))->FUN_00263e90();
        char wasLocked = locked;
        stream = 0;
        if (wasLocked) {
            locked = 0;
            return 0;
        }
        if (flag)
            FUN_00204540(id)->FUN_00204f00();
        busy = 0;
        pending = 0;
        return 0;
    }

    if (!pending && !locked)
        FUN_00207130();

    if (flag) {
        Node_207410 *n = FUN_00204540(id);
        int r = ((LoadInventory_nv_207410*)(stream))->FUN_00266700();
        n->slot->FUN_00266220(r);
    } else if (locked) {
        int r = ((LoadInventory_nv_207410*)(stream))->FUN_00266700();
        slots[curSlot]->FUN_00266220(r);
    }

    if (!locked) {
        int r = FUN_00203bb0();
        if (pending) {
            pending = 0;
            FUN_00204720(r);
        } else {
            FUN_002067d0(r, 0);
        }
    }

    ((LoadInventory_nv_207410*)(stream))->FUN_00263e90();
    stream = 0;
    return 1;
}
