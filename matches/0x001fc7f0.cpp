struct Entry {
    char pad[8];
    unsigned __int64 key;
};
struct Table {
    char pad[12];
    Entry* slots[128];
    Entry* FUN_001fc7f0(unsigned value);
};
unsigned __int64 __cdecl FUN_00096d80(unsigned value);
Entry* Table::FUN_001fc7f0(unsigned value) {
    unsigned __int64 key = FUN_00096d80(value);
    for (int i = 0; i < 128; ++i) {
        Entry* entry = slots[i];
        if (entry && entry->key == key)
            return entry;
    }
    return 0;
}