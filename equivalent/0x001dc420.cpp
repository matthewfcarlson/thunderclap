// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dc420 @ 0x001dc420
struct Vec3 {
    float x, y, z;
};
struct Target {
    void FUN_001d7810(Vec3 v);
};
struct Slot {
    char pad0[0x18];
    Target *target;
    char pad1c[6];
    short link;
    char pad24[4];
};
struct Entry {
    Vec3 pos;
    char pad0c[4];
    unsigned char flags;
    char pad11[3];
};
struct Table {
    char pad0[0x608];
    Slot slots[0x800];
    Entry entries[1];
    bool FUN_001dc420(int index, Vec3 *pos);
};

bool Table::FUN_001dc420(int index, Vec3 *pos)
{
    if (index < 0)
        return false;
    Slot *slot = &slots[index];
    Entry *e = &entries[slot->link];
    if ((e->flags & 1) && slot->target) {
        slot->target->FUN_001d7810(*pos);
        return true;
    }
    e->pos = *pos;
    return true;
}
