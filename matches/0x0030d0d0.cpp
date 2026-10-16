#include "gen/physics.h"

void physics::PhysicsJoint3D::vfunc_1() {
    *(int*)((char*)this + 0x128) = 0;
    *(int*)((char*)this + 0x124) = 0;
    *(int*)((char*)this + 0x120) = 0;
    *(int*)((char*)this + 0x134) = 0;
    *(int*)((char*)this + 0x130) = 0;
    *(int*)((char*)this + 0x12c) = 0;
    *((char*)this + 0x151) = 1;
}
