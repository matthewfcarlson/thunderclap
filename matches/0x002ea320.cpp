typedef void*(__cdecl* AllocFn)(void*, int, int);
typedef void(__cdecl* FreeFn)(void*, void*);
struct Manager_2ea320 {
    char pad[0x20];
    AllocFn alloc;
    FreeFn freefn;
    void* heap;
};
extern void* __cdecl FUN_002ea2a0(void*, void*, int);
void* __cdecl FUN_002ea320(Manager_2ea320* m, int param2, int param3) {
    void* a = m->alloc(m->heap, 1, 0x40);
    if (!a)
        return 0;
    *(void**)((char*)a + 0x24) = m->alloc(m->heap, 8, 0x5a0);
    if (!*(void**)((char*)a + 0x24)) {
        m->freefn(m->heap, a);
        return 0;
    }
    *(void**)((char*)a + 0x28) = m->alloc(m->heap, 1, param3);
    if (!*(void**)((char*)a + 0x28)) {
        m->freefn(m->heap, *(void**)((char*)a + 0x24));
        m->freefn(m->heap, a);
        return 0;
    }
    *(void**)((char*)a + 0x2c) = (char*)*(void**)((char*)a + 0x28) + param3;
    *(int*)((char*)a + 0x38) = param2;
    *(int*)a = 0;
    FUN_002ea2a0(a, m, 0);
    return a;
}