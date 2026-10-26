#include "compat/ptr.h"
#include "gen/physics.h"

void physics::PhysicsJoint3D::vfunc_18(hulk_intptr __p0, hulk_intptr __p1) { float * a = (float *)__p0; float * b = (float *)__p1;

    float x = this->f_e8;
    b[0] = x * a[0];
    b[1] = x * a[1];
    b[2] = x * a[2];
}
