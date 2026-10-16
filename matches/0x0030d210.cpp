#include "gen/physics.h"

void physics::PhysicsJoint3D::vfunc_22(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    out[0] = *(unsigned int*)((char*)this + 0x114);
    out[1] = *(unsigned int*)((char*)this + 0x118);
    out[2] = *(unsigned int*)((char*)this + 0x11c);
}
