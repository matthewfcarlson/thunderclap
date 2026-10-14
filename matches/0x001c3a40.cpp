extern "C" void* __cdecl Alloc(int);
extern "C" void __cdecl Free(void*);
extern "C" void __cdecl Print(const char*);
struct Maker {
    void* Make(int, int);
};
struct Store {
    void Put(void*);
};
struct Obj {
    char pad[4];
    Store* store;
    char pad2[4];
    Maker* maker;
    void Create(int a, int b);
};
void Obj::Create(int a, int b) {
    void* p = Alloc(15);
    void* q = maker->Make(a, b);
    if (q)
        store->Put(q);
    else
        Print("Object creation failed!\n");
    Free(p);
}