// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 12/12)
// FUN_001f31a0 @ 0x001f31a0
struct Id_1f31a0 {
    unsigned int lo;
    unsigned int hi;
};

struct Entry_1f31a0 {
    Id_1f31a0 id;
};

struct Registry_1f31a0 {
    char pad[0xd4];
    Entry_1f31a0 *entries[1];
    char pad2[0x324 - 0xd8];
    int count;
    Entry_1f31a0 *FUN_001f31a0(const Id_1f31a0 *key);
};

Entry_1f31a0 *Registry_1f31a0::FUN_001f31a0(const Id_1f31a0 *key)
{
    if (key == 0)
        return 0;
    unsigned int lo = key->lo;
    unsigned int hi = key->hi;
    if ((lo | hi) == 0)
        return 0;
    for (int i = 0; i < count; i++) {
        if (entries[i]->id.lo == lo && entries[i]->id.hi == hi)
            return entries[i];
    }
    return 0;
}
