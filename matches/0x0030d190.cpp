#include "compat/ptr.h"
#include "gen/physics.h"

namespace physics {

} // namespace physics
void physics::PhysicsJoint3D::vfunc_16(hulk_intptr __p0, hulk_intptr __p1) { unsigned int * src = (unsigned int *)__p0; unsigned int * dst = (unsigned int *)__p1;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}
