#include "gen/pure3d.h"

namespace pure3d {
extern const float zero;

} // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_21() {
    if (this->f_28 > 0)
        return *(float*)((char*)this + this->f_28 * 0x2c + 0x18);
    return zero;
}
