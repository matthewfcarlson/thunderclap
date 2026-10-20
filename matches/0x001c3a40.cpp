#include "compat/ptr.h"
extern "C" void* __cdecl Alloc(hulk_intptr);
extern "C" void __cdecl Free(void*);
extern "C" void __cdecl Print(const char*);
struct Maker_1c3a40 {
    void* Make(int, int);
};
struct Store {
    void Put(void*);
};
struct Obj_1c3a40 {
    char pad[4];
    Store* store;
    char pad2[4];
    Maker_1c3a40* maker;
    void Create(int a, int b);
};
void Obj_1c3a40::Create(int a, int b) {
    void* p = Alloc(15);
    void* q = maker->Make(a, b);
    if (q)
        store->Put(q);
    else
        Print("Object creation failed!\n");
    Free(p);
}