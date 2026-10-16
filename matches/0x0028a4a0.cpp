#include "gen/pure3d.h"

void pure3d::Vector1DOFChannel::vfunc_3(int index, void* __p1, void* __p2) { float * out = (float *)__p1; unsigned int * vec = (unsigned int *)__p2;

    *out = (float)(int)(*(short * *)&this->f_14)[index];
    vec[0] = this->f_1c;
    vec[1] = this->f_20;
    vec[2] = this->f_24;
    vec[this->f_18] = (*(unsigned int * *)&this->f_28)[index];
}
