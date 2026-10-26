#include "gen/physics.h"
#include "decls/data/engine/physics.h"
// data: global_4d2b78 = DAT_004d2b78

typedef unsigned char u8;
typedef unsigned int u32_2f59f0;

void physics::PhysicsObject::vfunc_13() {
    *((u8*)this + 0x1f4) &= 0xfd;
    *((u32_2f59f0*)this + 0x75) = 0;
    *((u32_2f59f0*)this + 0x77) = 0;
    *((u8*)this + 0x1f0) = (*(u8*)&DAT_004d2b78);
}
