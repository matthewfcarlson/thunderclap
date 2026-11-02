#include "decls/data/platform/xbox/audio.h"
// data: bss = DAT_004e7778

struct Elem {
    void clean();
    char pad[12];
};
struct Obj {
    char pad[0x10];
    Elem a;
    Elem b;
    Elem arr[10];
};
extern "C" void __cdecl FUN_0025b5b0(void *, void *);
void freeobj(void*, Obj*);
void __cdecl target(void* p, Obj* o) {
    FUN_0025b5b0(p, (Obj *)o);
    if (o) {
        Elem* e = o->arr + 10;
        int n = 10;
        do {
            --e;
            e->clean();
        } while (--n);
        o->b.clean();
        o->a.clean();
        freeobj(((char*)((char*)&DAT_004e76e8 + 144)), o);
    }
}