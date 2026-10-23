// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::QuaternionChannel::vfunc_5 @ 0x0028aa20
#include "gen/pure3d.h"

namespace pure3d {
struct Quaternion_28aa20 {
 float x,y,z,w;
 void FUN_0022b750(const Quaternion_28aa20*, const Quaternion_28aa20*, float);
};
struct QuaternionChannel_nv_28aa20 {
    bool FUN_00289f80(float, int*, int*);
};

}
void pure3d::QuaternionChannel::vfunc_5(float time, int __p1) { Quaternion_28aa20 * out = (Quaternion_28aa20 *)__p1;

 int first, second;
 bool found = ((QuaternionChannel_nv_28aa20*)this)->FUN_00289f80(time, &first, &second);
 if (found && this->f_04) {
   double delta = (double)time - (int)(*(short * *)&this->f_14)[first];
   if (delta != 0.0f) {
     int span = (int)(*(short * *)&this->f_14)[second] - (int)(*(short * *)&this->f_14)[first];
     out->FUN_0022b750(&(*(Quaternion_28aa20 * *)&this->f_18)[first], &(*(Quaternion_28aa20 * *)&this->f_18)[second], (float)(delta / span));
     return;
   }
 }
 *out = (*(Quaternion_28aa20 * *)&this->f_18)[first];
}
