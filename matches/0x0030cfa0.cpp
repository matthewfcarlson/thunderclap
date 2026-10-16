#include "gen/physics.h"

void physics::PhysicsJoint1D::vfunc_24(int __p0) { float * p = (float *)__p0;

    this->f_10c = this->f_fc * p[0] + this->f_100 * p[1] + this->f_104 * p[2] + this->f_10c;
}
