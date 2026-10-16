// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 9/10, incomplete)
// FUN_001bee10 @ 0x001bee10
#include "decls/data/game/global.h"

struct Owner_1bee10 {
    char pad0[0x24];
    int values[1];
    int FUN_000f7240(int a, int b);
    int FUN_000f7220(int index);
};

struct Slot_1bee10 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1bee10 {
    Owner_1bee10 *owner;
    int current;
    Slot_1bee10 slots[8];
    int index;
    float scale;
    Blender_1bee10 *FUN_000f7fe0(Owner_1bee10 *o);
    void FUN_000f78e0();
};

int __cdecl FUN_000fba10(int handle, int a, int b, int value, float t, int extra);

class Effect_1bee10 {
public:
    char pad0[0x10];
    int keyA;
    int keyB;
    char pad18[0x20 - 0x18];
    int mode;
    char pad24[4];
    int handle;
    char pad2c[0x44 - 0x2c];
    Owner_1bee10 *owner;

    int FUN_001bee10();
};

int Effect_1bee10::FUN_001bee10()
{
    int result = 1;
    if (owner == 0)
        return result;

    Blender_1bee10 b;
    b.FUN_000f7fe0(owner);
    b.slots[b.index].weight = DAT_004c4c1c;
    b.slots[b.index].a = 1;
    b.slots[b.index].b = 3;
    b.scale = (*(float*)&DAT_004c4c18);
    int r = owner->FUN_000f7240(keyA, keyB);
    if (r != -1) {
        float num;
        switch (mode) {
        case 0:
            b.slots[b.index].weight = DAT_004c4c28 * DAT_004c4c1c;
            num = DAT_004c4c30;
            break;
        case 1:
            b.slots[b.index].weight = DAT_004c4c34 * DAT_004c4c1c;
            num = DAT_004c4c3c;
            break;
        case 2:
            b.slots[b.index].weight = DAT_004c4c44 * DAT_004c4c40;
            num = DAT_004c4c48;
            break;
        default:
            b.FUN_000f78e0();
            return result;
        }
        float t = num / b.slots[b.index].weight;
        int extra = b.owner->values[(*(int*)&DAT_004e22f0)];
        int value = owner->FUN_000f7220(r);
        result = FUN_000fba10(handle, 10, 0x80, value, t, extra);
    }
    b.FUN_000f78e0();
    return result;
}
