// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_16 @ 0x00284df0
#include "gen/pure3d.h"

#include "decls/data/engine/pure3d.h"

namespace pure3d {

}
void pure3d::SimpleFrameController::vfunc_16(int value) {
    if (value != this->f_20) {
        this->f_20 = value;
        float duration = vfunc_20();
        this->f_28 = duration;
        if (this->f_20 == 0 && duration == DAT_0042c5b0)
            this->f_24 = 0;
        this->f_38 = this->f_20 != 3 && this->f_20 != 5;
    }
}
