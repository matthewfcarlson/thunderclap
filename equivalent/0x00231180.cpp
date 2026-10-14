// STATUS: equivalent (tools/equiv.py level 3: 2730 inputs, branch coverage 9/10, incomplete)
// FUN_00231180 @ 0x00231180
struct Entry_231180 {
    unsigned int first;
    unsigned int second;
};

struct Table_231180 {
    unsigned int capacity;  // 0x00
    char pad04[0x14];
    void **slots;           // 0x18
    Entry_231180 *entries;         // 0x1c
    char sentinel[4];       // 0x20
};

struct Probe_231180 {
    Table_231180 *table;           // 0x00
    int pad04;
    unsigned int first;     // 0x08
    unsigned int second;    // 0x0c
    unsigned int index;     // 0x10
    unsigned int step;      // 0x14
    void *FUN_00231180(unsigned int first, unsigned int second);
};

void *Probe_231180::FUN_00231180(unsigned int firstKey, unsigned int secondKey)
{
    Table_231180 *t = table;
    second = secondKey;
    first = firstKey;
    index = (t->capacity - 1) & firstKey;
    unsigned int stride = ((firstKey >> 9) & 0xfe) | 1;
    step = stride;
    unsigned int tries = 0;
    for (;;) {
        unsigned int i = index;
        void *slot = t->slots[i];
        if (slot == 0 || (t->entries[i].first == firstKey && t->entries[i].second == secondKey)) {
            if (slot != t->sentinel)
                break;
        }
        tries++;
        if (tries > t->capacity - 1)
            return 0;
        index = i + stride;
        index = (t->capacity - 1) & index;
    }
    return t->slots[index];
}
