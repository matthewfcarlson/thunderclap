#include "gen/physics.h"

namespace physics {

} // namespace physics
hulk_freg physics::PhysicsJoint1D::vfunc_6() {
    union U {
        float f;
        unsigned int i;
    } u;
    u.f = this->f_114;
    u.i &= 0x7fffffff;
    return u.f;
}
