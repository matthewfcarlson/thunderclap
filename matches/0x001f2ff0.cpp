struct Entry {
    unsigned __int64 key;
    char pad[24];
};
extern int count;
extern Entry entries[];
Entry* Find(unsigned __int64* k) {
    int n = count;
    for (int i = 0; i < n; i++) {
        unsigned __int64 v = *k;
        if (entries[i].key == v)
            return &entries[i];
    }
    return 0;
}