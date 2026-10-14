// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 11/12, incomplete)
// FUN_001c81a0 @ 0x001c81a0
struct Vec3 {
    float x, y, z;
};

struct Item {
    char pad00[0x20];
    float x;                // 0x20
    float y;                // 0x24
    float z;                // 0x28
};

class ItemTable {
public:
    char pad00[0x28];
    int last;               // 0x28
    Item **slots;           // 0x2c
    Item *FUN_001c81a0(const Vec3 *pos);
};

// Returns the item nearest to pos (squared distance below 1e12), or null.
Item *ItemTable::FUN_001c81a0(const Vec3 *pos)
{
    Item *nearest = 0;
    float best = 1.0e12f;

    for (int i = 0; i <= last; i++) {
        Item *item = slots[i];
        if (item == 0)
            continue;
        double dist2 = ((pos->x - item->x) * (pos->x - item->x) + (pos->z - item->z) * (pos->z - item->z)) +
                       (pos->y - item->y) * (pos->y - item->y);
        if (dist2 < best) {
            best = (float)dist2;
            nearest = item;
        }
    }
    return nearest;
}
