// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f5130..0x002f79f0 (kind game, layer engine, confidence high), dominant class physics::PhysicsObject
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x002f78c0 physics::PhysicsObject::vfunc_28 (72 B): matches/0x002f78c0.cpp [isolated: conflict: thunk_FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_28@PhysicsObject@physics@@UAEPAXI@Z
#include "gen/physics.h"

struct PhysicsObject_2f78c0 {
    int call_002f5480();
};
struct PhysicsObject_nv_2f78c0 {
    void work_002f75d0(hulk_intptr, int);
};
extern PhysicsObject_2f78c0* __cdecl thunk_FUN_0008d690(unsigned int);

void* physics::PhysicsObject::vfunc_28(unsigned int __p0) { int arg = (int)__p0;

    PhysicsObject_2f78c0* p = thunk_FUN_0008d690(0x1f8);
    hulk_intptr result;
    if (p)
        result = p->call_002f5480();
    else
        result = 0;
    ((PhysicsObject_nv_2f78c0*)this)->work_002f75d0(result, arg);
    return (void*)(result);
}

