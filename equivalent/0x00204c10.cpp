// STATUS: equivalent (tools/equiv.py level 3: 19593 inputs, branch coverage 28/28)
// FUN_00204c10 @ 0x00204c10
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_204c10 {
    float x, y, z;
};

class Node {
public:
    char pad0[0x10];
    class Locator *loc;
};

class Locator {
public:
    char FUN_00059a50(Vec3_204c10 *out);
};

struct Item_204c10 {
    char pad0[0x20];
    Vec3_204c10 pos;
    char pad1[0x54 - 0x2c];
    short index;
};

struct Info_204c10 {
    char pad0[9];
    char blocked;
};

struct Counter_204c10 {
    int FUN_001c7520();
};

class Items_204c10 {
public:
    char pad0[0x18];
    Counter_204c10 counter;
    Item_204c10 *FUN_001c7f80(int i);
    Info_204c10 *FUN_001c7f10(int index);
};

struct Sys_204c10 {
    int pad0;
    Items_204c10 *items;
};

Sys_204c10 *FUN_001c3d90();

struct Level3_204c10 {
    char pad0[0x124];
    Node *node;
};

struct Level2_204c10 {
    char pad0[0x20];
    Level3_204c10 *l3;
};

struct Level1_204c10 {
    char pad0[0xc];
    Level2_204c10 *l2;
};

class Finder_204c10 {
public:
    char pad0[0x588];
    Level1_204c10 *l1;
    char pad1[0x5a4 - 0x58c];
    char kind[1];
    int FUN_00204c10(char wantNear);
};

int Finder_204c10::FUN_00204c10(char wantNear)
{
    Node *node = l1->l2->l3->node;
    if (node == 0)
        return -1;
    Vec3_204c10 origin;
    node->loc->FUN_00059a50(&origin);
    Items_204c10 *items = FUN_001c3d90()->items;
    int count = items->counter.FUN_001c7520();
    int bestIndex = -1;
    hulk_freg bestDist = wantNear ? 999999.0f : -999999.0f;
    for (int i = 0; i < count; i++) {
        Item_204c10 *item = items->FUN_001c7f80(i);
        int idx = item->index;
        char k = kind[idx];
        if ((k == 2 && wantNear) || (k == 3 && !wantNear)) {
            Vec3_204c10 p = item->pos;
            hulk_freg dx = p.x - origin.x;
            hulk_freg dy = p.y - origin.y;
            hulk_freg dz = p.z - origin.z;
            hulk_freg d = (float)sqrt(dz * dz + dx * dx + dy * dy);
            if (d < bestDist) {
                if (wantNear) {
                    bestDist = d;
                    bestIndex = idx;
                }
            } else if (d > bestDist && !wantNear) {
                Info_204c10 *info = FUN_001c3d90()->items->FUN_001c7f10(idx);
                if (info == 0 || info->blocked == 0) {
                    bestDist = d;
                    bestIndex = idx;
                }
            }
        }
    }
    return bestIndex;
}
