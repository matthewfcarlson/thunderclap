#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
extern const float defaultValue;

} // namespace pure3d
float pure3d::BlendFrameController::vfunc_10() {
    unsigned int n = this->f_28;
    if (n > 0)
        return *(float*)(*(hulk_intptr*)((char*)this + 0x28 + n * 0x2c) + 0x14);
    return defaultValue;
}
