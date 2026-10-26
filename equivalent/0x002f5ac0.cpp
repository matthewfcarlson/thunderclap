// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::PhysicsObject::vfunc_32 @ 0x002f5ac0
#include "compat/ptr.h"
#include "gen/physics.h"

struct Vec_2f5ac0 { float x,y,z; };
namespace physics {

}
void physics::PhysicsObject::vfunc_32(hulk_intptr __p0, hulk_intptr __p1) { Vec_2f5ac0 * f = (Vec_2f5ac0 *)__p0; Vec_2f5ac0 * p = (Vec_2f5ac0 *)__p1;

(*(Vec_2f5ac0 *)&this->f_130).x += f->x; (*(Vec_2f5ac0 *)&this->f_130).y += f->y; (*(Vec_2f5ac0 *)&this->f_130).z += f->z;
if(p) {
 double x=(double)p->x-(*(Vec_2f5ac0 *)&this->f_98).x, y=(double)p->y-(*(Vec_2f5ac0 *)&this->f_98).y, z=(double)p->z-(*(Vec_2f5ac0 *)&this->f_98).z;
 float ty=(float)(z*f->x-x*f->z);
 float tz=(float)(x*f->y-y*f->x);
 (*(Vec_2f5ac0 *)&this->f_13c).x=(float)(y*f->z-z*f->y+(*(Vec_2f5ac0 *)&this->f_13c).x);
 (*(Vec_2f5ac0 *)&this->f_13c).y += ty; (*(Vec_2f5ac0 *)&this->f_13c).z += tz; (*(unsigned char *)&this->f_1d0)=1;
}
if(vfunc_11()) vfunc_13();
}
