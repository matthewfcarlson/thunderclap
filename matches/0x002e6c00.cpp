typedef unsigned int u32_2e6c00;
typedef u32_2e6c00(__cdecl* Callback_2e6c00)(void*, void*);
extern u32_2e6c00 __cdecl fallback(void*, void*);
struct Obj_2e6c00 {
    char pad[0x210];
    Callback_2e6c00 fn;
};
u32_2e6c00 __cdecl target(Obj_2e6c00* a, void* b) {
    if (!a || !b)
        return 0;
    if (a->fn)
        return a->fn(a, b);
    return fallback(a, b);
}