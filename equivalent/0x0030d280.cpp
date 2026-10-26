// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// physics::PhysicsJoint3D::vfunc_24 @ 0x0030d280
#include "compat/ptr.h"
#include "gen/physics.h"

namespace physics {
struct Vec3 { float x, y, z; };

}
void physics::PhysicsJoint3D::vfunc_24(hulk_intptr __p0) { const Vec3 * delta = (const Vec3 *)__p0;

    (*(Vec3 *)&this->f_120).x += delta->x;
    (*(Vec3 *)&this->f_120).y += delta->y;
    (*(Vec3 *)&this->f_120).z += delta->z;
    (*(unsigned char *)&this->f_151) = 0;
}
