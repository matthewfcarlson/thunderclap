#include "compat/ptr.h"
#include "gen/pure3d.h"

extern const float zero_285130;

hulk_freg pure3d::BlendFrameController::vfunc_11() {
    if (this->f_28 > 0)
        return *(float*)(*(hulk_intptr*)((char*)this + this->f_28 * 0x2c + 0x28) + 0x10);
    return zero_285130;
}
