#include "gen/pure3d.h"

void pure3d::pddiBaseContext::vfunc_47(int i, void* __p1) { unsigned int * out = (unsigned int *)__p1;

    if (i < 8) {
        unsigned int* p = (unsigned int*)((char*)(*(unsigned int * *)&this->f_50) + i * 0x7c + 0x24);
        out[0] = p[0];
        out[1] = p[1];
        out[2] = p[2];
    } else {
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;
    }
}
