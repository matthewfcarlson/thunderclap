#include "compat/ptr.h"
#include "gen/pure3d.h"

unsigned int pure3d::Image8::vfunc_20(int p2, int p3) {
    return *((unsigned char*)(this->f_10 * p3 + (*(hulk_intptr *)&this->f_24) + p2));
}
