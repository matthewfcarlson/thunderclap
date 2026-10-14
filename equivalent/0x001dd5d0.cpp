// STATUS: equivalent (tools/equiv.py level 3: 1098 inputs, branch coverage 11/12, incomplete)
// FUN_001dd5d0 @ 0x001dd5d0
struct Id {
    unsigned int lo;
    unsigned int hi;
};

struct Vec3 {
    float x, y, z;
};

struct Anchor {
    const Vec3 *FUN_001d6b40();
};

struct Slot {
    Vec3 pos;
    int pad0c;
    unsigned int flags;
};

struct Entry {
    Id id;
    char pad08[0x10];
    Anchor *anchor;
    char pad1c[6];
    short slot;
    char pad24[4];
};

class Registry {
public:
    char pad000[0x608];
    Entry entries[0x800];
    Slot slots[1];
    bool GetPosition(const Id *key, Vec3 *out);
};

bool Registry::GetPosition(const Id *key, Vec3 *out)
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
    Entry *e = &entries[i];
    Slot *s = &slots[e->slot];
    const Vec3 *src = &s->pos;
    if ((s->flags & 1) && e->anchor != 0)
        src = e->anchor->FUN_001d6b40();
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    return true;
}
