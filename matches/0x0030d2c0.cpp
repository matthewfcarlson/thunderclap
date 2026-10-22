#include "gen/physics.h"

extern "C" double __cdecl sqrt(double);

float physics::PhysicsJoint3D::vfunc_6() {
    return (float)sqrt((double)((*(float *)&this->f_138) * (*(float *)&this->f_138) + (*(float *)&this->f_13c) * (*(float *)&this->f_13c) + (*(float *)&this->f_140) * (*(float *)&this->f_140)));
}
