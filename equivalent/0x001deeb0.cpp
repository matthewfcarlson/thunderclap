// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/16, incomplete)
// FUN_001deeb0 @ 0x001deeb0
struct Key_1deeb0 {
    int lo, hi;
};

struct Entry_1deeb0 {
    char pad[8];
    Key_1deeb0 id;         // 0x8
};

class EntryList_1deeb0 {
public:
    char pad[0x1e620];
    Entry_1deeb0* entries[128];    // 0x1e620
    int count;              // 0x1e820
    Entry_1deeb0* FUN_001deeb0(const Key_1deeb0* key);
};

// Finds the entry whose id matches the key.
Entry_1deeb0* EntryList_1deeb0::FUN_001deeb0(const Key_1deeb0* key)
{
    int lo = key->lo;
    int hi = key->hi;
    for (int i = 0; i < count; i++) {
        Entry_1deeb0* e = 0;
        if (i < count && i >= 0)
            e = entries[i];
        if (e->id.lo == lo && e->id.hi == hi) {
            if (i < count && i >= 0)
                return entries[i];
            return 0;
        }
    }
    return 0;
}
