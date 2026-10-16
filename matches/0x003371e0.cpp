#include "decls/data/engine/movie.h"

struct Element_3371e0 {
    char pad[0x18];
    void f();
};
struct Obj_3371e0 {
    char pad[0x288];
    void run();
};
void Obj_3371e0::run() {
    *(void**)this = (void*)((int)((char*)&DAT_00434318));
    Element_3371e0* p = (Element_3371e0*)((char*)this + 0x288);
    int i = 0x18;
    do {
        p--;
        p->f();
        --i;
    } while (i);
}