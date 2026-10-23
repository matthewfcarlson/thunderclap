// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 17/18, incomplete)
// pure3d::MultiController::vfunc_14 @ 0x002b1a80
#include "gen/pure3d.h"

namespace pure3d {
struct FrameController_2b1a80 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(float,float); virtual void vfunc_15(); virtual void vfunc_16(int); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
};

}
void pure3d::MultiController::vfunc_14(float first, float last) {
 double scale = 1.0 / this->f_1c;
 float start = (float)(first * scale);
 double finish = last * scale;
 if (start == this->f_28 && finish == this->f_2c) return;
 this->f_2c = (float)finish;
 this->f_28 = start;
 if (!(this->f_24 >= first && this->f_24 <= last)) {
 this->f_24 = this->f_24 > last ? last : first;
 }
 for (unsigned i=0;i<(*(unsigned int *)&this->f_44);++i) {
 float length=(*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_10();
 (*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_16(this->f_3c);
 (*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_14(length*this->f_28,length*this->f_2c);
 }
 this->f_34=vfunc_20();
 (*(unsigned char *)&this->f_40) = this->f_3c != 3 && this->f_3c != 5;
}
