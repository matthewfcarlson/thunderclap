#include "gen/physics.h"

void physics::PhysicsJoint::vfunc_28(void* __p0) { char * p = (char *)__p0;

    *(int*)(p + 0x1c) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x24) = *(int*)(p + 0x20);
}
