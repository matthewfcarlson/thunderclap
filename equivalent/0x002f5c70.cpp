// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::PhysicsObject::vfunc_18 @ 0x002f5c70
#include "gen/physics.h"

struct Vec_2f5c70 { float x,y,z; };
namespace physics {
}
bool physics::PhysicsObject::vfunc_18(int __p0, int __p1, int __p2, int __p3, int __p4, int __p5) { const Vec_2f5c70 * point = (const Vec_2f5c70 *)__p0; const Vec_2f5c70 * force = (const Vec_2f5c70 *)__p1; unsigned int a = (unsigned int)__p2; unsigned int b = (unsigned int)__p3; unsigned int c = (unsigned int)__p4; unsigned int d = (unsigned int)__p5;

 float scale=this->f_44;
 this->f_148=0;
 (*(Vec_2f5c70 *)&this->f_14c).x=scale*force->x;
 (*(Vec_2f5c70 *)&this->f_14c).y=scale*force->y;
 (*(Vec_2f5c70 *)&this->f_14c).z=scale*force->z;
 (*(Vec_2f5c70 *)&this->f_158).x=point->x-(*(Vec_2f5c70 *)&this->f_98).x;
 (*(Vec_2f5c70 *)&this->f_158).y=point->y-(*(Vec_2f5c70 *)&this->f_98).y;
 (*(Vec_2f5c70 *)&this->f_158).z=point->z-(*(Vec_2f5c70 *)&this->f_98).z;
 double az=*(volatile float*)&(*(Vec_2f5c70 *)&this->f_158).z; // the original reads the rounded member back
 double y=(double)force->x*az-(double)(*(Vec_2f5c70 *)&this->f_158).x*force->z;
 double z=(double)force->y*(*(Vec_2f5c70 *)&this->f_158).x-(double)force->x*(*(Vec_2f5c70 *)&this->f_158).y;
 double x=(double)(*(Vec_2f5c70 *)&this->f_158).y*force->z-(double)force->y*az;
 (*(Vec_2f5c70 *)&this->f_158).x=(float)x;
 (*(Vec_2f5c70 *)&this->f_158).y=(float)y;
 (*(Vec_2f5c70 *)&this->f_158).z=(float)z;
 return true;
}
