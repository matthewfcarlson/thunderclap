typedef void(__cdecl* Fn)(void*, void*);
struct Obj {
    char pad[0x214];
    Fn fn;
};
void __cdecl fallback(void*, void*);
void __cdecl target(Obj* a, void* b) {
    if (a && b) {
        if (a->fn)
            a->fn(a, b);
        else
            fallback(a, b);
    }
}