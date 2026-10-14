// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 14/14)
// FUN_002317e0 @ 0x002317e0
struct Table;
struct Search {
    Table* owner;
    unsigned reserved;
    unsigned a;
    unsigned b;
    unsigned index;
    unsigned c;
    unsigned FUN_00231180(unsigned key, unsigned value);
    unsigned FUN_00231230();
};
struct Pair { unsigned key; unsigned value; };
struct Table {
    unsigned unknown;
    unsigned count;
    unsigned removed;
    unsigned char cleanup;
    char pad[3];
    unsigned threshold;
    unsigned unused;
    void** slots;
    Pair* pairs;
    unsigned sentinel;
    void FUN_00231690();
    bool FUN_002317e0(unsigned key, unsigned value, unsigned match);
};
bool Table::FUN_002317e0(unsigned key, unsigned value, unsigned match) {
    Search search;
    search.owner = this;
    search.a = 0;
    search.b = 0;
    search.index = 0;
    search.c = 0;
    unsigned result = search.FUN_00231180(key, value);
    while (result != 0) {
        unsigned index = search.index;
        if (result == match && pairs[index].key == key && pairs[index].value == value) {
            slots[index] = &sentinel;
            pairs[index].key = 0;
            pairs[index].value = 0;
            unsigned newRemoved = removed + 1;
            unsigned newCount = count - 1;
            count = newCount;
            removed = newRemoved;
            return true;
        }
        result = search.FUN_00231230();
    }
    if (cleanup && removed > threshold) FUN_00231690();
    return false;
}