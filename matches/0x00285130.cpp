#include "decls/data/game/global.h"
// data: zero_285130 = DAT_003f32e0

#include "compat/ptr.h"
#include "gen/pure3d.h"


hulk_freg pure3d::BlendFrameController::vfunc_11() {
    if (this->f_28 > 0)
        return *(float*)(*(hulk_intptr*)((char*)this + this->f_28 * 0x2c + 0x28) + 0x10);
    return DAT_003f32e0;
}
