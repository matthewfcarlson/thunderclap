// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::pddiBaseContext::vfunc_104 @ 0x0031d380
#include "gen/pure3d.h"

namespace pure3d {

}
void pure3d::pddiBaseContext::vfunc_104() {
    if (this->f_b4 > 0.0f)
        this->f_b8 = (this->f_ac + this->f_a4) / this->f_b4;
    else
        this->f_b8 = 0.0f;
    if (this->f_cc > 0.0f)
        this->f_d0 = this->f_c4 / this->f_cc;
    else
        this->f_d0 = 0.0f;
}
