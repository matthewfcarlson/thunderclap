#include "gen/pure3d.h"

extern "C" void* memset(void*, int, unsigned int);

void pure3d::ShadowTraversal::vfunc_5() {
    memset((*(void * *)&this->f_3c), 0, this->f_38 * 20);
    this->f_38 = 0;
}
