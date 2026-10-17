// STATUS: equivalent (tools/equiv.py level 3: 2983 inputs, branch coverage 6/6)
// FUN_001eefc0 @ 0x001eefc0
struct Sub { void FUN_0027b040(int value); };
struct Entry {
    char pad0[8];
    int field8;
    int fieldC;
    int field10;
    unsigned char active;
    char pad15[3];
    Sub sub;
    char pad19[7];
    float field20;
    int field24;
};
struct Owner {
    char pad[12];
    Entry *entries;
    Entry* FUN_001eefc0();
};
Entry* Owner::FUN_001eefc0() {
    Entry *entry = entries;
    for (int index = 0; index < 100; ++index) {
        if (entry && !entry->active) {
            entry->field8 = 0;
            entry->fieldC = 0;
            entry->field10 = 0;
            entry->active = 0;
            entry->field20 = 100.0f;
            entry->field24 = 0;
            entry->sub.FUN_0027b040(0);
            return entry;
        }
        Entry *previous = entry;
        entry = (Entry*)((char*)entry + 0x28);
        if (index == 99) return previous;
    }
    return entry;
}