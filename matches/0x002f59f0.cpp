#include "gen/physics.h"

typedef unsigned char u8;
typedef unsigned int u32_2f59f0;
extern u8 global_4d2b78;

void physics::PhysicsObject::vfunc_13() {
    *((u8*)this + 0x1f4) &= 0xfd;
    *((u32_2f59f0*)this + 0x75) = 0;
    *((u32_2f59f0*)this + 0x77) = 0;
    *((u8*)this + 0x1f0) = global_4d2b78;
}
