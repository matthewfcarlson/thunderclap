// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/14)
// pure3d::SimpleFrameController::vfunc_14 @ 0x00285930
#include "gen/pure3d.h"

namespace pure3d {

}
void pure3d::SimpleFrameController::vfunc_14(float newLo, float newHi) {
    if ((*(float *)&this->f_2c) == newLo && (*(float *)&this->f_30) == newHi)
        return;
    (*(float *)&this->f_2c) = newLo;
    (*(float *)&this->f_30) = newHi;
    if (this->f_34 >= (*(float *)&this->f_2c) && this->f_34 <= (*(float *)&this->f_30)) {
    } else if (this->f_34 > (*(float *)&this->f_30)) {
        this->f_34 = (*(float *)&this->f_30);
    } else {
        this->f_34 = (*(float *)&this->f_2c);
    }
    this->f_28 = vfunc_20();
    this->f_38 = !(this->f_20 == 3 || this->f_20 == 5);
}
