extern "C" void* __cdecl Alloc(int size);

struct Obj {
    char data[0x98];
    Obj* Create(int arg);
};

Obj* __cdecl Target(int arg) {
    Obj* p = (Obj*)Alloc(0x98);
    if (p)
        return p->Create(arg);
    return 0;
}
