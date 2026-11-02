typedef void(__cdecl* ReadFn_2dd690)(void*, void*, unsigned int);
extern "C" void __cdecl Fail(void*, const char*);
struct Obj_2dd690 {
    char pad[0x50];
    ReadFn_2dd690 fn;
};
extern "C" void __cdecl FUN_002dd690(void * p, void* data, unsigned int length) {
    ReadFn_2dd690 fn = ((Obj_2dd690 *)p)->fn;
    if (fn)
        fn(((Obj_2dd690 *)p), data, length);
    else
        Fail(((Obj_2dd690 *)p), "Call to NULL read function");
}