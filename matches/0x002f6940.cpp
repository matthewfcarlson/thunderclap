#include "gen/physics.h"

struct Data_2f6940 {
    char p[0x68];
    float x;
};

void physics::PhysicsObject::vfunc_30() {
    float f = ((Data_2f6940*)(*(float * *)&this->f_10))->x;
    this->f_3c = f * this->f_38 * f * f;
    this->f_1b0 = f * this->f_1b0;
}
