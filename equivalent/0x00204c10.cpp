// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 24/28, incomplete)
// FUN_00204c10 @ 0x00204c10
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

class Node {
public:
    char pad0[0x10];
    class Locator *loc;
};

class Locator {
public:
    char FUN_00059a50(Vec3 *out);
};

struct Item {
    char pad0[0x20];
    Vec3 pos;
    char pad1[0x54 - 0x2c];
    short index;
};

struct Info {
    char pad0[9];
    char blocked;
};

struct Counter {
    int FUN_001c7520();
};

class Items {
public:
    char pad0[0x18];
    Counter counter;
    Item *FUN_001c7f80(int i);
    Info *FUN_001c7f10(int index);
};

struct Sys {
    int pad0;
    Items *items;
};

Sys *FUN_001c3d90();

struct Level3 {
    char pad0[0x124];
    Node *node;
};

struct Level2 {
    char pad0[0x20];
    Level3 *l3;
};

struct Level1 {
    char pad0[0xc];
    Level2 *l2;
};

class Finder {
public:
    char pad0[0x588];
    Level1 *l1;
    char pad1[0x5a4 - 0x58c];
    char kind[1];
    int FUN_00204c10(char wantNear);
};

int Finder::FUN_00204c10(char wantNear)
{
    Node *node = l1->l2->l3->node;
    if (node == 0)
        return -1;
    Vec3 origin;
    node->loc->FUN_00059a50(&origin);
    Items *items = FUN_001c3d90()->items;
    int count = items->counter.FUN_001c7520();
    int bestIndex = -1;
    float bestDist = wantNear ? 1000000.0f : -1000000.0f;
    for (int i = 0; i < count; i++) {
        Item *item = items->FUN_001c7f80(i);
        int idx = item->index;
        char k = kind[idx];
        if ((k == 2 && wantNear) || (k == 3 && !wantNear)) {
            Vec3 p = item->pos;
            float dx = p.x - origin.x;
            float dy = p.y - origin.y;
            float dz = p.z - origin.z;
            float d = (float)sqrt(dz * dz + dx * dx + dy * dy);
            if (d < bestDist) {
                if (wantNear) {
                    bestDist = d;
                    bestIndex = idx;
                }
            } else if (d > bestDist && !wantNear) {
                Info *info = FUN_001c3d90()->items->FUN_001c7f10(idx);
                if (info == 0 || info->blocked == 0) {
                    bestDist = d;
                    bestIndex = idx;
                }
            }
        }
    }
    return bestIndex;
}
