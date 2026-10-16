#include "gen/physics.h"

unsigned char physics::PhysicsObject::vfunc_11() {
    volatile unsigned char* p = &this->f_1f4;
    unsigned char x = *p;
    x >>= 1;
    x &= 1;
    return x;
}
