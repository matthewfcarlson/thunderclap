// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 6/6)
// pure3d::Vector1DOFChannel::vfunc_4 @ 0x0028a4e0
#include "gen/pure3d.h"

namespace pure3d {
struct Vector_28a4e0 { float x,y,z; };
struct Vector1DOFChannel_nv_28a4e0 {
    bool FUN_00289f80(float time, int* first, int* second);
};

}
void pure3d::Vector1DOFChannel::vfunc_4(float time, int __p1) { Vector_28a4e0 * out = (Vector_28a4e0 *)__p1;

 out->x=(*(Vector_28a4e0 *)&this->f_1c).x; out->y=(*(Vector_28a4e0 *)&this->f_1c).y; out->z=(*(Vector_28a4e0 *)&this->f_1c).z;
 int first, second;
 if (((Vector1DOFChannel_nv_28a4e0*)this)->FUN_00289f80(time,&first,&second) && this->f_04) {
  double delta=(double)time-(int)(*(short * *)&this->f_14)[first];
  if(delta==0.0f) { (&out->x)[this->f_18]=(*(float * *)&this->f_28)[first]; return; }
  (&out->x)[this->f_18]=(float)(((double)(*(float * *)&this->f_28)[second]-(*(float * *)&this->f_28)[first])/((int)(*(short * *)&this->f_14)[second]-(int)(*(short * *)&this->f_14)[first])*delta+(*(float * *)&this->f_28)[first]);
 } else { (&out->x)[this->f_18]=(*(float * *)&this->f_28)[first]; }
}
