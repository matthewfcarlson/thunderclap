#include "gen/physics.h"

namespace physics {
class PhysicsJoint1D_30ce90 : public physics::PhysicsJoint1D {};

} // namespace physics
void physics::PhysicsJoint1D::vfunc_15(void* __p0) { void * out = (void *)__p0;

    unsigned int* p = (unsigned int*)out;
    p[0] = *(unsigned int*)((char*)this + 0xfc);
    p[1] = *(unsigned int*)((char*)this + 0x100);
    p[2] = *(unsigned int*)((char*)this + 0x104);
}
