// STATUS: equivalent (tools/equiv.py level 3: 18 inputs, branch coverage 22/22)
// FUN_001fc8c0 @ 0x001fc8c0
struct Entry_1fc8c0 {
    char pad[8];
    unsigned int key1;
    unsigned int key2;
    char rest[48];
};
struct Bucket_1fc8c0 { int count; Entry_1fc8c0 *entries; };
struct Object {
    char pad[0x20c];
    int count;
    Entry_1fc8c0 *entries;
    Bucket_1fc8c0 *groups[6];
    Entry_1fc8c0 *FUN_001fc8c0(unsigned int key1, unsigned int key2);
};
Entry_1fc8c0 *Object::FUN_001fc8c0(unsigned int key1, unsigned int key2) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].key1 == key1 && entries[i].key2 == key2)
            return entries + i;
    }
    for (int g = 0; g < 6; ++g) {
        Bucket_1fc8c0 *buckets = groups[g];
        for (int b = 0; b < 20; ++b) {
            Entry_1fc8c0 *entry = buckets[b].entries;
            int n = buckets[b].count;
            for (int j = 0; j < n; ++j, ++entry) {
                if (entry && entry->key1 == key1 && entry->key2 == key2)
                    return entry;
            }
        }
    }
    return 0;
}
