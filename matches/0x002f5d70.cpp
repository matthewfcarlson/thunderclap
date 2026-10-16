#include "gen/physics.h"

namespace physics {

} // namespace physics
void physics::PhysicsObject::vfunc_35(float x) {
    this->f_40 = x;
    if (x > 0.0f)
        this->f_44 = 1.0f / x;
    else
        this->f_44 = 0.0f;
}
