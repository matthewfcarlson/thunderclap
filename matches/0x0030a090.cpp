#include "gen/physics.h"

extern const float zero_30a090;

void physics::PhysicsJoint3D::vfunc_21(void* __p0) { float * p = (float *)__p0;

    if (((*(volatile float (*)[3])&this->f_120)[2] * p[2] + (*(volatile float (*)[3])&this->f_120)[1] * p[1]) + (*(volatile float (*)[3])&this->f_120)[0] * p[0] < zero_30a090) {
        this->f_ec = 1;
        (*(float (*)[3])&this->f_114)[0] = -(*(volatile float (*)[3])&this->f_120)[0];
        (*(float (*)[3])&this->f_114)[1] = -(*(volatile float (*)[3])&this->f_120)[1];
        (*(float (*)[3])&this->f_114)[2] = -(*(volatile float (*)[3])&this->f_120)[2];
    }
}
