#include "gen/physics.h"

class PhysicsJoint1D_30cf20 : public physics::PhysicsJoint1D {};

void physics::PhysicsJoint1D::vfunc_19(void* __p0) { float * p = (float *)__p0;

    *(float*)((char*)this + 0x108) = *(float*)((char*)this + 0xfc) * p[0] +
                                     *(float*)((char*)this + 0x100) * p[1] +
                                     *(float*)((char*)this + 0x104) * p[2];
}
