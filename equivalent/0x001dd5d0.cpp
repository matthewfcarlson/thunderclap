// STATUS: equivalent (tools/equiv.py level 3: 1098 inputs, branch coverage 11/12, incomplete)
// FUN_001dd5d0 @ 0x001dd5d0
struct Id_1dd5d0 {
    unsigned int lo;
    unsigned int hi;
};

struct Vec3_1dd5d0 {
    float x, y, z;
};

struct Anchor_1dd5d0 {
    const Vec3_1dd5d0 *FUN_001d6b40();
};

struct Slot_1dd5d0 {
    Vec3_1dd5d0 pos;
    int pad0c;
    unsigned int flags;
};

struct Entry_1dd5d0 {
    Id_1dd5d0 id;
    char pad08[0x10];
    Anchor_1dd5d0 *anchor;
    char pad1c[6];
    short slot;
    char pad24[4];
};

class Registry_1dd5d0 {
public:
    char pad000[0x608];
    Entry_1dd5d0 entries[0x800];
    Slot_1dd5d0 slots[1];
    bool GetPosition(const Id_1dd5d0 *key, Vec3_1dd5d0 *out);
};

bool Registry_1dd5d0::GetPosition(const Id_1dd5d0 *key, Vec3_1dd5d0 *out)
{
    unsigned int lo = key->lo;
    unsigned int hi = key->hi;
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].id.lo == lo && entries[i].id.hi == hi)
            break;
    }
    if (i == 0x800)
        return false;
    Entry_1dd5d0 *e = &entries[i];
    Slot_1dd5d0 *s = &slots[e->slot];
    const Vec3_1dd5d0 *src = &s->pos;
    if ((s->flags & 1) && e->anchor != 0)
        src = e->anchor->FUN_001d6b40();
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    return true;
}
