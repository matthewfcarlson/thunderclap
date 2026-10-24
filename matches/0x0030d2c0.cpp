#include "gen/physics.h"

extern "C" double __cdecl sqrt(double);

hulk_freg physics::PhysicsJoint3D::vfunc_6() {
    return sqrt((double)((hulk_freg)(*(float *)&this->f_138) * (*(float *)&this->f_138) + (hulk_freg)(*(float *)&this->f_13c) * (*(float *)&this->f_13c) + (hulk_freg)(*(float *)&this->f_140) * (*(float *)&this->f_140)));
}
