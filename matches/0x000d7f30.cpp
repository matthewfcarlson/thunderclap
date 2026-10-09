extern "C" void* __cdecl FUN_000fc3d0();
struct Root {
    char pad[0x2218];
    void* obj;
};
struct Obj {
    char pad[0x9a8];
    unsigned char value;
};
unsigned char __cdecl FUN_000d7f30() {
    Root* r = (Root*)FUN_000fc3d0();
    Obj* p = (Obj*)r->obj;
    if (p)
        return p->value;
    return 0;
}