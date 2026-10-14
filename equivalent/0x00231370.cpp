// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 12/12)
// FUN_00231370 @ 0x00231370
struct HashEntry;

struct HashTable {
    unsigned int size;           // power of two
    char pad04[0x14];
    HashEntry **buckets;         // 0x18
    unsigned int *keys;          // 0x1c, two words per slot
    char emptyMarker[1];         // 0x20
};

class HashProbe {
public:
    HashTable *table;            // 0x00
    char pad04[4];
    unsigned int keyLo;          // 0x08
    unsigned int keyHi;          // 0x0c
    unsigned int index;          // 0x10
    unsigned int step;           // 0x14
    HashEntry *FUN_00231370();
};

// Advances to the next slot in the open-addressing sequence that holds the key (or is empty).
HashEntry *HashProbe::FUN_00231370() {
    HashTable *t = table;
    unsigned int stride = step;
    index = (index + stride) & (t->size - 1);
    unsigned int slot = index;
    unsigned int tries = 0;
    if (t->buckets[slot] != 0) {
        for (;;) {
            if (t->keys[slot * 2] == keyLo && t->keys[slot * 2 + 1] == keyHi)
                break;
            if ((char *)t->buckets[slot] == t->emptyMarker)
                break;
            tries++;
            if (tries > t->size - 1)
                return 0;
            index = slot + stride;
            slot = (t->size - 1) & index;
            index = slot;
            if (table->buckets[slot] == 0)
                break;
        }
    }
    return t->buckets[slot];
}
