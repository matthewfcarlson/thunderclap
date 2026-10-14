// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 14/14)
// FUN_0002b730 @ 0x0002b730
struct Name_2b730 {
    unsigned int lo, hi;
    Name_2b730 *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Link_2b730 {
    char pad0[0x118];
    unsigned int nameLo;        // 0x118
    unsigned int nameHi;        // 0x11c
    char flagA;                 // 0x120
    char flagB;                 // 0x121
};

struct Item_2b730 {
    char pad0[0x1ca0];
    Link_2b730 *link;                 // 0x1ca0
    bool FUN_00035ab0();
};

struct Registry_2b730 {
    Item_2b730 *FUN_00059c10(int id);
};

struct Owner_2b730 {
    char pad0[0x44];
    Registry_2b730 *registry;         // 0x44
};

class Group_2b730 {
public:
    Owner_2b730 *owner;
    char pad4[8];
    int count;                  // 0xc
    int ids[16];                // 0x10
    bool FUN_0002b730(const char *name);
    void FUN_0002a4b0(int index, int flag);
};

// Walks the ids backwards and releases every item whose link carries the given name.
bool Group_2b730::FUN_0002b730(const char *name)
{
    Name_2b730 key;
    key.FUN_0027b0e0(name);
    for (int i = count - 1; i >= 0; i--) {
        Item_2b730 *item = owner->registry->FUN_00059c10(ids[i]);
        if (item == 0)
            continue;
        if (item->FUN_00035ab0())
            continue;
        Link_2b730 *link = item->link;
        if (link == 0)
            continue;
        link->flagB = 0;
        link->flagA = 0;
        if (key.lo == link->nameLo && key.hi == link->nameHi)
            FUN_0002a4b0(i, 0);
    }
    key.FUN_0027af50();
    return true;
}
