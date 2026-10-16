#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
float pure3d::pddiBaseContext::vfunc_49(int index) {
    if (index < 8)
        return *(float*)((char*)(*(struct Data * *)&this->f_50) + index * 0x7c + 0x58);
    return 0.0f;
}
