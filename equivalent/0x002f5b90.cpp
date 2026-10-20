// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::PhysicsObject::vfunc_33 @ 0x002f5b90
#include "gen/physics.h"

namespace physics {   }
void physics::PhysicsObject::vfunc_33(int __p0) { const float * delta = (const float *)__p0;
 (*(float *)&this->f_13c) += delta[0]; (*(float *)&this->f_140) += delta[1]; (*(float *)&this->f_144) += delta[2]; (*(unsigned char *)&this->f_1d0) = 1; if (vfunc_11()) vfunc_13(); }
