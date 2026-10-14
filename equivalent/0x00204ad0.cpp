// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 20/20)
// FUN_00204ad0 @ 0x00204ad0
extern "C" double sqrt(double);

struct Vec3_204ad0 {
    float x, y, z;
};

struct Item_204ad0 {
    char pad00[9];
    char skip;
    char pad0a[0x20 - 0xa];
    Vec3_204ad0 pos;
    char pad2c[0x54 - 0x2c];
    short id;
};

struct ItemSub {
    int FUN_001c7520();
};

struct ItemList_204ad0 {
    char pad00[0x18];
    ItemSub sub;
    Item_204ad0 *FUN_001c7f80(unsigned int index);
};

struct Manager_204ad0 {
    char pad00[4];
    ItemList_204ad0 *items;
};

struct Position_204ad0 {
    void FUN_00059a50(Vec3_204ad0 *out);
};

struct Anchor_204ad0 {
    char pad00[0x10];
    Position_204ad0 *position;
};

struct Node3 {
    char pad00[0x124];
    Anchor_204ad0 *anchor;
};

struct Node2_204ad0 {
    char pad00[0x20];
    Node3 *c;
};

struct Mid_204ad0 {
    char pad00[0xc];
    Node2_204ad0 *b;
};

struct Owner_204ad0 {
    char pad00[0x588];
    Mid_204ad0 *mid;
    char pad58c[0x59c - 0x58c];
    int excludedId;
    char pad5a0[4];
    char flags[1];
    int FUN_00204ad0(int count, int *ignore);
};

Manager_204ad0 *FUN_001c3d90();

int Owner_204ad0::FUN_00204ad0(int count, int *ignore)
{
    Node3 *c = mid->b->c;
    Anchor_204ad0 *anchor = c->anchor;
    if (anchor == 0)
        return -1;
    Vec3_204ad0 origin;
    anchor->position->FUN_00059a50(&origin);
    ItemList_204ad0 *items = FUN_001c3d90()->items;
    int total = items->sub.FUN_001c7520();
    int bestId = -1;
    float bestDist = -999999.0f;
    for (int i = 0; i < total; i++) {
        Item_204ad0 *it = items->FUN_001c7f80(i);
        if (it->skip != 0)
            continue;
        int id = it->id;
        bool ignored = false;
        for (int k = 0; k < count; k++) {
            if (id == ignore[k]) {
                ignored = true;
                break;
            }
        }
        if (ignored)
            continue;
        if (id == excludedId || flags[id] != 1)
            continue;
        float dx = it->pos.x - origin.x;
        float dy = it->pos.y - origin.y;
        float dz = it->pos.z - origin.z;
        double dist = sqrt((double)(dx * dx + dy * dy + dz * dz));
        if (dist > bestDist) {
            bestDist = (float)dist;
            bestId = id;
        }
    }
    return bestId;
}
