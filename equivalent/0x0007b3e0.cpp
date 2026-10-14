// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0007b3e0 @ 0x0007b3e0
// FUN_0007b3e0 @ 0x0007b3e0: remove the item in slot idx (swap with the last) after dropping its group count
struct Entry_7b3e0 {
    char pad0[0x1c];
    int groupId;            // 0x1c (only meaningful in a group's first entry)
    char pad20[0xc];
    int count;              // 0x2c
    int counts[6];          // 0x30
};

struct Group_7b3e0 {
    Entry_7b3e0 entries[14];
};

class Item_7b3e0 {
public:
    virtual void v0();
    virtual void Release();
    char pad04[0xbc - 4];
    int groupId;            // 0xbc
    int entryIndex;         // 0xc0
    char padc4[4];
    int countIndex;         // 0xc8
};

class Manager_7b3e0 {
public:
    char pad0[0x1904];
    Group_7b3e0 groups[7];        // 0x1904
    char pad_after[0x354c - 0x1904 - sizeof(Group_7b3e0) * 7];
    Item_7b3e0 *items[20];        // 0x354c
    int itemCount;          // 0x359c
    void FUN_0007b3e0(int idx);
};

void Manager_7b3e0::FUN_0007b3e0(int idx)
{
    Item_7b3e0 *item = items[idx];
    int id = item->groupId;
    if (id >= 0) {
        int g;
        for (g = 0; g < 7; g++) {
            if (groups[g].entries[0].groupId == id)
                break;
        }
        if (g >= 7)
            g = -1;
        Entry_7b3e0 *e = &groups[g].entries[item->entryIndex];
        e->counts[item->countIndex]--;
        e->count--;
    }
    item->Release();

    items[idx] = items[itemCount - 1];
    items[itemCount - 1] = 0;
    itemCount--;
}
