// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dc420 @ 0x001dc420
struct Vec3_1dc420 {
    float x, y, z;
};
struct Target_1dc420 {
    void FUN_001d7810(Vec3_1dc420 v);
};
struct Slot_1dc420 {
    char pad0[0x18];
    Target_1dc420 *target;
    char pad1c[6];
    short link;
    char pad24[4];
};
struct Entry_1dc420 {
    Vec3_1dc420 pos;
    char pad0c[4];
    unsigned char flags;
    char pad11[3];
};
struct Table_1dc420 {
    char pad0[0x608];
    Slot_1dc420 slots[0x800];
    Entry_1dc420 entries[1];
    bool FUN_001dc420(int index, Vec3_1dc420 *pos);
};

bool Table_1dc420::FUN_001dc420(int index, Vec3_1dc420 *pos)
{
    if (index < 0)
        return false;
    Slot_1dc420 *slot = &slots[index];
    Entry_1dc420 *e = &entries[slot->link];
    if ((e->flags & 1) && slot->target) {
        slot->target->FUN_001d7810(*pos);
        return true;
    }
    e->pos = *pos;
    return true;
}
