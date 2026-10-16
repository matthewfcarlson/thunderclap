#include "gen/pure3d.h"

int pure3d::SimpleFrameController::vfunc_19() {
    if (this->f_20 == 0 && (*(int *)&this->f_3c) != 0)
        return (int)(*(unsigned char*)((*(int *)&this->f_3c) + 0x18) == 0);
    return (int)(this->f_24);
}
