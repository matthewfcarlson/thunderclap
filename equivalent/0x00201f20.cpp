// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 19/20, incomplete)
// FUN_00201f20 @ 0x00201f20
struct Vec3_201f20 { int x, y, z; };
struct Vec3f { float x, y, z; };

struct Entry24 {
    char pad00[0x16];
    unsigned short flags;
};

struct Info_201f20 {
    char pad00[0x18];
    Entry24* table;
};

struct Owner_201f20 {
    char pad00[0x44];
    Info_201f20* info;
};

struct Item_201f20 {
    char pad00[0x18];
    Vec3f dir;
    float f24;
    char pad28[0x38 - 0x28];
    Vec3_201f20 pos;
    bool FUN_002f8e10(Owner_201f20** owner, int* index);
};

struct Manager_201f20 {
    char pad00[0x1b0];
    Item_201f20* begin;
    Item_201f20* end;
    bool FUN_002edb90(int id, int mode);
};
extern Manager_201f20* DAT_00554c14;

bool __stdcall FUN_00201f20(int id, int mask, Vec3_201f20* outPos, Vec3_201f20* outDir, Entry24** outEntry, Owner_201f20** outOwner)
{
    if (outEntry)
        *outEntry = 0;
    if (outOwner)
        *outOwner = 0;
    Manager_201f20* mgr = DAT_00554c14;
    if (!mgr->FUN_002edb90(id, 10))
        return false;
    unsigned int count = (unsigned int)(mgr->end - mgr->begin);
    struct Frame { int index; Entry24* entry; int pad; Owner_201f20* owner; } f;
    for (unsigned int i = 0; i < count; i++) {
        Item_201f20* item = &mgr->begin[i];
        if (item->f24 < 0.0f)
            continue;
        item->FUN_002f8e10(&f.owner, &f.index);
        Entry24* e = &f.owner->info->table[(unsigned short)f.index];
        f.entry = e;
        if (mask & (e->flags >> 3))
            continue;
        item = &mgr->begin[i];
        float s = item->dir.z * 0.0f + item->dir.y * -1.0f + item->dir.x * 0.0f;
        if (s > 0.0f)
            continue;
        item = &mgr->begin[i];
        *outPos = item->pos;
        item = &mgr->begin[i];
        outDir->x = *(int*)&item->dir.x;
        outDir->y = *(int*)&item->dir.y;
        outDir->z = *(int*)&item->dir.z;
        if (outEntry)
            *outEntry = f.entry;
        if (outOwner)
            *outOwner = f.owner;
        return true;
    }
    return false;
}
