// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/16, incomplete)
// FUN_001deeb0 @ 0x001deeb0
struct Key {
    int lo, hi;
};

struct Entry {
    char pad[8];
    Key id;         // 0x8
};

class EntryList {
public:
    char pad[0x1e620];
    Entry* entries[128];    // 0x1e620
    int count;              // 0x1e820
    Entry* FUN_001deeb0(const Key* key);
};

// Finds the entry whose id matches the key.
Entry* EntryList::FUN_001deeb0(const Key* key)
{
    int lo = key->lo;
    int hi = key->hi;
    for (int i = 0; i < count; i++) {
        Entry* e = 0;
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
