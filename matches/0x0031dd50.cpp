#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_48(int index, float value) {
    if (index < 8) {
        int i = index;
        char* p = (char*)(*(hulk_intptr *)&this->f_50);
        *(float*)(p + i * 0x7c + 0x58) = value;
        vfunc_110(index, 0);
    }
}
