#include "gen/pure3d.h"

void pure3d::Camera::vfunc_25(void* __p0, void* __p1, void* __p2) { float * x = (float *)__p0; float * y = (float *)__p1; float * z = (float *)__p2;

    float q = 1.0f / this->f_1c;
    float r = 1.0f / this->f_20;
    y[0] = *x / (q * this->f_24 * 0.5f);
    y[1] = x[1] / (q * this->f_28 * 0.5f);
    y[2] = this->f_1c;
    z[0] = *x / (r * this->f_24 * 0.5f);
    z[1] = x[1] / (r * this->f_28 * 0.5f);
    z[2] = this->f_20;
}
