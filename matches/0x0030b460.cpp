#include "gen/physics.h"

namespace physics {

} // namespace physics
void physics::PhysicsJoint3D::vfunc_9(float a, float b) {
    (*(float *)&this->f_10) = a;
    (*(float *)&this->f_14) = b;
    if (b == a && b > 0.0f) {
        this->f_f8 = 0;
        (*(float *)&this->f_10) = -b;
    } else {
        this->f_f8 = 1;
        (*(float *)&this->f_10) = -b;
    }
}
