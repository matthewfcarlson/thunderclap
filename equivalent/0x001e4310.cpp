// STATUS: equivalent (tools/equiv.py level 3: 914 inputs, branch coverage 9/10, incomplete)
// FUN_001e4310 @ 0x001e4310
struct Vec3 { float x, y, z; };
struct Info { char pad[8]; Vec3 pos; };
struct Key { unsigned lo, hi; };
struct Entry {
    unsigned lo, hi;
    char pad08[0x1a];
    short id;
    char pad24[4];
};

class Table {
public:
    char pad0[0x608];
    Entry entries[0x800];
    int FUN_001dd330(const Key *key, const Vec3 *pos, int a, int b, int c, int d, int flag);
    int FUN_001e2940(int id);
    int FUN_001e4310(Info *info, const Key *key, int unused, int a, int b, int c, int d);
};

int Table::FUN_001e4310(Info *info, const Key *key, int unused, int a, int b, int c, int d)
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
