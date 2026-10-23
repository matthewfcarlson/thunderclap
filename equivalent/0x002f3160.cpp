// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionCylinder::vfunc_8 @ 0x002f3160
#include "gen/physics.h"

namespace physics {

}
void physics::CollisionCylinder::vfunc_8() {
 for (int i=0;i<3;++i) {
 union { float f; unsigned int u; } a;
 a.f=(*(float (*)[3])&this->f_44)[i]; a.u &= 0x7fffffff;
 if((*(unsigned char *)&this->f_58)) {
 double square=(double)a.f*a.f;
 (*(float (*)[3])&this->f_28)[i]=(float)(((1.0-0.5*square)+square*square*0.125)*this->f_54+(double)a.f*this->f_50);
 } else (*(float (*)[3])&this->f_28)[i]=(float)((double)a.f*this->f_50+this->f_54);
 }
}
