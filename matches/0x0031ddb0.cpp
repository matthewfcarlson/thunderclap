#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_50(int i, float a, float b, float c) {
    if (i < 8) {
        *(float*)((*(char * *)&this->f_50) + i * 0x7c + 0x5c) = a;
        *(float*)((*(char * *)&this->f_50) + i * 0x7c + 0x60) = b;
        *(float*)((*(char * *)&this->f_50) + i * 0x7c + 0x64) = c;
        vfunc_110(i, 0);
    }
}
