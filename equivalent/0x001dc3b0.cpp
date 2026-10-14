// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc3b0 @ 0x001dc3b0
struct Vec3 { float x, y, z; };
extern Vec3 DAT_004e26ac;
extern unsigned int DAT_004e26b8;

struct Record { char pad[0x10]; unsigned int flags; };
struct Link {
    void *FUN_001d6b40();
};
struct Entry {
    char pad0[0x18];
    Link *link;
    char pad1[0x22 - 0x1c];
    short recordIndex;
    char pad2[0x28 - 0x24];
};
struct Target {
    char pad0[0x608];
    Entry entries[1];
    char pad1[0x14608 - 0x608 - sizeof(Entry)];
    Record records[1];
    void *FUN_001dc3b0(int idx);
};

void *Target::FUN_001dc3b0(int idx)
{
    if ((DAT_004e26b8 & 1) == 0) {
        DAT_004e26b8 |= 1;
        DAT_004e26ac.x = 3.4028234663852886e+38f;
        DAT_004e26ac.y = 3.4028234663852886e+38f;
        DAT_004e26ac.z = 3.4028234663852886e+38f;
    }
    if (idx < 0)
        return &DAT_004e26ac;
    Entry *e = &entries[idx];
    Record *r = &records[e->recordIndex];
    if ((r->flags & 1) == 0)
        return r;
    Link *l = e->link;
    if (l == 0)
        return r;
    return l->FUN_001d6b40();
}
