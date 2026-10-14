// STATUS: equivalent (tools/equiv.py level 3: 950 inputs, branch coverage 9/10, incomplete)
// FUN_001dc170 @ 0x001dc170
struct Key {
    int lo;
    int hi;
};

struct Entry {
    Key key;                // 0x00
    char pad8[0x22 - 8];
    short slot;             // 0x22
    char pad24[4];
};

struct Slot {
    unsigned char flags;
    char pad1[19];
};

struct KeyRef {
    char pad0[8];
    Key key;                // 0x08
};

class SlotTable {
public:
    char pad0[0x608];
    Entry entries[0x800];   // 0x608
    char pad14608[0x10];
    Slot slots[1];          // 0x14618; indexed by Entry::slot (may be negative)
    bool FUN_001dc170(const KeyRef* ref, char set);
};

// Looks up the entry for a key and sets or clears bit 1 of its slot; false when the key is unknown.
bool SlotTable::FUN_001dc170(const KeyRef* ref, char set)
{
    int hi = ref->key.hi;
    int lo = ref->key.lo;
    for (int i = 0; i < 0x800; i++) {
        if (entries[i].key.lo == lo && entries[i].key.hi == hi) {
            Slot* slot = &slots[entries[i].slot];
            if (set)
                slot->flags |= 2;
            else
                slot->flags &= 0xfd;
            return true;
        }
    }
    return false;
}
