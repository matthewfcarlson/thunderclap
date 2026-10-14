// STATUS: equivalent (tools/equiv.py level 3: 914 inputs, branch coverage 9/10, incomplete)
// FUN_001e4310 @ 0x001e4310
struct Vec3_1e4310 { float x, y, z; };
struct Info_1e4310 { char pad[8]; Vec3_1e4310 pos; };
struct Key_1e4310 { unsigned lo, hi; };
struct Entry_1e4310 {
    unsigned lo, hi;
    char pad08[0x1a];
    short id;
    char pad24[4];
};

class Table_1e4310 {
public:
    char pad0[0x608];
    Entry_1e4310 entries[0x800];
    int FUN_001dd330(const Key_1e4310 *key, const Vec3_1e4310 *pos, int a, int b, int c, int d, int flag);
    int FUN_001e2940(int id);
    int FUN_001e4310(Info_1e4310 *info, const Key_1e4310 *key, int unused, int a, int b, int c, int d);
};

int Table_1e4310::FUN_001e4310(Info_1e4310 *info, const Key_1e4310 *key, int unused, int a, int b, int c, int d)
{
    for (int i = 0; i < 0x800; i++) {
        if (entries[i].lo == key->lo && entries[i].hi == key->hi)
            return 0;
    }
    int idx = FUN_001dd330(key, &info->pos, a, b, c, d, 1);
    if (idx == -1)
        return 0;
    return FUN_001e2940(entries[idx].id);
}
