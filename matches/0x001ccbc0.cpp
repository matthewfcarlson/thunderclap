#include "compat/ptr.h"
struct C_1ccbc0 {
    char pad[0x54];
    int check();
};
struct B_1ccbc0 {
    int x;
    void* p;
};
struct A_1ccbc0 {
    char pad[0x3c];
    B_1ccbc0* b;
    char pad2[0x14];
    C_1ccbc0* c;
};
struct Obj_1ccbc0 {
    char pad[4];
    A_1ccbc0* a;
    hulk_intptr get();
};
hulk_intptr Obj_1ccbc0::get() {
    if (this->a && this->a->c && this->a->c->check()) {
        A_1ccbc0* q = this->a;
        if (q->b) {
            void* p = q->b->p;
            if (p)
                return (hulk_intptr)p;
        }
    }
    return 0;
}
