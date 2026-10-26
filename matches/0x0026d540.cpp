#include "decls/data/engine/core.h"

#include "compat/ptr.h"
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) {
    return p;
}
struct MemoryTwoWayAllocator_26d540 {
    char pad0[8];
    int size;
    char pad1[4];
    char* begin;
    char* end;
    char* cur;
    char* limit;
    char pad2[12];
    MemoryTwoWayAllocator_26d540();
};
extern "C" void* __cdecl Alloc(hulk_intptr, int);
extern "C" void __cdecl Other();
MemoryTwoWayAllocator_26d540* __cdecl Make(int n, int heap) {
    DAT_004cdbb0 = heap;
    void* p = Alloc(heap, 44);
    MemoryTwoWayAllocator_26d540* o = new (p) MemoryTwoWayAllocator_26d540;
    Other();
    char* q = (char*)Alloc(o->size, n);
    char* e = q + n;
    o->begin = q;
    o->cur = q;
    o->end = e;
    o->limit = e;
    return o;
}