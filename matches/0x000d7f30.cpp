extern "C" void* __cdecl FUN_000fc3d0();
struct Root_d7f30 {
    char pad[0x2218];
    void* obj;
};
struct Obj_d7f30 {
    char pad[0x9a8];
    unsigned char value;
};
unsigned char __cdecl FUN_000d7f30() {
    Root_d7f30* r = (Root_d7f30*)FUN_000fc3d0();
    Obj_d7f30* p = (Obj_d7f30*)r->obj;
    if (p)
        return p->value;
    return 0;
}