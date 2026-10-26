// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::SimState::vfunc_8 @ 0x002ef530
#include "compat/ptr.h"
#include "gen/physics.h"

struct Vec3_2ef530 {
    float x, y, z;
};

void physics::SimState::vfunc_8(hulk_intptr __p0, hulk_intptr __p1, int unused) { const Vec3_2ef530 * p = (const Vec3_2ef530 *)__p0; Vec3_2ef530 * out = (Vec3_2ef530 *)__p1;

    double dx = p->x - (*(Vec3_2ef530 *)&this->f_40).x;
    double dy = p->y - (*(Vec3_2ef530 *)&this->f_40).y;
    double dz = p->z - (*(Vec3_2ef530 *)&this->f_40).z;
    // ny and nz are rounded frame copies in the original; nx stays in a register
    volatile float ny = dx * (*(Vec3_2ef530 *)&this->f_5c).z - dz * (*(Vec3_2ef530 *)&this->f_5c).x;
    volatile float nz = dy * (*(Vec3_2ef530 *)&this->f_5c).x - dx * (*(Vec3_2ef530 *)&this->f_5c).y;
    double nx = dz * (*(Vec3_2ef530 *)&this->f_5c).y - dy * (*(Vec3_2ef530 *)&this->f_5c).z;
    volatile float *o = &out->x;
    o[1] = ny;
    o[2] = nz;
    o[0] = nx;
    o[0] = o[0] + (*(Vec3_2ef530 *)&this->f_50).x;
    o[1] = ny + (*(Vec3_2ef530 *)&this->f_50).y;
    o[2] = nz + (*(Vec3_2ef530 *)&this->f_50).z;
}
