// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// pure3d::Camera::vfunc_11 @ 0x002927e0
#include "gen/pure3d.h"

namespace pure3d {
struct Plane_2927e0 { float x,y,z,w; };

}
void pure3d::Camera::vfunc_11(int __p0, int __p1) { unsigned int which = (unsigned int)__p0; Plane_2927e0 * out = (Plane_2927e0 *)__p1;

switch(which) {
case 1: out->x=0; out->y=0; out->z=-1.0f; out->w=this->f_1c; break;
case 2: out->x=0; out->y=0; out->z=1.0f; out->w=-this->f_20; break;
case 4: { float z=this->f_40,y=this->f_3c; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 8: { float z=this->f_48,y=this->f_44; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 16: { float x=this->f_2c,z=this->f_30; out->x=x; out->z=z; out->y=0; out->w=0; break; }
case 32: { float z=this->f_38,x=this->f_34; out->z=z; out->x=x; out->y=0; out->w=0; break; }
}
}
