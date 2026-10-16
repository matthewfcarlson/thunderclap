#include "gen/physics.h"

struct Obj1_2fd5e0 {
    void* f490(int);
};
struct Obj2_2fd5e0 {
    void* edf();
};
struct Obj3_2fd5e0 {
    void* f100();
};

void* physics::SimStateArticulated::vfunc_5(int x) {
    if (x >= 0 && (*(void * *)&this->f_88)) {
        Obj1_2fd5e0* a = (Obj1_2fd5e0*)(*(void * *)&this->f_88);
        Obj2_2fd5e0* b = (Obj2_2fd5e0*)a->f490(x);
        Obj3_2fd5e0* c = (Obj3_2fd5e0*)b->edf();
        return (void*)((char*)c->f100() + 0x30);
    }
    return (void*)((char*)this + 0x40);
}
