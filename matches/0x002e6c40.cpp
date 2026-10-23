typedef void(__cdecl* Fn_2e6c40)(void*, void*);
struct Obj_2e6c40 {
    char pad[0x214];
    Fn_2e6c40 fn;
};
void __cdecl FUN_002e6b20(void*, void*);
void __cdecl target(Obj_2e6c40* a, void* b) {
    if (a && b) {
        if (a->fn)
            a->fn(a, b);
        else
            FUN_002e6b20(a, b);
    }
}