#include "gen/core.h"

#include "decls/data/game/global.h"

namespace core {

} // namespace core
void core::ControllerInputPointXBox::vfunc_5(float input) {
    if (input < DAT_003f32e0)
        this->f_14 = 0.0f;
    else if (input > DAT_003f32dc)
        this->f_14 = 1.0f;
    else
        this->f_14 = input;
}
