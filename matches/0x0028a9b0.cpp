#include "gen/pure3d.h"

void pure3d::QuaternionChannel::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; unsigned int * out = (unsigned int *)__p2;

    *time = (float)(*(short * *)&this->f_14)[index];
    unsigned int* p = (unsigned int*)((char*)(*(unsigned int * *)&this->f_18) + index * 16);
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
    out[3] = p[3];
}
