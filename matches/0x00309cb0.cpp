#include "gen/physics.h"
#include "decls/data/game/global.h"
// data: zero_309cb0 = DAT_003f32e0


void physics::PhysicsJoint1D::vfunc_21(void* __p0) { float * p = (float *)__p0;

    if ((this->f_100 * p[1] + this->f_104 * p[2] + this->f_fc * p[0]) * this->f_10c < DAT_003f32e0) {
        this->f_ec = 1;
        this->f_108 = -this->f_10c;
    }
}
