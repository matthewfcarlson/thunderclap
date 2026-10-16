// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 25/26, incomplete)
// physics::HairclubPhysicsObject::vfunc_35 @ 0x00309680
#include "gen/physics.h"

struct Strand {
 char pad[0x28];
 float weight;
 char extra[4];
 unsigned char active;
 char tail[3];
 void FUN_002fcb80(float scale);
};
namespace physics {
struct HairclubPhysicsObject_nv_309680 {
    void FUN_00309410();
};
}
void physics::HairclubPhysicsObject::vfunc_35(float value) {
 double total = 0.0f;
 int n = this->f_1fc;
 for (int i=0;i<n;++i) {
  if ((*(Strand * *)&this->f_1f8)[i].active) total += (*(Strand * *)&this->f_1f8)[i].weight;
 }
 if (total > 0.0f) {
  value = (float)(value / total);
  if(n > 0) {
   for(int i=0;i<this->f_1fc;++i) {
    Strand* s = &(*(Strand * *)&this->f_1f8)[i];
    if(s->active) {
     s->weight = s->weight * value;
     s->FUN_002fcb80(value);
    }
   }
  }
 }
 ((HairclubPhysicsObject_nv_309680*)this)->FUN_00309410();
}
