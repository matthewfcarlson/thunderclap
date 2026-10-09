struct Alloc {
    char pad[0xc];
    void* (*fn)(void*, void*, int, unsigned);
    void* ud;
    char pad2[0x38];
    int total;
};
struct State {
    char pad[0x10];
    Alloc* g;
};
void Error(State* L, const char* msg);
void ErrMem(State* L, int code);
void* Realloc(State* L, void* block, int osize, unsigned nsize) {
    Alloc* g = L->g;
    if (nsize >= 0xfffffffd)
        Error(L, "memory allocation error: block too big");
    void* r = g->fn(g->ud, block, osize, nsize);
    if (r == 0 && nsize > 0)
        ErrMem(L, 4);
    g->total += nsize - osize;
    return r;
}
