struct Entry {
    int count;
    float* value;
};
extern Entry entries[12];
extern float zero;
float* __cdecl FUN_000b0a00(int x, int y, int z) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return &zero;
    Entry* p = &entries[(x * 2 + y) * 3 + z];
    if (p->count <= 0)
        return &zero;
    return p->value;
}