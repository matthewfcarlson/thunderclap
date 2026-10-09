typedef void(__cdecl* ReadFn)(void*);
extern "C" void __cdecl Fail(void*, const char*);
struct Obj {
    char pad[0x50];
    ReadFn fn;
};
void __cdecl Target(Obj* p) {
    ReadFn fn = p->fn;
    if (fn)
        fn(p);
    else
        Fail(p, "Call to NULL read function");
}