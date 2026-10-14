typedef unsigned int uint;
struct SourceEntry_333ab0 {
    uint key;
    uint count;
    uint* values;
};
struct Source_333ab0 {
    uint count;
    SourceEntry_333ab0* entries;
};
struct DestEntry_333ab0 {
    uint count;
    uint values[16];
};
struct Object {
    char padding[0x28];
    uint count;
    uint keys[6];
    DestEntry_333ab0 entries[1];
    void FUN_00333ab0(Source_333ab0* source);
};
void Object::FUN_00333ab0(Source_333ab0* source) {
    count = source->count;
    for (uint i = 0; i < count; ++i) {
        SourceEntry_333ab0* entry = &source->entries[i];
        keys[i] = entry->key;
        uint n = entry->count;
        entries[i].count = n;
        for (uint j = 0; j < n; ++j)
            entries[i].values[j] = entry->values[j];
    }
}
