// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_18 @ 0x00284e60
#include "gen/pure3d.h"

#include "decls/data/engine/pure3d.h"

namespace pure3d {
}
void pure3d::SimpleFrameController::vfunc_18(int value) {
    if (this->f_24 != value) {
        this->f_24 = value;
        float length = vfunc_20();
        this->f_28 = length;
        int currentMode = this->f_20;
        if (currentMode == 0 && length == (*(float*)&DAT_0042c5b0))
            this->f_24 = 0;
        this->f_38 = currentMode != 3 && currentMode != 5;
    }
}
