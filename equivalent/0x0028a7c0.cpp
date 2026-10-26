// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::Vector3DOFChannel::vfunc_4 @ 0x0028a7c0
#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
struct Vector_28a7c0 { float x,y,z; };
struct Vector3DOFChannel_nv_28a7c0 {
    bool FUN_00289f80(float time, int* first, int* second);
};

}
void pure3d::Vector3DOFChannel::vfunc_4(float time, hulk_intptr __p1) { Vector_28a7c0 * out = (Vector_28a7c0 *)__p1;

 int first, second;
 bool found = ((Vector3DOFChannel_nv_28a7c0*)this)->FUN_00289f80(time, &first, &second);
 if (found && this->f_04) {
  double delta = (double)time - (*(short * *)&this->f_14)[first];
  if (delta != 0.0) {
   double t = delta / (int)((*(short * *)&this->f_14)[second] - (*(short * *)&this->f_14)[first]);
   out->x = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].x - (*(Vector_28a7c0 * *)&this->f_18)[first].x) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].x);
   out->y = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].y - (*(Vector_28a7c0 * *)&this->f_18)[first].y) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].y);
   out->z = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].z - (*(Vector_28a7c0 * *)&this->f_18)[first].z) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].z);
   return;
  }
 }
 *out = (*(Vector_28a7c0 * *)&this->f_18)[first];
}
