// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// physics::PhysicsJoint1D::vfunc_25 @ 0x0030b190
#include "gen/physics.h"

#include "decls/data/engine/physics.h"

namespace physics {
}
void physics::PhysicsJoint1D::vfunc_25() {
 union { float f; unsigned int u; } absolute;
 absolute.f = this->f_10c;
 absolute.u &= 0x7fffffff;
 if (absolute.f > DAT_004d3198) {
 float sign = 0.0f;
 if (this->f_10c < 0.0f) sign = -1.0f;
 else if (this->f_10c > 0.0f) sign = 1.0f;
 this->f_10c = sign * DAT_004d3198;
 }
 if (DAT_004d319c) {
 if (this->f_11c > (*(float *)&this->f_14)) {
 double delta = (double)this->f_11c - (*(float *)&this->f_14);
 this->f_11c = (*(float *)&this->f_14);
 this->f_114 = (float)((double)this->f_114 - delta * DAT_004d31a0);
 if (this->f_10c > 0.0f) this->f_10c = DAT_004d31d8 * this->f_10c;
 } else if (this->f_11c < (*(float *)&this->f_10)) {
 double delta = (double)this->f_11c - (*(float *)&this->f_10);
 this->f_11c = (*(float *)&this->f_10);
 this->f_114 = (float)((double)this->f_114 - delta * DAT_004d31a0);
 if (this->f_10c < 0.0f) this->f_10c = DAT_004d31d8 * this->f_10c;
 }
 }
}
