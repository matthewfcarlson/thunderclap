#include "gen/physics.h"

void physics::PhysicsJoint1D::vfunc_22(void* __p0) { float * out = (float *)__p0;

    float x = this->f_108;
    out[0] = x * this->f_fc;
    out[1] = x * this->f_100;
    out[2] = x * this->f_104;
}
