#include "gen/pure3d.h"

extern const float gZero_285150;
namespace pure3d {

} // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_13() {
    if (this->f_28 > 0)
        return *(float*)((char*)this + this->f_28 * 0x2c);
    return gZero_285150;
}
