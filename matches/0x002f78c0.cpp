#include "compat/ptr.h"
#include "gen/physics.h"

struct Helper_2f78c0 {
    int call();
};
struct PhysicsObject_nv_2f78c0 {
    void work(hulk_intptr, int);
};
extern Helper_2f78c0* __cdecl thunk_FUN_0008d690(unsigned int);

void* physics::PhysicsObject::vfunc_28(unsigned int __p0) { int arg = (int)__p0;

    Helper_2f78c0* p = thunk_FUN_0008d690(0x1f8);
    hulk_intptr result;
    if (p)
        result = p->call();
    else
        result = 0;
    ((PhysicsObject_nv_2f78c0*)this)->work(result, arg);
    return (void*)(result);
}
