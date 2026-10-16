// Same code shape as 0x0030ce90 (propagated; names are from that function)
#include "gen/physics.h"

namespace physics {
class PhysicsJoint1D_30d160 : public physics::PhysicsJoint3D {};

} // namespace physics
void physics::PhysicsJoint3D::vfunc_15(void* __p0) { void * out = (void *)__p0;

    unsigned int* p = (unsigned int*)out;
    p[0] = *(unsigned int*)((char*)this + 0xfc);
    p[1] = *(unsigned int*)((char*)this + 0x100);
    p[2] = *(unsigned int*)((char*)this + 0x104);
}
