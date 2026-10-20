#include "compat/ptr.h"
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) {
    return p;
}
struct Obj {
    char pad0[8];
    int size;
    char pad1[4];
    char* begin;
    char* end;
    char* cur;
    char* limit;
    char pad2[12];
    Obj();
};
extern "C" void* __cdecl Alloc(hulk_intptr, int);
extern "C" void __cdecl Other();
extern int g;
Obj* __cdecl Make(int n, int heap) {
    g = heap;
    void* p = Alloc(heap, 44);
    Obj* o = new (p) Obj;
    Other();
    char* q = (char*)Alloc(o->size, n);
    char* e = q + n;
    o->begin = q;
    o->cur = q;
    o->end = e;
    o->limit = e;
    return o;
}