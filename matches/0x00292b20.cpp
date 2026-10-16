#include "gen/pure3d.h"

void pure3d::Camera::vfunc_20(void* __p0) { unsigned long * out = (unsigned long *)__p0;

    if (!this->f_cc)
        vfunc_26();
    out[0] = this->f_bc;
    out[1] = this->f_c0;
    out[2] = this->f_c4;
}
