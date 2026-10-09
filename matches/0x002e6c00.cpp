typedef unsigned int u32;
typedef u32 (__cdecl *Callback)(void*, void*);
extern u32 __cdecl fallback(void*, void*);
struct Obj { char pad[0x210]; Callback fn; };
u32 __cdecl target(Obj* a, void* b) {
    if (!a || !b) return 0;
    if (a->fn) return a->fn(a, b);
    return fallback(a, b);
}