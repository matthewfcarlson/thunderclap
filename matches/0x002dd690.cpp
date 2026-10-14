typedef void(__cdecl* ReadFn_2dd690)(void*);
extern "C" void __cdecl Fail(void*, const char*);
struct Obj_2dd690 {
    char pad[0x50];
    ReadFn_2dd690 fn;
};
void __cdecl Target(Obj_2dd690* p) {
    ReadFn_2dd690 fn = p->fn;
    if (fn)
        fn(p);
    else
        Fail(p, "Call to NULL read function");
}