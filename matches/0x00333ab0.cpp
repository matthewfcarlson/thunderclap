typedef unsigned int uint;
struct SourceEntry {
    uint key;
    uint count;
    uint* values;
};
struct Source {
    uint count;
    SourceEntry* entries;
};
struct DestEntry {
    uint count;
    uint values[16];
};
struct Object {
    char padding[0x28];
    uint count;
    uint keys[6];
    DestEntry entries[1];
    void FUN_00333ab0(Source* source);
};
void Object::FUN_00333ab0(Source* source) {
    count = source->count;
    for (uint i = 0; i < count; ++i) {
        SourceEntry* entry = &source->entries[i];
        keys[i] = entry->key;
        uint n = entry->count;
        entries[i].count = n;
        for (uint j = 0; j < n; ++j)
            entries[i].values[j] = entry->values[j];
    }
}
