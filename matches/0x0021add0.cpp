struct Alloc_21add0 {
    char pad[0xc];
    void* (*fn)(void*, void*, int, unsigned);
    void* ud;
    char pad2[0x38];
    int total;
};
struct State_21add0 {
    char pad[0x10];
    Alloc_21add0* g;
};
void Error(State_21add0* L, const char* msg);
void ErrMem(State_21add0* L, int code);
void* Realloc(State_21add0* L, void* block, int osize, unsigned nsize) {
    Alloc_21add0* g = L->g;
    if (nsize >= 0xfffffffd)
        Error(L, "memory allocation error: block too big");
    void* r = g->fn(g->ud, block, osize, nsize);
    if (r == 0 && nsize > 0)
        ErrMem(L, 4);
    g->total += nsize - osize;
    return r;
}
