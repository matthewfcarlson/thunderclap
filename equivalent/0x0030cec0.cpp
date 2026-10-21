// STATUS: equivalent (tools/equiv.py level 3: 19872 inputs, branch coverage 0/0)
// physics::PhysicsJoint1D::vfunc_16 @ 0x0030cec0
#include "gen/physics.h"
#include "compat/ptr.h"

namespace physics { struct PhysicsJoint_30cec0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); };  }
void physics::PhysicsJoint1D::vfunc_16(int __p0, int __p1) { const float * input = (const float *)__p0; float * output = (float *)__p1;
 hulk_freg projection = -(this->f_104*input[2]+this->f_100*input[1]+this->f_fc*input[0]); output[0]=projection*this->f_fc+input[0]; output[1]=projection*this->f_100+input[1]; output[2]=projection*this->f_104+input[2]; }
