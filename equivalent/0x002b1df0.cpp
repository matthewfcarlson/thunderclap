// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 6/6)
// pure3d::MultiController::vfunc_23 @ 0x002b1df0
#include "gen/pure3d.h"

namespace pure3d {

}
void pure3d::MultiController::vfunc_23() {
 this->f_18=0.0f; this->f_1c=30.0f; this->f_20=1.0f; this->f_24=0.0f; this->f_28=0.0f;
 double end=(this->f_30-1.0)*0.033333333333333333f;
 if(end<0.0) end=0.0;
 this->f_2c=(float)end;
 this->f_34=3.402823466e38f; this->f_38=0; this->f_3c=0;
 for(unsigned i=0;i<(*(unsigned int *)&this->f_44);++i) {
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_23();
 double length=(*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_10();
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_14((float)(length*this->f_28),(float)(length*this->f_2c));
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_16(0);
 }
}
