#include "compat/ptr.h"
#include "gen/physics.h"

struct Small_2fc130 {
    unsigned int x[0x10];
};
struct Big_2fc130 {
    unsigned int x[0x15];
    Small_2fc130* f100();
    void f120(Small_2fc130*);
};
struct Joint2 {
    char pad[8];
    void* item;
    void b980(Small_2fc130*);
};
struct Obj_2fc130 {
    Big_2fc130* edf0();
    void ee40(Big_2fc130*);
};
struct Arg_2fc130 {
    Obj_2fc130* f490(void*);
};

void physics::PhysicsJointMatrixModifier::vfunc_9(hulk_intptr __p0) { Arg_2fc130 * arg = (Arg_2fc130 *)__p0;

    if (!this->f_10)
        return;
    void* it = (*(Joint2 * *)&this->f_18)->item;
    Obj_2fc130* obj = arg->f490(it);
    Big_2fc130* bp = obj->edf0();
    Big_2fc130 big = *bp;
    Small_2fc130* sp = big.f100();
    Small_2fc130 small = *sp;
    (*(Joint2 * *)&this->f_18)->b980(&small);
    big.f120(&small);
    obj->ee40(&big);
}
