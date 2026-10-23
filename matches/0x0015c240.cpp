#include "gen/hulkfight.h"

struct A {
    char pad[0x138];
    int n;
};
struct B {
    A* get();
};
struct C {
    B* get();
};
extern int t1, t2;
extern "C" void* __cdecl cast(void*, int, void*, void*, int);

bool hulkfight::motion::LocomotingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; C * obj = (C *)__p1; int z = (int)__p2;

    if (!cast(obj, 0, &t1, &t2, 0))
        return false;
    unsigned char v = obj->get()->get()->n > 0;
    return (unsigned char)(v - (*(unsigned char *)&this->f_0c)) == 0;
}
