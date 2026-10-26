#include "gen/physics.h"
#include "decls/data/game/global.h"
// data: zero_30a090 = DAT_003f32e0


void physics::PhysicsJoint3D::vfunc_21(void* __p0) { float * p = (float *)__p0;

    if (((*(volatile float (*)[3])&this->f_120)[2] * p[2] + (*(volatile float (*)[3])&this->f_120)[1] * p[1]) + (*(volatile float (*)[3])&this->f_120)[0] * p[0] < DAT_003f32e0) {
        this->f_ec = 1;
        (*(float (*)[3])&this->f_114)[0] = -(*(volatile float (*)[3])&this->f_120)[0];
        (*(float (*)[3])&this->f_114)[1] = -(*(volatile float (*)[3])&this->f_120)[1];
        (*(float (*)[3])&this->f_114)[2] = -(*(volatile float (*)[3])&this->f_120)[2];
    }
}
