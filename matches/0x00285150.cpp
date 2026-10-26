#include "gen/pure3d.h"
#include "decls/data/game/global.h"
// data: gZero_285150 = DAT_003f32e0

namespace pure3d {

} // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_13() {
    if (this->f_28 > 0)
        return *(float*)((char*)this + this->f_28 * 0x2c);
    return DAT_003f32e0;
}
