// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc3b0 @ 0x001dc3b0
struct Vec3_1dc3b0 { float x, y, z; };
extern Vec3_1dc3b0 DAT_004e26ac;
extern unsigned int DAT_004e26b8;

struct Record_1dc3b0 { char pad[0x10]; unsigned int flags; };
struct Link_1dc3b0 {
    void *FUN_001d6b40();
};
struct Entry_1dc3b0 {
    char pad0[0x18];
    Link_1dc3b0 *link;
    char pad1[0x22 - 0x1c];
    short recordIndex;
    char pad2[0x28 - 0x24];
};
struct Target_1dc3b0 {
    char pad0[0x608];
    Entry_1dc3b0 entries[1];
    char pad1[0x14608 - 0x608 - sizeof(Entry_1dc3b0)];
    Record_1dc3b0 records[1];
    void *FUN_001dc3b0(int idx);
};

void *Target_1dc3b0::FUN_001dc3b0(int idx)
{
    if ((DAT_004e26b8 & 1) == 0) {
        DAT_004e26b8 |= 1;
        DAT_004e26ac.x = 3.4028234663852886e+38f;
        DAT_004e26ac.y = 3.4028234663852886e+38f;
        DAT_004e26ac.z = 3.4028234663852886e+38f;
    }
    if (idx < 0)
        return &DAT_004e26ac;
    Entry_1dc3b0 *e = &entries[idx];
    Record_1dc3b0 *r = &records[e->recordIndex];
    if ((r->flags & 1) == 0)
        return r;
    Link_1dc3b0 *l = e->link;
    if (l == 0)
        return r;
    return l->FUN_001d6b40();
}
