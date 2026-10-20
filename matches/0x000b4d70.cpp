struct Entry {
    unsigned __int64 first, second;
    char rest[0x18];
};
struct Owner {
    char padding[0x470];
    Entry entries[128];
    int FUN_000b4d70(unsigned __int64 value);
};
int Owner::FUN_000b4d70(unsigned __int64 value) {
    for (int i = 0; i < 128; ++i) {
        Entry& entry = entries[i];
        if (entry.first == 0)
            return -1;
        if (entry.first == value)
            return i;
        if (entry.second == value)
            return i;
    }
    return -1;
}