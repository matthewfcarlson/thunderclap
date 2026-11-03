#include "compat/ptr.h"
#include "decls/data/engine/movie.h"
#include "gen/owners.h"

struct Element_3371e0 {
    char pad[0x18];
    void f();
};
void owners::Obj_3371e0::FUN_003371e0() {
    *(void**)this = (void*)((hulk_intptr)((char*)&DAT_00434318));
    Element_3371e0* p = (Element_3371e0*)((char*)this + 0x288);
    int i = 0x18;
    do {
        p--;
        p->f();
        --i;
    } while (i);
}